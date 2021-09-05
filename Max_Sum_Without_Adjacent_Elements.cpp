int Solution::adjacent(vector<vector<int> > &A) {
    int inc=max(A[0][0],A[1][0]);
    int exc = 0;
    int newexcl;
    for(int i = 1; i < A[0].size(); i++){
         newexcl = max(inc,exc);
        inc = exc + max(A[0][i],A[1][i]);
        exc = newexcl;
    }
    return max(inc,exc);
}
