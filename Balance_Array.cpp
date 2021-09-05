int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int>odd(n,0);
    vector<int>even(n,0);
    for(int i = 0; i < n; i++){
        if(i%2){
            odd[i] += A[i]+ (i-2 >= 0 ? odd[i-2]:0);
        }
        else{
            even[i] += A[i]+ (i-2 >=0 ? even[i-2]:0);
        }
    }
    int cnt = 0;
    int fodd,feven;
    if(n%2){
        fodd = odd[n-2];
        feven = even[n-1];
    }
    else{
        fodd = odd[n-1];
        feven = even[n-2];
    }
    for(int i = 0; i < n;i++){
        if(i == 0){
            if(feven - A[i] == fodd){
                cnt++;
            }
        }
        else if(i == n-1){
            if(n%2){
                if(feven-A[i] == fodd){
                    cnt++;
                }
            }
            else{
                if(fodd - A[i] == feven){
                    cnt++;
                }
            }
        }
        else{
            if(i%2){
                int o = fodd - odd[i] + even[i-1];
                int e = feven - even[i-1];
                if(i-2 >= 0){
                    e += odd[i-2];
                }
                if(o == e){
                    cnt++;
                }
            }
            else{
                int e = feven - even[i] + odd[i-1];
                int o = fodd - odd[i-1];
                if(i-2>=0 ){
                    o += even[i-2];
                }
                if(e == o){
                    cnt++;
                }
            }
        }
    }

    return cnt;
}
