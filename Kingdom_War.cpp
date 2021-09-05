int Solution::solve(vector<vector<int> > &A) {
    int m = A.size(),n = A[0].size();
    int ans = INT_MIN;
    for(int i = m-1; i >=0 ; i--){
        for(int j = n-1; j >=0; j--){
            if(i+1 < m){
                A[i][j] += A[i+1][j];
            }
            if(j +1 < n){
                A[i][j] += A[i][j+1];
            }
            if(i+1 < m&& j +1 < n){
                A[i][j] -= A[i+1][j+1];
            }
            ans = max(ans,A[i][j]);
        }

    }
    return ans;
}
