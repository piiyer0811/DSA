
class Solution 
{
    public:
    
    bool isPossible(int option, int row,int col, int grid[N][N]){
        
        int i=row;
        int j=col;
        
        int k=0;
        //column
        
        while(k<N){
            if(grid[k][j]==option){
                return false;
            }
            k++;
        }
        
        //row;
        k=0;
        while(k<N){
            if(grid[i][k]==option){
                return false;
            }
            k++;
        }
        
        //matrix
        
        int startx= (i/3)*3;
        int starty= (j/3)*3;
        
        for(int m=startx;m<startx+3;m++){
            for(int n=starty;n<starty+3;n++){
                if(grid[m][n]==option){
                    return false;
                }
            }
        }
        
        
        return true;
        
    }
    void helper(int grid[N][N],int i,int j,bool &ans,int fc){
        
       if(i==N){
           ans=true;
           if(fc==2){
           for(int i=0;i<N;i++){
             for(int j=0;j<N;j++){
                 cout<<grid[i][j]<<" ";
             }
         }
           }
           return;
       }
       
       if(j==N){
           helper(grid,i+1,0,ans,fc);
           return;
       }
       
       if(grid[i][j]!=0){
           helper(grid,i,j+1,ans,fc);
           return;
       }
       
       for(int option=1;option<=9;option++){
           
           if(isPossible(option,i,j,grid)){
               grid[i][j]=option;
                helper(grid,i,j+1,ans,fc);
               grid[i][j]=0;
           }
           
           
       }
       
       return;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        bool ans=false;
        helper(grid,0,0,ans,1);
        return ans;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        bool ans=false;
        helper(grid,0,0,ans,2);
         
         
    }
};
