int Solution::power(string A) {
    int n = A.length();
    if((A[n-1] -'0')%2 == 1){
        return 0;
    }
    if(A == "2"){
        return 1;
    }
    int rem = 0;
    string ans = "";
    for(int i = 0; i < n; i++){
        int num = rem*10 + A[i]-'0';
        if(num == 1){
            if(i == 0){
                rem = 1;
                continue;
            }
        }
        ans.push_back(num/2 + '0');
        rem = num%2;
    }
    return power(ans);
}
