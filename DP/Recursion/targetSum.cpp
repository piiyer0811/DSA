int helper(int arr[],int n,int sum ,int idx){
        
        if(sum==0){
            return 1;
        }
        
        if(idx==n){
            return 0;
        }
        
        int include=0;
        int exclude=0;
        
        if(sum-arr[idx]>=0){
            include= helper(arr,n,sum-arr[idx],idx+1);
        }
        
        exclude= helper(arr,n,sum,idx+1);
        
        return include+exclude;
        
        
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        return helper(arr,n,sum,0);
	}
