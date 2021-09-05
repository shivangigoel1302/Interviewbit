int Solution::solve(vector<vector<int> > &A) {
    unordered_map<int,int>ma;
    if(A.empty()){
        return 0;
    }
    int ans = 0;
    int m = A.size();
    int n = A[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++){
            A[i][j] += A[i][j-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            ma.clear();
            int sum = 0;
            for(int r = 0; r < m; r++){
                sum += A[r][j] - (i > 0 ? A[r][i-1] : 0);
                  if(sum == 0){
                    ans++;
                }
                if(ma.find(sum) != ma.end()){
                    ans += ma[sum];
                }

                ma[sum]++;
            }
        }
    }
    return ans;
}
