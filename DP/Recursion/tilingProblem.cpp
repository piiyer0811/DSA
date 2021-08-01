
    long long numberOfWays(long long N) {
        
        if(N==1||N==2){
            return N;
        }
        
        return (numberOfWays(N-1)%1000000007+numberOfWays(N-2)%1000000007)%1000000007;
    }