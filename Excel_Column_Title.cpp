string Solution::convertToTitle(int A) {
    string s ="";
    while(A > 0){
        int x = (A-1)%26;
        s = (char)(x+'A') + s;
        A = (A-1)/26;
    }
    return s;
}
