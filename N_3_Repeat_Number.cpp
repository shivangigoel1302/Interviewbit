int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long long int cnt1 = 0;
    long long int num1 = INT_MAX;
    long long int cnt2=0,num2=INT_MAX;
    for(int i = 0; i < A.size(); i++){
        if(num1 == INT_MAX || A[i] == num1){
            num1 = A[i];
            cnt1++;
        }
        else if(num2 == INT_MAX || A[i] == num2){
            num2 = A[i];
            cnt2++;
        }
        else if(cnt1 == 0){
            cnt1 = 1;
            num1 = A[i];
        }
        else if(cnt2 == 0){
            cnt2 = 1;
            num2 = A[i];
        }
        else{
           cnt1--;
           cnt2--;
        }
    }
    long long int freq1=0,freq2 = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == num1){
            freq1++;
        }
        if(A[i] == num2){
            freq2++;
        }
    }
    if(freq1 > A.size()/3){
        return num1;
    }
    if(freq2 > A.size()/3){
        return num2;
    }
    return -1;
}
