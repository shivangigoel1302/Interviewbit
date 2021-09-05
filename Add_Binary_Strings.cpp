string Solution::addBinary(string A, string B) {
    string ans = "";
    int i = A.size()-1;
    int j = B.size()-1;
    int carry = 0;
    while(i >=0 || j>=0){
        int a = i >=0 ? A[i--] -'0' : 0;
        int b = j >=0 ? B[j--] - '0' : 0;
        int c = a+b+carry;
        ans = to_string(c%2) + ans;
        carry = c/2;
    }
    if(carry){
        ans = to_string(carry) + ans;
    }
    return ans;
}
