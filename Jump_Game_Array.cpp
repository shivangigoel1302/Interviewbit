int Solution::canJump(vector<int> &A) {
    int jump = A[0];
    for(int i = 1; i < A.size(); i++){
        if(i > jump){
            return 0;
        }
        jump = max(jump,i+A[i]);
    }
    return 1;
}
