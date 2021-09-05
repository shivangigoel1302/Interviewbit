
int Solution::solve(vector<string> &A) {
    sort(A.begin(),A.end());
    int l = 0,r=A.size()-1;
    while(l < r-1){
        double sum = stod(A[l]) + stod(A[r]) + stod(A[l+1]);
        if(sum < 1 ){
            l++;
        }
        else if(sum > 2){
            r--;
        }
        else{
            return 1;
        }
    }
    return 0;

}

// vector<double> B(A.size(),0);
// for(size_t i=0; i<A.size(); ++i)
//     B[i] = stod(A[i]);

// double L = (B[0]<B[1])?B[0]:B[1];
// double M = (B[1]>B[0])?B[1]:B[0];
// bool LL, UL;
// double curSum;
// for(size_t i=2; i<B.size(); ++i)
// {
//     curSum = L + M + B[i];
//     LL = curSum>1;
//     UL = curSum<2;

//     if(LL && UL)
//         return 1;
//     else if(!UL)
//     {
//         M = (B[i]<M)?B[i]:M;
//         if(L>M) swap<double>(L,M);
//     }
//     else if(!LL)
//     {
//         L = (B[i]>L)?B[i]:L;
//         if(L>M) swap<double>(L,M);
//     }
// }

// return 0;
// }
