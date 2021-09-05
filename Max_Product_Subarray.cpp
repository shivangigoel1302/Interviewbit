int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    vector<int>maximum(n,INT_MIN);
    vector<int>minimum(n,INT_MAX);
    maximum[0] = A[0];
    minimum[0] = A[0];
    int ans = A[0];
    for(int i = 1; i < n; i++){
        maximum[i] = max(A[i],max(A[i]*maximum[i-1],A[i]*minimum[i-1]));
        minimum[i] = min(A[i],min(A[i]*maximum[i-1],A[i]*minimum[i-1]));
        ans = max(ans,maximum[i]);
    }
    return ans;
}
