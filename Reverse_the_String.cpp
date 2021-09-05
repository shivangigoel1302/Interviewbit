string Solution::solve(string A) {
    string curr = "";
    string ans = "";
    for(int i = A.size()-1; i >=0 ;i--){
        if(A[i] == ' '){
            if(curr != ""){
                ans += curr;
                curr = "";
                ans += " ";
            }
        }
        else{
            curr = A[i] + curr;
        }
    }
    if(curr != ""){
        ans += curr;
    }
    int n = ans.size();
    if(ans[n-1] == ' '){
        return ans.substr(0,n-1);
    }
    return ans;
}
