vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size(),m = B.size();
    if(C == 1){
        return {A[n-1] + B[m-1]};
    }
    vector<int>ans;
    ans.push_back({A[n-1]+B[m-1]});

}
