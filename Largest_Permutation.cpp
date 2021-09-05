vector<int> Solution::solve(vector<int> &A, int B) {
    int i = 0;
    int n = A.size();
    unordered_map<int,int>m;
    for(int j = 0; j < A.size(); j++){
        m[A[j]] = j;
    }

    while(B && i < A.size()){
        int x = A[i];
        if(x == n-i){
            i++;
            continue;
        }
        int j = m[n-i];
        A[j] = x;
        A[i] = n-i;
        m[A[j]] = j;
        m[A[i]] = i;
        i++;
        B--;
    }
    return A;
}
