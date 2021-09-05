int Solution::solve(vector<string> &A) {
    int n = A.size();
    int ms = A[0].size();
    vector<vector<int>>h1(ms,vector<int>(3,-1));
    vector<vector<int>>h2(ms,vector<int>(3,-1));
    unordered_map<char,int>m;
    m['r'] = 0;
    m['g'] = 1;
    m['b'] = 2;
    for(int i = 0; i < n; i++){
        h1[0][m[A[i][0]]] = max(h1[0][m[A[i][0]]],0);
    }
    for(int i = 1; i < ms; i++){
        for(int k = 0; k < 3; k++){
            h1[i][k] = h1[i-1][k] == -1? -1: h1[i-1][k]+1;
        }
        for(int j = 0; j < n; j++){
            h1[i][m[A[j][i]]] = max(h1[i][m[A[j][i]]],0);
        }
    }
    for(int i = n-1; i >= 0; i--){
        h2[ms-1][m[A[i][ms-1]]] = max(h2[ms-1][m[A[i][ms-1]]],0);
    }
    for(int i = ms-2; i >= 0; i--){
        for(int k = 0; k < 3; k++){
            h2[i][k] = h2[i+1][k] == -1 ? -1 : h2[i+1][k] + 1;
        }
        for(int j = n-1; j >= 0; j--){
            h2[i][m[A[j][i]]] = max(h2[i][m[A[j][i]]],0);
        }
    }
    vector<vector<int>>mx(ms,vector<int>(3,INT_MIN));
    vector<vector<int>>mn(ms,vector<int>(3,INT_MAX));
    for(int i = 0; i < ms; i++){
        for(int j = 0; j < n; j++){
            mn[i][m[A[j][i]]] = min(mn[i][m[A[j][i]]],j);
            mx[i][m[A[j][i]]] = max(mx[i][m[A[j][i]]],j);
        }
    }
    int ans = 0;

    for(int i = 0; i < ms; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k || mn[i][k] > 1000 || mx[i][j] < 0){
                    continue;
                }
                if(h1[i][3-j-k] != -1){
                    ans = max(ans,abs(mx[i][j] - mn[i][k] + 1)*(h1[i][3-j-k]+1));
                }
                if(h2[i][3-j-k] != -1){
                    ans = max(ans,abs(mx[i][j] - mn[i][k] + 1)*(1+ h2[i][3-j-k]));
                }
            }
        }
    }
    return (ans+1)/2;
}
