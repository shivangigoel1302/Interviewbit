int Solution::romanToInt(string A) {
    int ans = 0;
    for(int i = 0 ; i <A.size();){
        if(A[i] == 'I'){
            if(i+1 < A.size()){
                if(A[i+1] == 'V'){
                    ans += 4;
                    i+=2;
                }
                else if(A[i+1] == 'X'){
                    ans += 9;
                    i+=2;
                }
                else{
                    ans += 1;
                    i+=1;
                }
            }
            else{
                ans += 1;
                i++;
            }
        }
        else if(A[i] == 'X'){
            if(i+1 < A.size()){
                if(A[i+1] == 'L'){
                    ans += 40;
                    i+=2;
                }
                else if(A[i+1] == 'C'){
                    ans += 90;
                    i+=2;
                }
                else{
                    ans += 10;
                    i+=1;
                }
            }
            else{
                ans += 10;
                i++;
            }
        }
        else if(A[i] == 'C'){
            if(i+1 < A.size()){
                if(A[i+1] == 'D'){
                    ans += 400;
                    i+=2;
                }
                else if(A[i+1] == 'M'){
                    ans += 900;
                    i+=2;
                }
                else{
                    ans += 100;
                    i+=1;
                }
            }
            else{
                ans += 100;
                i++;
            }
        }
        else if(A[i] == 'V'){
            ans += 5;
            i++;
        }
        else if(A[i] == 'L'){
            ans += 50;
            i++;
        }
        else if(A[i] == 'D'){
            ans += 500;
            i++;
        }
        else if(A[i] == 'M'){
            ans += 1000;
            i++;
        }
    }
    return ans;
}
