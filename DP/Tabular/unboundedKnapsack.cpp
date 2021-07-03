class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1);
        dp[0]=0;
        
        for(int i=1;i<=W;i++){
            dp[i]=0;
            for(int j=0;j<N;j++){
                if(i-wt[j]>=0){
                    dp[i]=max(dp[i],val[j]+dp[i-wt[j]]);
                }
                
               
            }
            
            
        }
        
        return dp[W];
        
        
    }
};
