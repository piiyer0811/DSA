#include <bits/stdc++.h>
using namespace std;
#define n 8

bool helper(vector<vector<int>> &tour,int i,int j,int count,vector<pair<int,int>> &dir){

    //cout<<count<<"\n";

     

    if(count==(n*n)){

     for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                cout<<tour[k][l]<<" ";
            }
            cout<<"\n";
        }

        return true;
    }


    for(int k=0;k<8;k++){
        int newr= i+dir[k].first;
        int newc= j+dir[k].second;

        if(newr>=0&&newr<n&&newc>=0&&newc<n&&tour[newr][newc]==-1){
            tour[newr][newc]=count;
            bool poss= helper(tour,newr,newc,count+1,dir);
            if(poss){

                return true;
            }
            else{
                 tour[newr][newc]=-1;
            }
        }
    }


    return false;




}

int main() {


		vector<pair<int,int>> dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};


	//cout<<n<<"\n";
// 	helper(tour,i+2,j+1,n,count+1);
//     helper(tour,i+2,j-1,n,count+1);
//     helper(tour,i+1,j+2,n,count+1);
//     helper(tour,i+1,j-2,n,count+1);
//     helper(tour,i-1,j+2,n,count+1);
//     helper(tour,i-1,j-2,n,count+1);
//     helper(tour,i-2,j+1,n,count+1);
//     helper(tour,i-2,j-1,n,count+1);

	vector<vector<int>> tour(n,vector<int>(n,-1));
	tour[0][0]=0;

	helper(tour,0,0,1,dir);


}

