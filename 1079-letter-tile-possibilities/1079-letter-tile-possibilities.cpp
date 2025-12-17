class Solution {
public:

    void solve(string tiles , set<string> &st , string s , vector<bool> &used) {
        if(!s.empty()) {
            st.insert(s);
        }

        for(int i=0; i<tiles.size(); i++) {
            if(used[i] == true) continue;

            used[i] = true;
            s += tiles[i];

            solve(tiles , st , s , used);

            s.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();

        set<string> st;

        string s;

        vector<bool> used(n , false);

        solve(tiles , st , s , used);

        return st.size();
    }
};