vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<int>ans;
    int i = 0;
    int j = 1;
    while(i < A.size() && j < A.size()){
        ans.push_back(A[j]);
        ans.push_back(A[i]);
        j+=2;
        i+=2;
    }
    while(i < A.size()){
        ans.push_back(A[i]);
        i++;
    }
    while(j < A.size()){
        ans.push_back(A[j]);
        j++;
    }
    return ans;
}
