  #define mod 1000000007
    int countFriendsPairings(int n) 
    { 
        if(n==1||n==2||n==0){
            return n;
        }
        
        int takeOne= (countFriendsPairings(n-1))%mod;
        int takeTwo= ((n-1)%mod*(countFriendsPairings(n-2))%mod)%mod;
        
        return takeOne+takeTwo;
    }