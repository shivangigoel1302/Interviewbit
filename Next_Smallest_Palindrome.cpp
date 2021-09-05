string helper(string s){
    string ans = "";
    int l = s.size()/2;
    int r = s.size()/2;
    if(s.size()%2 == 0){
        l--;
    }
    while(l >= 0 && s[l] == s[r]){
        l--;
        r++;
    }
    bool greater = false;
    if(l >= 0){
        if(s[l] > s[r]){
            greater = true;
        }
    }
    while(l >= 0){
        s[r] = s[l];
        r++;
        l--;
    }
    if(!greater){
        l = s.size()/2;
        r = s.size()/2;
        if(s.size()%2 == 0){
            l--;
        }
        int carry = 1;
        if(l == r){
            int a = s[l] - '0';
            a++;
            carry = a/10;
            a%=10;
            s[l] = (a) + '0';
            l--;
            r++;
        }
        while(l >=0 && carry){
            int a = s[l] -'0';
            a += carry;
            carry = a/10;
            a%=10;
            s[l] = s[r] = (a) + '0';
            l--;
            r++;
        }
    }
    return s;
}
string Solution::solve(string A) {
    int i = 0;
    while(i < A.size()){
        if(A[i] != '9'){
            break;
        }
        i++;
    }
    if(i == A.size()){
        string s = "1";
        for(int j = 1; j < A.size(); j++){
            s += "0";
        }
        s += "1";
        return s;
    }
    return helper(A);
}
