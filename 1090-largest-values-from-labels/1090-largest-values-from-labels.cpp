class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) { 
        int n = labels.size();

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(labels[i]);
        }

        int total = st.size();

        priority_queue<pair<int , int>> pq;
        for(int i=0; i<n; i++) {
            pq.push({values[i] , labels[i]});
        }  

        int cnt = numWanted;
        int prev = pq.top().second;

        int ans = pq.top().first;
        pq.pop();
        cnt--;

        map<int , int> mpp;
        mpp[prev] = 1;

        while(!pq.empty() && cnt != 0) {
            auto it = pq.top();
            pq.pop();

            int val = it.first;
            int l = it.second;

            if(mpp.find(l) == mpp.end()) {
                mpp[l]++;
                ans += val;
                cnt--;
            }
            else {
                int c = mpp[l];

                if(c >= useLimit) {
                    continue;
                }
                else {
                    mpp[l]++;
                    ans += val;
                    cnt--;
                }
            }
        }
        return ans;
    }
};