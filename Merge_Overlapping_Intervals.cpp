/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more detail
    vector<Interval>ans;
    sort(A.begin(),A.end(),[](Interval i1,Interval i2){
        if(i1.start == i2.start){
            return i1.end <= i2.end;
        }
        return i1.start < i2.start;
    });
    for(int i = 0; i < A.size();){
        int j = i+1;
        int right = A[i].end;
        while(j < A.size() && right >= A[j].start){
            right = max(right,A[j].end);
            j++;
        }
        Interval n(A[i].start,right);
        ans.push_back(n);
        i = j;
    }
    return ans;
}
