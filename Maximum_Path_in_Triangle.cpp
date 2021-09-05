int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i = m-2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            A[i][j] += max(A[i+1][j+1],A[i+1][j]);
        }
    }
    return A[0][0];
}
