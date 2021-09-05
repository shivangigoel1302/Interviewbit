vector<int> Solution::solve(vector<int> &A) {
    vector<int>v;
    int maximum = INT_MIN;
    for(int i = A.size()-1; i >= 0; i--){
        if(maximum < A[i]){
            v.push_back(A[i]);
            maximum = A[i];
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
