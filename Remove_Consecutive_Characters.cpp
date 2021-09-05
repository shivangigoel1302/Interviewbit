string Solution::solve(string A, int B) {
    string s = "";
    for(int i = 0; i < A.size(); ){
        char c = A[i];
        int j = i;
        while(j < A.size() && A[j] == c){
            j++;
        }
        if(j-i == B){
            i = j;
            continue;
        }
        while(i < j){
            s += A[i];
            i++;
        }
    }
    return s;
}
