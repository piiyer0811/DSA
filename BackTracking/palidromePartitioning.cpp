class Solution {
public:
    
    bool isPalindrome(string s){
        
        int l=0;
        int r=s.size()-1;
        
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
        
        
    }
    
    void helper( vector<vector<string>> &ans,vector<string> temp, string s){
        
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }
        
        string tillNow="";
        
        for(int i=0;i<s.size();i++){
            
            tillNow+=s[i];
            
            if(isPalindrome(tillNow)){
                
                temp.push_back(tillNow);
                helper(ans,temp,s.substr(i+1));
                temp.pop_back();
                
            }
            
        }
        
        return;
        
        
    }
        
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        helper(ans,temp,s);
        
        return ans;
        
    }
};
