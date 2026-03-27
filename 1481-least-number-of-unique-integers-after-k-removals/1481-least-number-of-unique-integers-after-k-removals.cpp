class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[arr[i]]++;
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }

        while(k > 0 && !pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int f = it.first;
            int ele = it.second;
            int mini = min(k , f);
            k -= mini;
            f -= mini;

            if(f > 0) {
                pq.push({f , ele});
            }
        }
        return pq.size();
    }
};