vector<int> Solution::solve(vector<int> &A) {
    int maximum = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        maximum = max(maximum,abs(A[i]));
    }
    vector<int>v(maximum+1,0);
    for(int i = 0;i < A.size(); i++){
        v[abs(A[i])]++;
    }
    vector<int>ans;
    for(int i = 0; i < v.size(); i++){
        while(v[i]--){
            ans.push_back(i*i);
        }
    }
    return ans;
}
