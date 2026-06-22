class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;

        set<pair<int , int>> st;

        pq.push({nums1[0] + nums2[0] , {0 , 0}});
        st.insert({0 , 0});

        int cnt = k;

        vector<vector<int>> res;

        while(cnt != 0 && !pq.empty()) {
          auto it = pq.top();
          pq.pop();

          int sum = it.first;
          int i = it.second.first;
          int j = it.second.second;

          res.push_back({nums1[i] , nums2[j]});

          cnt--;

            if(i + 1 < nums1.size() && st.find({i + 1 , j}) == st.end()) {
               pq.push({nums1[i+1] + nums2[j] , {i+1 , j}});
               st.insert({i+1 , j});
            }

            if(j + 1 < nums2.size() && st.find({i , j + 1}) == st.end()) {
               pq.push({nums1[i] + nums2[j + 1] , {i , j + 1}});
               st.insert({i , j + 1});
            }
        }

        return res;
    }
};