class Solution {
public:

    void solve(int idx , vector<int> &arr , int n , vector<int> &ans , vector<vector<int>> &res) {
        if(idx == arr.size()) {
            res.push_back(ans);
            return;
        }

        ans.push_back(arr[idx]);
        solve(idx+1 , arr , n , ans , res);
        ans.pop_back();

        solve(idx+1 , arr , n , ans , res);
    }

    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int cnt = 0;

        vector<int> arr;

        for(int i=0; i<n; i++) {
            arr.push_back(i);
        }

        vector<vector<int>> res;

        vector<int> ans;

        solve(0 , arr , n , ans , res);

        // for(int i=0; i<res.size(); i++) {
        //     for(auto x : res[i]) {
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        for(int i=0; i<res.size(); i++) {
            vector<int> v1 = res[i];

            set<int> st;
            for(auto x : v1) {
                st.insert(x);
            }

            vector<vector<int>> dist(n , vector<int>(n , 1e9));

            for(auto it : roads) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(st.find(u) == st.end() && st.find(v) == st.end()) {
                    dist[u][v] = min(dist[u][v] , wt);
                    dist[v][u] = min(dist[v][u] , wt);
                }
            }

            for(int i=0; i<n; i++) {
                dist[i][i] = 0;
            }

            bool f = true;

            for(int k=0; k<n; k++) {
                for(int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                            dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }

            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(st.find(i) == st.end() && st.find(j) == st.end()) {
                        if(dist[i][j] > maxDistance) {
                            f = false;
                            break;
                        }
                    }
                }
                if(!f) {
                    break;
                }
            }

            if(f) {
                cnt++;
            }
        }

        return cnt;
    }
};