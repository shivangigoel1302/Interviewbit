int required(int mid, vector<int>c){
    long long int person = 0;
    long long int sum = 0;
    for(int i = 0; i < c.size(); i++){
        sum += c[i];
        if(sum > mid){
            sum = c[i];
            person++;
        }
    }
    return person+1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int sum = 0,maximum = INT_MIN;
    for(int i = 0; i < C.size(); i++){
        maximum = max((int)maximum,C[i]);
        sum += C[i];
    }
    long long mod = 10000003;
    long long int max = (sum),min = (maximum);
    long long int ans = 0;
    //cout<<min<<" "<<max;
    while(min <= max){
        long long int mid = (min+max)/2;
        long long int x = required(mid,C);
        if(x <= A){
            ans = mid;
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    return (ans*B)%mod;
}
