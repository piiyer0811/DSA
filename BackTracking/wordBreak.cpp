class Solution{
public:
    
    vector<string> helper(unordered_set<string> &Dict,string s){
        
        vector<string> ans;
        
        if(s.size()==0){
            return ans;
        }
        
        string tillNow= "";
        
        for(int i=0;i<s.size();i++){
            
            tillNow+=s[i];
            
            if(Dict.count(tillNow)){
            
            vector<string> rem= helper(Dict,s.substr(i+1));
        
            if(rem.size()!=0){
                for(auto var: rem){
                    ans.push_back(tillNow+" "+var);
                }
            }
            else{
                //cout<<tillNow<<"\n";
                ans.push_back(tillNow);
            }
            
            
            }
            
            
        }
        
       
        
        return ans;
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> Dict;
        for(auto var: dict){
            Dict.insert(var);
        }
        
        vector<string> temp;
        
        vector<string> ans= helper(Dict,s);
        
        
        for(auto var: ans){
            int count=0;
            for(auto var1:var){
            if(isalpha(var1)){
                count++;
            }
            }
            if(count==s.size()){
                temp.push_back(var);
            }
        }
        
       
        return temp;
        
    }
};
