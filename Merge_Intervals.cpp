/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<Interval>v;
    int flag = 0;
    for(int i = 0; i < intervals.size(); i++){
        if(flag== 0 && intervals[i].start > newInterval.start){
            flag = 1;
            v.push_back(newInterval);
        }
        v.push_back(intervals[i]);
    }
    if(flag == 0){
        v.push_back(newInterval);
    }
    vector<Interval>ans;
    for(int i = 0;i < v.size();){
        int right = v[i].end;
        int j = i+1;
        while(j < v.size() && v[j].start < right){
            right = max(right,v[j].end);
            j++;
        }
        Interval n(v[i].start,right);
        ans.push_back(n);
        i = j;
    }
    return ans;
}
