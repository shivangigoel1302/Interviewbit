int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),[](vector<int>&v1,vector<int>&v2){
        if(v1[1] == v2[1]){
            return v1[0] <= v2[0];
        }
        return v1[1] < v2[1];
    });
    int ans = 1;
    int right = A[0][1];
    for(int i = 1; i < A.size(); i++){
        if(A[i][0] > right){
            right = A[i][1];
            ans++;
        }
    }
    return ans;
}
