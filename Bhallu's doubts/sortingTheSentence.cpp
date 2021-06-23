class Solution {
public:
   static bool comparator(string s1,string s2){
       char ch1 = s1.back();
        char ch2 = s2.back();
        return (ch1<ch2);
        }
    string sortSentence(string s) {
        vector<string> v;
        string ans="";
        int i=0;
        while(i<s.length()){
            if(isalpha(s[i])){
               
                ans=ans+s[i];
                i++;
                
            }
            else if(isdigit(s[i])){
                ans=ans+s[i];
                i++;
            }
            else{
               // cout<<ans<<"hey"<<"\n";
                v.push_back(ans);
                ans="";
                i++;
            }
            
            
        } 
        v.push_back(ans);
        sort(v.begin(),v.end(),comparator);
            string word="";
        for(int i=0;i<v.size();i++){
           // cout<<v[i]<<"\n";
              
              word=word+v[i].substr(0,v[i].size()-1)+" ";
            }
      
        //cout<<word<<"\n";
        
        return word.substr(0,word.size()-1);
        
             
    }
