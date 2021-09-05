
vector<int> Solution::findPerm(const string A, int B) {
    vector<int>v(B);
    int l = 1;
    int r = B;
    int i;
    for(i = 0; i < A.size(); i++){
        if(A[i] == 'D'){
            v[i] = r--;
        }
        else{
            v[i] = l++;
        }
    }
    while(l <= r){
        v[i++] = l++;
    }
    return v;

}
