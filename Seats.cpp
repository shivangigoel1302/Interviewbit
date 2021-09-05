int Solution::seats(string A) {
    int l = 0;
    int n = A.size();
    while(l < n && A[l] != 'x'){
       l++;
    }
    int r = A.size()-1;
    while(r >= 0 && A[r] != 'x'){
        r--;
    }
    long long int mod = 10000003;
    long long int ans = 0;
    long long int lcnt = 1;
    long long int rcnt = 1;
    while(l < r){
        int j;
        for(j = l+1; j <=r && A[j] != 'x' ; j++){
        }
        int hop = j-l-1;
        ans += hop*lcnt;
        l = j;
        lcnt++;
        for(j = r-1; j >= l && A[j] != 'x'; j--){
        }
        hop = r-j-1;
        ans += hop*rcnt;
        rcnt++;
        r = j;
    }
    return ans%mod;
}
