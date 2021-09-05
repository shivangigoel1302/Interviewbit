int Solution::solve(int A) {
    if(A%2 == 1){
        return 0;
    }
    vector<int>a(A+1,0);
    int mod = 1e9+7;
    vector<long long int>c(A+1,0);
    a[0] = 1,c[0] = 0,a[1] = 0,c[1] = 1;
    for(int i = 2; i <= A; i++){
        a[i] = (a[i-2] + 2*c[i-1])%mod;
        c[i] = (a[i-1] + c[i-2])%mod;
    }
    return a[A];
}
