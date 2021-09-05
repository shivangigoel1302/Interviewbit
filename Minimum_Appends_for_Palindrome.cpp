int lps(string s){
    int i = 0,j=1;
    int n = s.length();
    vector<int>v(n);
    v[0] = 0;
    while(j < n){
        if(s[i] == s[j]){
            v[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i == 0){
                v[j] =0;
                j++;
            }
            else{
                i = v[i-1];
            }
        }
    }
    return v[n-1];
}
int Solution::solve(string A) {
    string temp = A;
    reverse(temp.begin(),temp.end());
    A = temp + "$" + A;
    return temp.size() - lps(A);
}
