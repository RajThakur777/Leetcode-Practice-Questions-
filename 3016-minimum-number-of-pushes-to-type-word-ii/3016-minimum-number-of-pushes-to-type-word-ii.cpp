class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[word[i]]++;
        }

        priority_queue<pair<int , char>> pq;

        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }

        int r = 1;
        int cnt = 8;

        int ans = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int freq = it.first;

            ans += (freq * r);
            cnt--;

            if(cnt == 0) {
                r++;
                cnt = 8;
            }
        }
        return ans;
    }
};