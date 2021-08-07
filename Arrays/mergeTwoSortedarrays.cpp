class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        
        if(nums2.empty()){
           // cout<<m<<" "<<n<<"\n";
            return;
        }
        if(nums1.empty()){
             for(int i=n;i<n+m;i++){
            //cout<<nums2[i-n]<<" ";
            swap(nums1[i],nums2[i-n]);
        }
            return;
        }
        
        int gap= ceil((float)(n+m)/2.00);
        
        while(true){
            
            int i=0;
            int j=gap;
            
            while(j<n){
                if(nums1[i]>nums1[j]){
                    swap(nums1[i],nums1[j]);
                }
                i++;
                j++;
            }
            
            j=j-n;
            
            while(i<n&&j<m){
                
                if(nums1[i]>nums2[j]){
                    swap(nums1[i],nums2[j]);
                }
                i++;
                j++;
                
            }
            
            i=i-n;
            while(j<m){
                
                 if(nums2[i]>nums2[j]){
                    swap(nums2[i],nums2[j]);
                }
                i++;
                j++;
                
            }
            
            if(gap/2==0){
                break;
            }
            gap=ceil((float)gap/2.00);
            
        }
        
        for(int i=n;i<n+m;i++){
            //cout<<nums2[i-n]<<" ";
            swap(nums1[i],nums2[i-n]);
        }
        
    }
};
//Test ID(flipkart):-298860503434281

//Solution 2

 void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
             int i=0;
    
    
    while(i<n){
        
        if(arr1[i]<=arr2[0]){
            i++;
            continue;
        }
        
        swap(arr1[i],arr2[0]);
        i++;
        long long num= arr2[0];
        int k=1;
        while(k<m&&num>arr2[k]){
            arr2[k-1]=arr2[k];
            k++;
        }
        arr2[k-1]=num;
        
        } 
        
        }