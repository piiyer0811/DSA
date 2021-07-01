void helper(bool graph[101][101],vector<int> &colors, bool &ans, int src,int V,int m){
    
    if(src==V){
        ans=true;
    //      for(auto var: colors){
    //     cout<<var<<" ";
    // }
    // cout<<"\n";
        return;
    }
    
   
    
    for(int i=1;i<=m;i++){
        
        int color=i;
        bool canUse=true;
        for(int j=0;j<V;j++){
            if(graph[src][j]==0){
                continue;
            }
            if(colors[j]==color){
                canUse=false;
                break;
            }
        }
        
        if(!canUse){
            continue;
        }
        
        colors[src]=color;
        helper(graph,colors,ans,src+1,V,m);
        if(ans){
            break;
        }
        
        colors[src]=0;
        
    }
    
    return;
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V,0);
    bool ans=false;
    
    helper(graph,colors,ans,0,V,m);
    
    return ans;
}
