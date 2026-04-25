class Solution {
public:
    bool check(set<int> &st , vector<bool> &visited) {
        for(auto it : st) {
            if(visited[it] == false) {
                return false;
            }
        }
        return true;
    }

    void solve(int idx , vector<int> &vec , vector<int> temp , vector<vector<int>> &res) {
        if(idx == vec.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(vec[idx]);
        solve(idx+1 , vec , temp , res);
        temp.pop_back();

        solve(idx+1 , vec , temp , res);
    }

    void dfs(int node , vector<bool> &visited , int &sum , vector<int> &nums , unordered_map<int , vector<int>> &mpp , set<int> &st) {
        visited[node] = true;
        sum += nums[node];

        for(auto it : mpp[node]) {
            if(!visited[it] && st.count(it)) {
                dfs(it , visited , sum , nums , mpp , st);
            }
        }
    }
    
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }


        vector<int> vec;
        for(int i=0; i<n; i++) {
            vec.push_back(i);
        } 

        vector<vector<int>> res;
        vector<int> temp;

        solve(0 , vec , temp , res);

        int ans = 0;

        for(int i=0; i<res.size(); i++) {
            vector<int> v = res[i];

            if(v.empty()) {
                continue;
            }

            set<int> st;
            for(int j=0; j<v.size(); j++) {
                st.insert(v[j]);
            }

 
            vector<bool> visited(n , false);

            int sum = 0;

            dfs(v[0] , visited , sum , nums , mpp , st);

            cout<<sum<<endl;

            if((sum % 2 == 0) && check(st , visited)) {
                ans++;
            }
        }

        for(int i=0; i<res.size(); i++) {
            for(int j=0; j<res[i].size(); j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        // return -1;
        return ans;
    }
};