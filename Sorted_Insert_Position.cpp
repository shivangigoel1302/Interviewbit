int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l = 0;
    int r = A.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
        return l;

}
