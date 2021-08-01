class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int currmin=INT_MAX;
        int maxProfit=INT_MIN;
        
        for(int i=0;i<prices.size();i++){
            
            maxProfit=max(maxProfit,prices[i]-currmin);
            currmin=min(currmin,prices[i]);
            
        }
        
        return maxProfit<=0?0:maxProfit;
        
    }
};