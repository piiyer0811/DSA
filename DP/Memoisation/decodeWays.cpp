class Solution {
public:
    map<string,char> util;
    int helper(string &s,int idx,vector<int> &dp){
        if(idx==s.size()){
            return dp[idx]= 1;
        }
        
        if(idx==s.size()-1){
            if(s[idx]=='0'){
                return dp[idx]= 0;
            }
            return dp[idx]= 1;
        }       
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string one="";
        one+=s[idx];
        string two= "";
        two+=s[idx];
        two+=s[idx+1];
        
        cout<<one<<" "<<two<<"\n";
        
        int way1=0;
        int way2=0;
        if(util.count(one)){
            way1=helper(s,idx+1,dp);
        }
        if(util.count(two)){
            way2= helper(s,idx+2,dp);
        }
        
        return dp[idx]=way1+way2;
        
    }
    int numDecodings(string s) {
        
        for(int i=1;i<=26;i++){
            util[to_string(i)]='A'+i-1;
        }
        
        vector<int> dp(s.size()+1,-1);
        
        return helper(s,0,dp);
        
    }
};
