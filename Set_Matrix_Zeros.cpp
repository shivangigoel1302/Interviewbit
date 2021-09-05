void setrow(int i,vector<vector<int>>&a){
    for(int j = 0; j < a[i].size(); j++){
        a[i][j] = 0;
    }
}
void setcol(int j,vector<vector<int>>&a){
    for(int i= 0; i < a.size(); i++){
        a[i][j] = 0;
    }
}
void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int m = A.size();
    int n = A[0].size();
    vector<int>row(m,0);
    vector<int>col(n,0);
    for(int i = 0;i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 0){
                row[i]++;
                col[j]++;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(row[i]){
            setrow(i,A);
        }
    }
    for(int j = 0; j < n; j++){
        if(col[j]){
            setcol(j,A);
        }
    }
    return;
}
