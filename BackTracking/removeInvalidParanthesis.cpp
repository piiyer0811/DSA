class Solution {
public:
    bool isValid(string s){
        int balance=0;
        int i=0;
        while(i<s.size()){
            
            if(s[i]=='('){
                balance++;
            }
            else if(s[i]==')'){
                if(balance==0){
                    return false;
                }
                else{
                    balance--;
                }
            }
            
            i++;
            
        }
        
        return balance==0;
    }
    void helper(string s,int invalid,unordered_set<string> &ans, unordered_set<string> &done){
        
        if(invalid==0){
            
            if(isValid(s)){
                ans.insert(s);
            }
            return;
            
        }
        
        if(done.count(s)){
            return;
        }
        
        done.insert(s);
        
        for(int i=0;i<s.size();i++){
            
            if(isalpha(s[i])){
                continue;
            }
            
            string rem= s.substr(0,i)+s.substr(i+1);
            
            helper(rem,invalid-1,ans,done);
            
            
        }
        
        return;
        
        
        
        
    }
    vector<string> removeInvalidParentheses(string s) {
        
           int balance=0;
        int i=0;
        int count=0;
        while(i<s.size()){
                                     //))))))((((((((
            if(s[i]=='('){
                balance++;
            }
            else if(s[i]==')'){
                if(balance==0){
                    count++;
                }
                else{
                    balance--;
                }
            }
            
            i++;
            
        }
        int invalid= count+balance;
       // cout<<invalid;
        
        unordered_set<string> done;
        
        unordered_set<string> ans;
        helper(s,invalid,ans,done);
        
        vector<string> finalans;
        for(auto var:ans){
            finalans.push_back(var);
        }
        
        return finalans;
        
    }
};
