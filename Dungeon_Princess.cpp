int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    A[m-1][n-1] = min(A[m-1][n-1],0);
    for(int i = m-2; i >=0 ; i--){
        A[i][n-1] += A[i+1][n-1];
        if(A[i][n-1] > 0){
            A[i][n-1] = 0;
        }
    }
    for(int i = n-2; i >=0; i--){
        A[m-1][i] += A[m-1][i+1];
        if(A[m-1][i] > 0){
            A[m-1][i] = 0;
        }
    }
    for(int i = m-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            A[i][j] += max(A[i+1][j],A[i][j+1]);
            if(A[i][j] > 0){
                A[i][j] = 0;
            }
        }
    }
    return abs(A[0][0])+1;

}
