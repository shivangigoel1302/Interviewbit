string Solution::simplifyPath(string A) {
    vector<string>ans;
    for(int i = 1; i < A.size();i++){
        string temp = "";
        while(i < A.size() && A[i] != '/'){
            temp += A[i];
            i++;
        }
        if(temp.size() > 0 && temp != "." && temp != ".." ){
            ans.push_back(temp);
        }
        if(temp == "."){
            continue;
        }
        else if(temp == ".."){
            if(ans.size() > 0){
                ans.pop_back();
            }
        }
    }
    string fin = "";
    for(int i = 0; i < ans.size(); i++){
        fin += "/" + ans[i];
    }
    if(fin.size() == 0){
        return "/";
    }
    return fin;
}
