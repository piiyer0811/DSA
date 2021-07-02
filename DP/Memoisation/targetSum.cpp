 int helper(int arr[],int n,int sum ,int idx,vector<vector<int>> &dp){
        
        if(sum==0){
            return dp[idx][sum]=1;
        }
        
        if(idx==n){
            return 0;
        }
        
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        
        int include=0;
        int exclude=0;
        
        if(sum-arr[idx]>=0){
            include= helper(arr,n,sum-arr[idx],idx+1,dp);
        }
        
        exclude= helper(arr,n,sum,idx+1,dp);
        
        return dp[idx][sum]=(include%1000000007+exclude%1000000007)%1000000007;
        
        
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return helper(arr,n,sum,0,dp);
	}
	  
