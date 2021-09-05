int Solution::solve(string A) {
    long long int ans = 0;
    unordered_map<char,bool>m;
    m['a'] = true;
    m['e'] = true;
    m['i'] = true;
    m['o'] = true;
    m['u'] = true;
    m['A'] = true;
    m['E'] = true;
    m['I'] = true;
    m['O'] = true;
    m['U'] = true;
    for(int i = 0; i < A.size(); i++){
        if(m.find(A[i]) != m.end()){
            ans += (A.size() - i)%(10003);
        }
    }
    return ans%(10003);
}
