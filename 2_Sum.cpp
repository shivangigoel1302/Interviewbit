vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int l=A.size(),r=A.size();
    unordered_map<int,int>m;

    for(int i = 0; i < A.size(); i++){
        if(m.find(B-A[i]) != m.end()){
            if(i < r){
                l = m[B-A[i]];
                r = i;
            }
            else if(i == r){
                if(m[B-A[i]] < l){
                    l = m[B-A[i]];
                    r = i;
                }
            }
        }
        if(m.find(A[i]) == m.end()){
            m[A[i]] = i;
        }
    }
    if(l == A.size() && r == A.size()){
        return {};
    }
    return {l+1,r+1};
}
