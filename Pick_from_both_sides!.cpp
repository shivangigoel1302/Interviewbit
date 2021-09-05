int Solution::solve(vector<int> &A, int B) {
    for(int i = 1; i < A.size(); i++){
        A[i] += A[i-1];
    }
    int n = A.size();
    int ans = INT_MIN;
    for(int i = 0; i <= B; i++){
        int left=0;
        if(i){
            left = A[i-1];
        }
        int right = A[n-1];
        if(n-B+i){
            right -= A[n-B+i-1];
        }
        ans = max(ans,left+right);
    }
    return ans;
}
