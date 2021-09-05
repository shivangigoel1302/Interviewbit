string Solution::longestCommonPrefix(vector<string> &A) {
    string s = "";
    sort(A.begin(),A.end());
    string first = A[0];
    string second = A[A.size()-1];
    int i = 0;
    while(i < first.size()){
        if(first[i] == second[i]){
            s += first[i];
        }
        i++;
    }
    return s;
}
