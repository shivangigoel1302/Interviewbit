bool possible(int mid,vector<int>a,int b){
    long long int ans = 0;
    for(int i =0; i < a.size(); i++){
        if(a[i] > mid){
            ans += a[i] - mid;
        }
    }
    return ans >= b;
}
int Solution::solve(vector<int> &A, int B) {
    long long int l = 0;
    long long int r = 0;
    for(int i = 0; i < A.size(); i++){
        r = max(r,(long long)A[i]);
    }
   long long int ans = 0;
    while(l <= r){
       long long int mid = (l+r)/2;
        if(possible(mid,A,B)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
