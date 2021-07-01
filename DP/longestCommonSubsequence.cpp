class Solution {
public:
    int helper(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        
        
        if(i==text1.size()||j==text2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        char ch1= text1[i];
        char ch2= text2[j];
       
        
        if(ch1==ch2){
            
            return dp[i][j]= 1+helper(i+1,j+1,text1,text2,dp);
        }
        
        return dp[i][j]=max(helper(i,j+1,text1,text2,dp),helper(i+1,j,text1,text2,dp));
        
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
        
        return helper(0,0,text1,text2,dp);
        
    }
};
