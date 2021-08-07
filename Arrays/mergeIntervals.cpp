class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> curr= {intervals[0][0],intervals[0][1]};
        vector<vector<int>> ans;
        
        for(int i=1;i<intervals.size();i++){
            
            
            int l1= curr[0];
            int r1=curr[1];
            int l2=intervals[i][0];
            int r2=intervals[i][1];
            
            if(r1>=l2){
                curr[1]=max(r1,r2);
            }
            
            else{
                ans.push_back(curr);
                curr[0]=l2;
                curr[1]=r2;
            }
            
            
        }
        
        ans.push_back(curr);
        return ans;
        
        
    }
};