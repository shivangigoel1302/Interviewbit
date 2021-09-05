int mod = 1000003;
int fact(int x){
    if(x <= 1){
        return 1;
    }
    return (x%mod)*(fact(x-1)%mod);
}
int Solution::findRank(string A) {

    long ans = 0;
    for(int i = 0; i < A.size()-1; i++){
        int count = 0;
        for(int j = i+1; j < A.size(); j++){
            if(A[j] < A[i]){
                count++;
            }
        }
        ans+= count*fact(A.size()-i-1);
    }
    return (ans+1) %mod;
}
