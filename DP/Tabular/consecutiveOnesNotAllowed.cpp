class Solution{
public:
	 #define ll long long
	#define mod 1000000007
	ll countStrings(int n) {
	    vector<vector<ll>> dp(2,vector<ll> (n+1));
	    
	    dp[0][1]=1;
	    dp[1][1]=1;
	    for(int i=2;i<=n;i++){
	        dp[0][i]=(dp[0][i-1]%mod+dp[1][i-1]%mod)%mod;
	        dp[1][i]=dp[0][i-1]%mod;
	    }
	 
	 return (dp[0][n]%mod+dp[1][n]%mod)%mod;   
	}
};
