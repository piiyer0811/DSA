class Solution 
{
    public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void helper(vector<int> &A,int sum,int idx,vector<int> &temp,vector<vector<int>> &ans){
        
        
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        
        if(idx==A.size()){
            return;
        }
        
       
            
            if(sum>=A[idx]){
            temp.push_back(A[idx]);
            helper(A,sum-A[idx],idx,temp,ans);
            temp.pop_back();
            }
            
            
            helper(A,sum,idx+1,temp,ans);
            
        
        
        
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<vector<int>> finalans;
        
        vector<int> temp;
        set<int> dup;
        for(auto var:A){
            dup.insert(var);
        }
        
        A.clear();
        
        for(auto var:dup){
            A.push_back(var);
        }
        
        helper(A,B,0,temp,ans);
        
        
        
        return ans;
    }
};
