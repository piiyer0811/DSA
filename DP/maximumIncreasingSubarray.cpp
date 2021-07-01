class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        if(scores.size()==0){
            return 0;
        }
        
        vector<pair<int,int>> newScores;
        
        for(int i=0;i<scores.size();i++){
            newScores.push_back({ages[i],scores[i]});
        }
        
        sort(newScores.begin(),newScores.end());
        
        vector<int> dp(scores.size());
        for(int i=0;i<scores.size();i++){
            dp[i]=newScores[i].second;
        }
        
        for(int i=0;i<scores.size();i++){
            
            int ans=dp[i];
            for(int j=0;j<i;j++){
                if(newScores[i].second>=newScores[j].second){
                    ans=max(ans,newScores[i].second+dp[j]);
                }
            }
            
            dp[i]=ans;
            
        }
        
        auto it= max_element(dp.begin(),dp.end());
        
        return (*it);
        
    }
};
