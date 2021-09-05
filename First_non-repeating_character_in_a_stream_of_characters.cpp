string Solution::solve(string A) {
    map<char,int>m;
    string ans = "";
    queue<char>q;
    for(int i = 0; i < A.size(); i++){
        m[A[i]]++;
        if(m[A[i]] == 1){
            q.push(A[i]);
            ans += q.front();
        }
        else{
            while(!q.empty() && m[q.front()] > 1){
                q.pop();
            }
            if(!q.empty()){
                ans += q.front();
            }
            else{
                ans += '#';
            }
        }
    }
    return ans;
}
