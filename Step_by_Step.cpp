int Solution::solve(int A) {
   int k = 0;
   int sum = 0;
   A = abs(A);
   while(sum < A || (A-sum)%2){
       k++;
       sum += k;
   }
   return k;
}
