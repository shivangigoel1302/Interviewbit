int Solution::solve(int a, int b, int c, int d) {

    if(a==b && c == d){
        return 1;
    }
    if(a == c && b == d){
        return 1;
    }
    if(b == c && a ==d){
        return 1;
    }
    return 0;
}
