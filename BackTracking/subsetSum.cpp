class Solution{
public:
    
    bool helper(int arr[],int idx,int currsum,int reqsum,int N){
        
        if(idx==N||currsum>reqsum){
            return false;
        }
        
        if(reqsum==currsum){
            return true;
        }
        
        bool include= helper(arr,idx+1,currsum+arr[idx],reqsum,N);
        bool exclude= helper(arr,idx+1,currsum,reqsum,N);
        
        return include||exclude;
        
        
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        
        return helper(arr,0,0,sum/2,N);
    }
};
