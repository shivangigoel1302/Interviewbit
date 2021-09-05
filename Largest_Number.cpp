string Solution::largestNumber(const vector<int> &A) {
    vector<string>v;
    for(int i = 0; i< A.size();i++){
        v.push_back(to_string(A[i]));
    }
    sort(v.begin(),v.end(),[](string a,string b){
        return a+b > b+a;
    });
    string str ="";
    for(auto s: v){
        str+=s;
    }
    int i = 0;
    while(i < str.size()){
        if(str[i] != '0'){
            return str;
        }
        i++;
    }
    return "0";
}
