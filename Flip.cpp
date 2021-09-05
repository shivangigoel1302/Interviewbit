vector<int> Solution::flip(string s) {
    int cnt = 0;
    vector<int>A(s.size());
    for(int i = 0; i < A.size(); i++){
        if(s[i] == '0'){
            A[i] = 1;
        }
        else{
            cnt++;
            A[i] = -1;
        }
    }
    if(cnt == A.size()){
        return {};
    }
    int L,R;
    int sum = 0;
    int maximum = INT_MIN;
    int l=0,r=0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] + sum < A[i]){
            r = i;
            l = i;
            sum = A[i];
        }
        else{
            sum += A[i];
        }
        if(sum > maximum){
            L = l;
            R = r;
            maximum = sum;
        }
        r++;
    }
    vector<int>ans;
    ans.push_back(L+1);
    ans.push_back(R+1);
    return ans;

}
