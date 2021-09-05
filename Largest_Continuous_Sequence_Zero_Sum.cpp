vector<int> Solution::lszero(vector<int> &A) {
    int l =-1,r=-1;
    unordered_map<int,int>m;
    int sum = 0;
    int maxlen = 0;
    m[0] = -1;
    for(int i = 0; i < A.size(); i++){
        sum += A[i];

        if(m.find(sum) != m.end()){
            int tr = m[sum];
            if(i-tr > maxlen){
                l = tr+1;
                r = i;
                maxlen = r-l+1;
            }
        }
        else{
           m[sum] = i;
        }
    }
    vector<int>ans;
    if(l == -1 && r == -1){
        return ans;
    }
    for(int j = l; j<= r; j++){
        ans.push_back(A[j]);
    }
    return ans;
}
