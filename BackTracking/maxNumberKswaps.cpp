class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string str,int idx,int k,string &ans){
        
        //cout<<str<<" "<<idx<<" "<<k<<"\n";
        if(k==0){
            ans=max(ans,str);
            return;
        }
        
        if(idx==str.size()){
            ans=max(str,ans);
            return;
        }
        
       
       
        
         char  ch='0';
        for(int i=idx;i<str.size();i++){
            ch=max(ch,str[i]);
        }
        
        for(int i=idx;i<str.size();i++){
            
            if(str[i]==ch){
                
                
                if(str[idx]!=str[i]){
                swap(str[idx],str[i]);
                helper(str,idx+1,k-1,ans);
                swap(str[idx],str[i]);
                }
                
                else{
            
                helper(str,idx+1,k,ans);
                }
                
                
               
                
            }
        }
        
        return;
        
    }
    string findMaximumNum(string str, int k)
    {
       string ans="";
       helper(str,0,k,ans);
       
       return ans;
    }
};

