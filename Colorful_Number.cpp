int findmult(string s){
    int mult = 1;
    for(int i = 0; i < s.size(); i++){
        mult *= (s[i] -'0');
    }
    return mult;
}
int Solution::colorful(int A) {
    unordered_map<int,bool>m;
    string s = to_string(A);
    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            string str = s.substr(i,j-i+1);
            int x = findmult(str);
            if(m.find(x) != m.end()){
                return 0;
            }
            m[x] = true;
        }
    }
    return 1;
}
