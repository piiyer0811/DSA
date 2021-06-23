class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int lc=0;
        int tr=0;
        int rc=m-1;
        int br=n-1;
        
        vector<int> ans;
        while(tr<=br && lc<=rc){
            
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[tr][i]);
            }
            tr++;
              if(tr>br){
                  break;
              }
            for(int i=tr;i<=br;i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;
            if(rc<lc){
                break;
            }
            for(int i=rc;i>=lc;i--){
                ans.push_back(matrix[br][i]);
            }
            br--;
            if(br<tr){
                break;
            }
            for(int i=br;i>=tr;i--){
                ans.push_back(matrix[i][lc]);
            }
            lc++;
            if(lc>rc)
                break;
            
        }
       return ans; 
    }
  
};
