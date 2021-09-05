int Solution::lengthOfLastWord(const string A) {
    int len = 0;
    for(int i = A.size()-1; i>=0;i--){
        if(A[i] != ' '){
            int j = i;
            while(j >=0 && A[j] !=' '){
                j--;
            }
            len = i-j;
            break;
        }
    }
    return len;
}
