int getparent(int val,vector<int>&parent){
    if(val == parent[val]){
        return val;
    }
    return getparent(parent[val],parent);
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),[](vector<int>&v1,vector<int>&v2){
        return v1[2] < v2[2];
    });
    vector<int>parent(A+1);
    for(int i = 0; i < A+1; i++){
        parent[i] = i;
    }
    int i = 0;
    int cnt = 0;
    int ans = 0;
    while(cnt < A-1 && i < B.size()){
        int srcparent = getparent(B[i][0],parent);
        int destparent = getparent(B[i][1],parent);
        if(srcparent != destparent){
            parent[srcparent] = destparent;
            ans += B[i][2];
            cnt++;
        }
        i++;
    }
    return ans;


//     bool cmp(const vector<int> &a, const vector<int> &b){
//     return a[2]<b[2];
// }



// int Solution::solve(int n, vector<vector<int> > &b) {
//     sort(b.begin(), b.end(), cmp);
//     int parent[n+1];
//     for(int i=0; i<=n; i++) parent[i]=i;
//     int count=0;
//     int i=-1;int sum=0;
//     while(count!=n-1){
//         i++;
//         vector<int> c=b[i];
//         // return c[2];
//         int k=c[0];
//         int j=c[1];
//         while(parent[k]!=k){
//             k=parent[k];
//         }
//         while(parent[j]!=j){
//             j=parent[j];
//         }

//         if(k!=j)
//          {sum+=c[2];count++;parent[k]=j;}

//     }return sum;

}
