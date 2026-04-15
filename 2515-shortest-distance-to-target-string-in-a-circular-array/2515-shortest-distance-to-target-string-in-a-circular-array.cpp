class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        vector<int> arr;

        for(int i=0; i<n; i++) {
            string str = words[i];

            if(str == target) {
                arr.push_back(i);
            }
        }

        if(arr.empty()) {
            return -1;
        }

        int dist = INT_MAX;
        for(int i=0; i<arr.size(); i++) {
            int v1 = abs(arr[i] - startIndex);
            int v2 = n - v1;
            int mini = min(v1 , v2);
            dist = min(dist , mini);
        }
        return dist;
    }
};