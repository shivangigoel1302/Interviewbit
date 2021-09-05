vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>>v;
    int m = A.size();
    int n = A[0].size();
    for(int g = 0; g < n; g++){
        vector<int>temp;
        for(int i = 0,j=g;i < m && j >= 0; i++,j--){
            temp.push_back(A[i][j]);
        }
        v.push_back(temp);
    }
    for(int g = 1; g < m; g++){
        vector<int>temp;
        for(int i = g,j=n-1;i < m; i++,j--){
            temp.push_back(A[i][j]);
        }
        v.push_back(temp);
    }
    return v;
}
