#include<bits/stdc++.h>
using namespace std;


void helper(vector<pair<int,int>> g[],bool visited[],int src,int k,bool &ans){

	//cout<<k<<"\n";
	if(k<=0){

		//cout<<"hey"<<"\n";
		ans=true;
		return;
	}

	visited[src]=true;
	for(auto var:g[src]){

		int to= var.first;
		int dist= var.second;

		helper(g,visited,to,k-dist,ans);

	}

	visited[src]=false;



}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("input1.txt","r",stdin);
  freopen("output1.txt","w",stdout);
  #endif

  int n,src,k;
  cin>>n>>src>>k;

  vector<pair<int,int>> g[n+5];

  for(int i=0;i<n;i++){

  	int from,to,dist;
  	cin>>from>>to>>dist;

  	g[from].push_back({to,dist});
  	g[to].push_back({from,dist});

  }

  bool visited[n+5];
  memset(visited,false,sizeof(visited));

  bool ans=false;

  helper(g,visited,src,k,ans);

  if(ans){
  	cout<<"Yes"<<"\n";
  }
  else{
  	cout<<"No"<<"\n";
  }


  return 0;




}
