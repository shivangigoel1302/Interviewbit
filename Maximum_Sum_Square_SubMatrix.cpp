void precompute(vector<vector<int>>&A){
    int n = A.size();
    for(int i = 1; i < n; i++){
        A[0][i] += A[0][i-1];
    }
    for(int j = 1; j < n; j++){
        A[j][0] += A[j-1][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }
    return;
}
int Solution::solve(vector<vector<int> > &A, int B) {
    precompute(A);
    int n = A.size();
    int ans = INT_MIN;
    for(int i = B-1; i < n; i++){
        for(int j = B-1; j < n; j++){
            int temp = A[i][j];
            if(i-B >= 0){
                temp -= A[i-B][j];
            }
            if(j-B >= 0){
                temp -= A[i][j-B];
            }
            if(i - B >= 0 && j-B >= 0){
                temp += A[i-B][j-B];
            }
            ans = max(ans,temp);
        }
    }
    return ans;
}
