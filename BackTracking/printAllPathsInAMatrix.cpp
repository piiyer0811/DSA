#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> ans)
{
   int n = ans.size();
   int m = ans[0].size();
   
   for(int i=0 ; i<n ; i++)
   {
       for(int j=0 ; j<m ; j++)
       {
           cout<<ans[i][j]<<" ";
       }
       cout<<'\n';
   }
}

void solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& ans,vector<int>& v)
{
    if(i == n-1 and j == m-1)
    {	
    	v.push_back(grid[i][j]);
        ans.push_back(v);
        v.pop_back();
        return;
    }
    
    if(i<0||i>=n||j<0||j>=m){
    	return;
    }
    if(grid[i][j]==-1){
    	return;
    }

   int curr = grid[i][j];
   grid[i][j] = -1;
   
   v.push_back(curr);
   
   
   
   		 solve(grid,i,j+1,n,m,ans,v);
       solve(grid,i+1,j,n,m,ans,v);
  	  
   
   
   grid[i][j] = curr;
   v.pop_back();
   
   return;
}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

   int n,m;
    cin>>n>>m;
    
    
    vector<vector<int>> grid(n,vector<int>(m));
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin>>grid[i][j];
        }
    }
    
    vector<vector<int>> ans;
    vector<int> v;
    
    solve(grid,0,0,n,m,ans,v);
    
    print(ans);
    
    return 0;



}
