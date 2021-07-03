class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int wt[],int val[],int W,int n,int idx){
        
        if(idx==n){
            return 0;
        }
        
       
        int include=0;
        int exclude=0;
        
        if(W-wt[idx]>=0){
            include= val[idx]+helper(wt,val,W-wt[idx],n,idx+1);
        }
        
        exclude= helper(wt,val,W,n,idx+1);
        
        return max(include,exclude);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       return helper(wt,val,W,n,0);
    }
};
