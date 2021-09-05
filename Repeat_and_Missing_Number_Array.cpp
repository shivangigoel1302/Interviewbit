vector<int> Solution::repeatedNumber(const vector<int> &B) {
    vector<int>A(B);
    int a;
    for(int i = 0; i < A.size(); i++){
        if(A[abs(A[i]) -1 ] > 0){
            A[abs(A[i]) - 1] *= -1;
        }
        else{
            a = abs(A[i]);
        }
    }
    int b;
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0){
            b = i+1;
        }
    }
    return {a,b};
}
