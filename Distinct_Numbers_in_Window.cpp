vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int>ans(n-B+1);
    unordered_map<int,int>m;
    for(int i=0; i < B; i++){
        m[A[i]]++;
    }
    ans[0] = m.size();
    for(int i = B; i < n; i++){
        m[A[i]]++;
        m[A[i-B]]--;
        if(m[A[i-B]] == 0){
            m.erase(A[i-B]);
        }
        ans[i-B+1] = m.size();
    }
    return ans;
}
