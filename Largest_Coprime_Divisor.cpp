int findgcd(int a,int b){
    if(a > b){
        return findgcd(b,a);
    }
    if(a == 0){
        return b;
    }
    return findgcd(b%a,a);
}
int Solution::cpFact(int A, int B) {
    while(findgcd(A,B) != 1){
        int x = findgcd(A,B);
        A/= x;
    }
    return A;

}
