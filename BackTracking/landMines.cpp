void helper(vector<vector<int>> &field,int row,int col,int steps,int &ans){
   
    if(col==field[0].size()){
        ans=min(ans,steps-1);
         //cout<<ans<<"\n";
        return;
    }
    
    if(steps>ans){
        return;
    }
    
    if(row<0||row>=field.size()||col<0||col>=field[0].size()){
        return;
    }
    if(field[row][col]==0||field[row][col]==-1){
        return;
    }
    
    field[row][col]=-1;
    helper(field,row,col+1,steps+1,ans);
    helper(field,row+1,col,steps+1,ans);
    helper(field,row-1,col,steps+1,ans);
    helper(field,row,col-1,steps+1,ans);
    
    field[row][col]=1;
    
    
}

int shortestPath(vector<vector<int>> &field)
{
	for(int i=0;i<field.size();i++){
        for(int j=0;j<field[0].size();j++){
            if(field[i][j]==0){
                if(i-1>=0)
                field[i-1][j]=-1;
                if(i+1<field.size())
                field[i+1][j]=-1;
                if(j-1>=0)
                field[i][j-1]=-1;
                if(j+1<field[0].size())
                field[i][j+1]=-1;
            }
        }
    }
   
    
    
    int ans=INT_MAX;
    
    for(int i=0;i<field.size();i++){
        helper(field,i,0,0,ans);
    }
    return ans==INT_MAX?-1:ans;
}
