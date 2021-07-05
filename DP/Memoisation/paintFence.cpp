class Solution{
    public:
    #define ll long long
    ll helper(vector<int> &colors,int k,int idx,map<pair<pair<int,int>,int>,ll> &dp){

	if(idx==colors.size()){
		//cout<<"hey"<<"\n";
		return dp[{{colors[idx-1],colors[idx-2]},idx}]= 1;
	}

	if(idx==0||idx==1){
		ll ans=0;
		for(int i=1;i<=k;i++){
			colors[idx]=i;
			ans+=helper(colors,k,idx+1,dp)%1000000007;
		}

		//cout<<ans<<"\n";
		return ans;
	}

	if(dp.count({{colors[idx-1],colors[idx-2]},idx})){
		return dp[{{colors[idx-1],colors[idx-2]},idx}];
	}

	if(colors[idx-1]==colors[idx-2]){
		ll ans=0;
		for(int i=1;i<=k;i++){
			if(i==colors[idx-1]){
				continue;
			}

			colors[idx]=i;
			ans+=helper(colors,k,idx+1,dp)%1000000007;
		}

		//cout<<ans<<"\n";
		return dp[{{colors[idx-1],colors[idx-2]},idx}]= ans;
	}

	ll ans=0;
		for(int i=1;i<=k;i++){
			
			colors[idx]=i;
			ans+=helper(colors,k,idx+1,dp)%1000000007;
		}


		return dp[{{colors[idx-1],colors[idx-2]},idx}]=ans;
	
}

    ll countWays(int n, int k){
        
        vector<int> colors(n);

map<pair<pair<int,int>,int>,ll> dp;

      return helper(colors,k,0,dp);
    }
};