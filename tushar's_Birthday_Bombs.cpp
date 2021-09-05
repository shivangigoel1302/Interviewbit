vector<int> Solution::solve(int A, vector<int> &arr) {

//     int minVal = *min_element(B.begin(),B.end()); //calculation of minimum value in array
// int maxKicks = A/minVal; // maxkicks calc
// int n = B.size();
// int curSum = minVal * maxKicks;
// int min;
// for(int i=0;i<n;i++) if(B[i] == minVal) {min = i; break;} // finding the min index of minval
// vector<int> ans(maxKicks,min);
// //for(int i=0;i<maxKicks;i++) cout << ans[i] << " ";
// //cout << endl;
// //cout << min << endl;
// int c = 0;int i = 0;
// while(c < maxKicks && i < min){
// int temp = curSum- B[ans[c]] + B[i];
// //cout <<i << " " << c << " " << curSum << " " << temp << endl;
// if(temp > curSum && temp <= A){ans[c++] = i;curSum = temp;} //if new sum is better,update
// else i++; // i++ only when not updated, as kicks can be unlimited by same person.
// }
// return ans;

    int n = arr.size();
    int midx = -1;
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < minimum){
            minimum = arr[i];
            midx = i;
        }
    }
    int size = A/minimum;
    int currsum = size*minimum;
    vector<int>ans(size,midx);
    int k = 0;
    int i = 0;
    while(k < size && i < midx){
        int temp = currsum + arr[i] - arr[ans[k]];
        if(temp > currsum && temp <= A){
            currsum = temp;
            ans[k++] = i;
        }
        else{
            i++;
        }
    }
    return ans;
}
