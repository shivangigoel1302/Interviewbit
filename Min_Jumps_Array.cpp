int Solution::jump(vector<int> &A) {
    int jump = A[0];
    int maxPossible = A[0];
    int cnt = 1;
    int i;
    for(i = 1; i < A.size()-1; i++){
        if(i > maxPossible){
            return -1;
        }
        if(i + A[i] > maxPossible){
            maxPossible = i + A[i];
        }
        jump--;
        if(jump == 0){
            cnt++;
            jump = maxPossible - i;
        }
    }
    if(i == A.size()-1){
        return cnt;
    }
    return 0;
}
