class Solution {
public:
    map<string,char> util;
    int numDecodings(string s) {
        
        for(int i=1;i<=26;i++){
            util[to_string(i)]='A'+i-1;
        }
        
        vector<int> dp(s.size()+1,0);
        dp[0]=1;
        string first="";
        first+=s[0];
        if(util.count(first)){
            dp[1]=1;
        }
        
        for(int i=2;i<=s.size();i++){
            
            string one="";
            one+=s[i-1];
            string two="";
            two+=s[i-2];
            two+=s[i-1];
            
            if(util.count(one)){
                dp[i]+=dp[i-1];
            }
            if(util.count(two)){
                dp[i]+=dp[i-2];
            }
            
        }
        
        return dp[s.size()];
        
    }
};
