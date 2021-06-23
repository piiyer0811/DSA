class Solution {
public:
    void helper(vector<int> stones,int idx,int sum,int currsum,int &ans ){
        

        if(idx==stones.size()){
             if(sum>=(2*currsum)){
        ans=min(ans,sum-(2*currsum));
        }
            return;
        }
        
        if(sum>=(2*currsum)){
        ans=min(ans,sum-(2*currsum));
        }
        //cout<<ans<<"\n";
        
        
        helper(stones,idx+1,sum,currsum+stones[idx],ans);
        helper(stones,idx+1,sum,currsum,ans);
        
        
        
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        
        int ans=INT_MAX;
        int sum=0;
        for(auto var:stones){
            sum+=var;
        }
        helper(stones,0,sum,0,ans);
        
        return ans;
        
    }
};
