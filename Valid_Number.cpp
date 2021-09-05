int Solution::isNumber(const string A) {
    int st = 0,ed = A.size()-1;
    while(st < A.size() && A[st] == ' '){
        st++;
    }
    while(ed >=0 && A[ed] == ' '){
        ed--;
    }
    while(st < A.size() && A[st]== '-'){
        st++;
    }
    if(st == A.size()) return 0;

    int deci = 0,e=0;
    for(;st <= ed;st++){
        if(A[st] >='0' && A[st] <='9'){
            continue;
        }
        else if(A[st] == '.' && deci == 0 && e == 0){
            deci++;
            if(st +1 >= A.size()){
                return 0;
            }
        }
        else if(A[st] == 'e' && e == 0){
            e++;
            if(A[st-1] == '.'){
                return 0;
            }
            if(A[st+1] == '-'){
                st++;
            }
        }
        else{
            return 0;
        }
    }
    return 1;
}
