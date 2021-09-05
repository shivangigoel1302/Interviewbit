vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>>v;
    for(int i = 0; i < A.size(); i++){
        v.push_back({A[i],B[i]});
    }
    sort(v.rbegin(),v.rend());
    vector<int>ans;
    for(int i = 0; i < v.size(); i++){
        ans.insert(ans.begin() + v[i].second,v[i].first);
    }
    return ans;
}
