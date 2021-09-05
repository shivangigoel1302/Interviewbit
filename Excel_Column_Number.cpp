int Solution::titleToNumber(string A) {
    int col = 0;
    int size = A.size();
    for(int i = 0; i < A.size(); i++,size--){
        col += pow(26,size-1)*(A[i]-64);
    }
    return col;
}
