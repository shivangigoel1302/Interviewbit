int Solution::repeatedNumber(const vector<int> &B) {
   vector<int>A(B);
    int a = A[0];
    for(int i = 0; i < A.size(); i++){
        if(A[abs(A[i]) - 1] >= 0){
            A[abs(A[i]) -1] *= -1;
        }
        else{
            return abs(A[i]);
        }
    }
    return -1;
}
