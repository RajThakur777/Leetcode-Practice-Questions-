class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        for(int i=0; i<n; i++) {
            pq.push({__builtin_popcount(arr[i]) , arr[i]});
        }

        vector<int> ans;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }
        return ans;
    }
};