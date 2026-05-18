class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;

        for(int i=0; i<n; i++) {
            pq.push(stones[i]);
        }

        while(pq.size() > 1) {
            auto it1 = pq.top();
            pq.pop();

            auto it2 = pq.top();
            pq.pop();

            if(it1 == it2) {
                continue;
            }
            else {
                int wt = it1 - it2;
                pq.push(wt);
            }
        }
        if(pq.empty()) return 0;
        
        return pq.top();
    }
};