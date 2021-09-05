int Solution::solve(vector<vector<int> > &A) {
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < 3; j++){
            int minimum = INT_MAX;
            for(int k = 0; k < 3; k++){
                if(k == j){
                    continue;
                }
                minimum = min(minimum,A[i-1][k]);
            }
            A[i][j] += minimum;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < 3; i++){
        ans = min(ans,A[A.size()-1][i]);
    }
    return ans;
}
