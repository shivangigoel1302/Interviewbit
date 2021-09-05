vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(A);
    pq.push(B);
    pq.push(C);
    vector<int>ans;
    unordered_map<int,int>m;
    while(D > 0){
        if(m[pq.top()]){
            pq.pop();
            continue;
        }
        if(!m[pq.top() * A]){
            pq.push(pq.top()*A);
        }
        if(!m[pq.top()]*B){
            pq.push(pq.top()*B);
        }
        if(!m[pq.top()]*C){
            pq.push(pq.top()*C);
        }
        m[pq.top()]++;
        D--;
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;

//     vector<int> Solution::solve(int A, int B, int C, int D) {
//     vector<int> ans;
//     ans.push_back(1);
//     int i=0,j=0,k=0;
//     while(D--){
//         int x=min(ans[i]*A,min(ans[j]*B,ans[k]*C));
//         if(x==ans[i]*A)
//         i++;
//         if(x==ans[j]*B)
//         j++;
//         if(x==ans[k]*C)
//         k++;
//         ans.push_back(x);
//     }
//     ans.erase(ans.begin());
//     return ans;
// }

}
