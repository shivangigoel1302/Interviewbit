int Solution::solve(vector<int> &A, int B) {
    unordered_set<int>s;
    for(int i = 0; i < A.size(); i++){
        int a = A[i] + B;
        int b = A[i] - B;
        if(s.find(a) != s.end() || s.find(b) != s.end()){
            return 1;
        }
        s.insert(A[i]);
    }
    return 0;
}
