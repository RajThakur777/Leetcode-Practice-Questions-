class Solution {
public:
    
    bool isFind(vector<int> vec2 , int a , int b) {
        for(int i=0; i<vec2.size(); i++) {
            if(vec2[i] == a) {
                return true;
            }
        }
        return false;
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {      
        int sz = roads.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<sz; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int city1 = i;
                int city2 = j;

                vector<int> vec1 = mpp[city1];
                vector<int> vec2 = mpp[city2];

                int cnt = vec1.size() + vec2.size();

                if(isFind(vec2 , i , j)) {
                    cnt--;
                }

                ans = max(ans , cnt);
            }
        }
        return ans;
    }
};