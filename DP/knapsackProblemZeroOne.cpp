class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[],int val[],int W,int n,int idx, vector<vector<int>> &dp){
        
        if(idx==n){
            return 0;
        }
        
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }
        
        int include=0;
        int exclude=0;
        
        if(W-wt[idx]>=0){
            include= val[idx]+helper(wt,val,W-wt[idx],n,idx+1,dp);
        }
        
        exclude= helper(wt,val,W,n,idx+1,dp);
        
        return dp[idx][W]=max(include,exclude);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
       return helper(wt,val,W,n,0,dp);
    }
};
