int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    int state = 0;
    for(int i = 0; i < A.size(); i++){
        if(state == 0){
            if(A[i] == 0){
                ans++;
                state = 1;
            }
        }
        else if(state == 1){
            if(A[i] == 1){
                ans++;
                state = 0;
            }
        }
    }
    return ans;
}
