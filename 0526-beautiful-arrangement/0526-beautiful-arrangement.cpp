class Solution {
public:

    int solve(int idx , set<int> &st , int n , int num) {
        if(idx > n) return 1;

        int ans = 0;

        for(int i=1; i<=n; i++) {
            if(st.find(i) != st.end()) continue;

            if((idx % i == 0) || (i % idx == 0)) {
                st.insert(i);
                ans += solve(idx+1 , st , n , i);
                st.erase(i);
            }
        }
        return ans;
    }

    int countArrangement(int n) {
        set<int> st;

        return solve(1 , st , n , 1);
    }
};