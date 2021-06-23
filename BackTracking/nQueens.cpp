class Solution {
public:
    
    bool isPossible(vector<vector<char>> ans,int row,int col,int n){
        
        int i=row;
        int j=col;
        
        //column;
        
        while(i>=0){
            
            if(ans[i][j]=='Q'){
                return false;
            }
            i--;
            
        }
        
        //diagonals
        
        i=row;
        
        while(i>=0&&j>=0){
            if(ans[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i=row;
        j=col;
        
        while(i>=0&&j<n){
            if(ans[i][j]=='Q'){
                return false;
            }
            i--;
            j++;
        }
        
        
        return true;
        
        
    }
    
    void helper(vector<vector<char>> &ans,int n,int row,vector<vector<vector<char>>> &all){
        
        if(row==n){
            all.push_back(ans);
            return;
        }
        
        for(int col=0;col<n;col++){
                
            if(isPossible(ans,row,col,n)){
                
                ans[row][col]='Q';
                
                helper(ans,n,row+1,all);
                
                ans[row][col]='.';
                
            }
            
        }
        
        return;
        
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>> ans(n,vector<char> (n,'.'));
        
        vector<vector<vector<char>>> all;
        
        
        helper(ans,n,0,all);
        
        vector<vector<string>> finalans;
        
        for(auto var:all){
            vector<string> curr;
            for(auto var1:var){
                string temp="";
                for(auto var2:var1){
                    temp+=var2;
                }
                
                curr.push_back(temp);
                
            }
            
            finalans.push_back(curr);
        }
        
        
        return finalans;
        
    }
};
