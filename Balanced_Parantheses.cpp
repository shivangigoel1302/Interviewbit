int Solution::solve(string A) {
    int open = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '('){
            open++;
        }
        else{
            if(open <= 0){
                return 0;
            }
            open--;
        }
    }
    return open == 0;
}
