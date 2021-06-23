class Solution{
    public:
    
    void helper(vector<vector<int>> &m,int i,int j,int n,string path,vector<string> &ans){
        
        if(i<0||i>=n||j<0||j>=n){
            return;
        }
        
        if(m[i][j]==0){
            return;
        }
        
        
        if(i==n-1&&j==n-1){
            ans.push_back(path);
            return;
        }
        
        
        m[i][j]=0;
        
        helper(m,i+1,j,n,path+"D",ans);
        helper(m,i,j+1,n,path+"R",ans);
        helper(m,i-1,j,n,path+"U",ans);
        helper(m,i,j-1,n,path+"L",ans);
        
        m[i][j]=1;
        return;
        
        
        
        
    }    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        helper(m,0,0,n,"",ans);
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

