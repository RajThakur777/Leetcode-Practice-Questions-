class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();

        unordered_map<int , vector<int>> mpp;
        for(int i=0; i<n; i++) {
            for(auto it : friends[i]) {
                mpp[i].push_back(it);
            }
        }

        queue<int> q;
        q.push(id);

        int l = 0;
        vector<int> ans;

        vector<int> visited(n , 0);

        while(!q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                int node = q.front();
                q.pop();

                if(l == level && visited[node] == 0) {
                    ans.push_back(node);
                    visited[node] = 1;
                }

                visited[node] = 1;

                for(auto it : mpp[node]) {
                    q.push(it);
                }
            }
            l++;
            if(l > level) break;
        }

        unordered_map<string , int> mpp2;
        for(int i=0; i<ans.size(); i++) {
            int idx = ans[i];

            for(auto it : watchedVideos[idx]) {
                mpp2[it]++;
            }
        }

        priority_queue<pair<int , string> , vector<pair<int , string>> , greater<pair<int , string>>> pq;
        for(auto it : mpp2) {
            string str = it.first;
            int freq = it.second;

            pq.push({freq , str});
        }

        vector<string> res;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            string s = it.second;

            res.push_back(s);
        }
        return res;
    }
};