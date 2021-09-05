vector<int> Solution::plusOne(vector<int> &A) {
    vector<int>res;
    int carry = 1;
    for(int i = A.size()-1;i >= 0; i--){
        int a = A[i] + carry;
        carry = a/10;
        a%=10;
        res.push_back(a);
    }
    while(carry){
        res.push_back(carry%10);
        carry/=10;
    }
    vector<int>ans;
    int i = res.size()-1;
    while(i >= 0 && res[i] == 0){
        i--;
    }
    if(i == -1){
        return {0};
    }
    for(int j = i; j >= 0; j--){
        ans.push_back(res[j]);
    }
    return ans;
}
