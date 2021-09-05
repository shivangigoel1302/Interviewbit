int Solution::solve(string A) {
    unordered_map<char,bool>m;
    m['a'] = true;
    m['e'] = true;
    m['i'] = true;
    m['o'] = true;
    m['u'] = true;
    long long int vowel = 0;
    long long int ans = 0;
    long long int consonent = 0;
    long long mod = 1e9+7;
    for(int i = 0; i < A.size(); i++){
        if(m.find(A[i]) == m.end()){
            ans += vowel;
            consonent++;
        }
        else{
            ans += consonent;
            vowel++;
        }
    }
    return ans%mod;
}
