class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
            
        else if(n>=1000 && n<1e6) return 1LL*(n-1000+1);
            
        else if(n>=1e6 && n<1e9) return 1LL*(n-1e6)*2 + 1LL*(1e6 - 1e3 +1) +1;
            
        else if(n>=1e9 && n<1e12) return 1LL*(n-1e9)*3 + 1LL*(1e9 -1e6 + 1)*2 + 1LL*(1e6 - 1e3 + 1) ;
            
        else if(n>=1e12 && n<1e15) return 1LL*(n- 1e12)*4 + 1LL*(1e12 - 1e9 +1 )*3 + 1LL*(1e9 - 1e6)*2 + 1LL*(1e6 - 1e3 + 1) ;
        
        return 1LL*(1e15- 1e12 + 1)*4 + 1LL*(1e12 - 1e9)*3 + 1LL*(1e9 - 1e6)*2 + 1LL*(1e6 - 1e3) + 1;
    }
};