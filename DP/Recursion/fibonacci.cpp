class Solution {
  public:
    long long int nthFibonacci(long long int n){
        
        if(n==0||n==1){
            return n;
        }
        
        return (nthFibonacci(n-1)%1000000007+nthFibonacci(n-2)%1000000007)%1000000007;
        
    }
};
