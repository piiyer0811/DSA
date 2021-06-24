class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> s(n);
        for(int i=1;i<=n;i++){
            s[i-1]=i;
        }
        
        for(int i=0;i<k-1;i++){
            
//             for(auto var:s){
//                 cout<<var<<" ";
//             }
//             cout<<"\n";
            
            int j=n-1;
            while(j>=1&&s[j-1]>s[j]){
                //cout<<s[j]<<"\n";
                j--;
            }
            
            int num= s[j-1];
            
           int ans=-1;
            
            int l=j;
            int r=n-1;
            while(l<=r){
                
                int mid= l+(r-l)/2;
                if(s[mid]<num){
                  
                    r=mid-1;
                }
                else{
                      ans=mid;
                    l=mid+1;
                }
                
            }
            
            swap(s[j-1],s[ans]);
            sort(s.begin()+j,s.end());
            
            
            
                 
                 }
                 
                
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(s[i]);
        }
        return ans;
                 
                 
                 
    }
};
