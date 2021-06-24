#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &grid, pair<int,int> src,pair<int,int> dest,int steps,int &longest, vector<pair<int,int>> &dir){

	if(src==dest){
		longest=max(longest,steps);
		return;
	}

	grid[src.first][src.second]=0;

	for(int i=0;i<4;i++){

		int newr= src.first+dir[i].first;
		int newc= src.second+dir[i].second;

		if(newr>=0&&newr<grid.size()&&newc>=0&&newc<grid[0].size()&&grid[newr][newc]!=0){
			helper(grid,{newr,newc},dest,steps+1,longest,dir);
		}

	}

	grid[src.first][src.second]=1;


}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

  int m,n;
  cin>>m>>n;

  vector<vector<int>> grid(m,vector<int> (n));

  for(int i=0;i<m;i++){
  	for(int j=0;j<n;j++){
  		cin>>grid[i][j];
  	}
  }

  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;

  pair<int,int> src= {x1,y1};
  pair<int,int> dest ={x2,y2};

  vector<pair<int,int>> dir ={{0,-1},{-1,0},{1,0},{0,1}};

  int longest=INT_MIN;

  helper(grid,src,dest,0,longest,dir);

  cout<<longest<<"\n";




}
