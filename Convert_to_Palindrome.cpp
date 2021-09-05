bool helper(string A, int s,int e,bool &removeal){
    if(s > e){
        return true;
    }
    while(s <= e){
        if(A[s] != A[e]){
            if(!removeal){
                removeal = true;
                if(helper(A,s,e-1,removeal) || helper(A,s+1,e,removeal)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        s++;
        e--;
    }
    return true;
}
int Solution::solve(string A) {
    bool removeal = false;
    return helper(A,0,A.size()-1,removeal);
}
