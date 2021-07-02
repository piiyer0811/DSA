	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
	    for(int i=0;i<sum+1;i++){
	        dp[0][i]=0;
	    }
	    
	    for(int i=0;i<=n;i++){
	        dp[i][0]=1;
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            
	            if(j-arr[i-1]>=0){
	                dp[i][j]+=dp[i-1][j-arr[i-1]]%1000000007;
	            }
	            
	            dp[i][j]+=dp[i-1][j]%1000000007;
	            
	            dp[i][j]=dp[i][j]%1000000007;
	            
	            
	        }
	    }
	    
	   // for(int i=0;i<=n;i++){
	   //     for(int j=0;j<=sum;j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<"\n";
	   // }
	    
	    
	    return dp[n][sum];
        
	}
