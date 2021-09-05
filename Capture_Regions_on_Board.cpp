void removearea(vector<vector<char>>&a,int i,int j){
    if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size() || a[i][j] != 'O'){
        return;
    }
    a[i][j] = '.';
    removearea(a,i+1,j);
    removearea(a,i-1,j);
    removearea(a,i,j+1);
    removearea(a,i,j-1);
    return;
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int m = A[0].size();
    for(int i = 0; i < n; i++){
        removearea(A,i,0);
        removearea(A,i,m-1);
    }
    for(int i = 0; i < m; i++){
        removearea(A,0,i);
        removearea(A,n-1,i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '.'){
                A[i][j] = 'O';
            }
            else if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }
    return;
}
