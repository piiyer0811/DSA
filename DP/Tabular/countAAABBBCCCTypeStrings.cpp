class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        
        int a=0;
        int b=0;
        int c=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='a'){
                a=((2*a)%1000000007+1%1000000007)%1000000007;
            }
            
            if(s[i]=='b'){
                b=(a%1000000007+(b*2)%1000000007)%1000000007;
            }
            
            if(s[i]=='c'){
                c=((c*2)%1000000007+b%1000000007)%1000000007;
            }
            
            
        }
        
        return c;
    }
};

