class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        for(int i=0; i<n; i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin() , tasks.end());

        int i = 0;

        unsigned long long time = tasks[0][0];

        priority_queue<pair<int , int> , vector<pair<int  ,int>> , greater<pair<int , int>>> pq;

        vector<int> ans;

        while(!pq.empty() || i < n) {
            while(i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }

            if(!pq.empty()) {
                time += pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else {
                time = tasks[i][0];
            }
        }

        return ans;
    }
};