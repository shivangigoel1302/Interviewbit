double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
if(A.size()>B.size()) return findMedianSortedArrays(B,A);

    int n=A.size(),m=B.size();
    int low=0,high=n,i,j,xl,xr,yl,yr;

    while(low<=high){
        i = low + (high-low)/2;//taking a value in search space
        j = (n+m)/2-i;//adjusting partition in array y such that
        // no of elements on right part - no of elements in left part
        //= 0(even case) or 1(odd case)
        if(i==0) xl=INT_MIN;
        else xl=A[i-1];

        if(i==n) xr=INT_MAX;
        else xr = A[i];

        if(j==0) yl=INT_MIN;
        else yl=B[j-1];

        if(j==m) yr=INT_MAX;
        else yr = B[j];

        if(yl>xr){
            low = i+1;
        }else if(xl>yr){
            high = i-1;
        }else{
            if((n+m)%2==0){
                return (max(xl,yl)+min(yr,xr))/2.0;
            }else{
                return min(xr,yr);
            }
        }
    }
    return -1;

}
