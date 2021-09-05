void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<bool>visited(A.size(),false);
    for(int i = 0; i < A.size(); i++){
        int j = i;
        while(!visited[j]){
            int temp = A[i];
            while(!visited[j]){
                visited[j] = true;
                int idx = A[j];
                if(idx == i){
                    A[j] = temp;
                }
                else{
                    A[j] = A[A[j]];
                }
                j = idx;
            }

        }
    }
    return;
}
