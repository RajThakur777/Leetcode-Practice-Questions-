class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();

        sort(occupiedIntervals.begin() , occupiedIntervals.end());

        int prev_x = occupiedIntervals[0][0];
        int prev_y = occupiedIntervals[0][1];

        vector<vector<int>> ans;

        for(int i=1; i<n; i++) {
            if(occupiedIntervals[i][0] <= prev_y) {
                prev_x = min(prev_x , occupiedIntervals[i][0]);
                prev_y = max(prev_y , occupiedIntervals[i][1]);
            }
            else if(occupiedIntervals[i][0] == prev_y + 1) {
                prev_x = min(prev_x , occupiedIntervals[i][0]);
                prev_y = max(prev_y , occupiedIntervals[i][1]);
            }    
            else {
                ans.push_back({prev_x , prev_y});
                prev_x = occupiedIntervals[i][0];
                prev_y = occupiedIntervals[i][1];
            }
        }
        ans.push_back({prev_x , prev_y});

        vector<vector<int>> res;

        for(int i=0; i<ans.size(); i++) {
            vector<int> v = ans[i];
            int l = v[0];
            int r = v[1];

            if(l >= freeStart && r <= freeEnd) {
                continue;
            }
            else if(l == freeStart) {
                vector<int> v = {freeEnd + 1 , r};
                res.push_back(v);
            }    
            else if(r == freeEnd) {
                vector<int> v = {l , freeStart - 1};
                res.push_back(v);
            }
            else if(r >= freeStart && r <= freeEnd) {
                vector<int> val = {l , freeStart - 1};
                res.push_back(val);
            }
            else if(l >= freeStart && l <= freeEnd) {
                if(r > freeEnd) {
                    vector<int> val = {freeEnd + 1 , r};
                    res.push_back(val);
                }
            }
            else if(l < freeStart && r > freeEnd) {
                vector<int> val = {l , freeStart - 1};
                vector<int> val2 = {freeEnd + 1 , r};
                res.push_back(val);
                res.push_back(val2);
            }
            else if(l > freeEnd) {
                vector<int> val = {l , r};
                res.push_back(val);
            }
            else if(r < freeStart) {
                vector<int> val = {l , r};
                res.push_back(val);
            }
            else if(l == freeEnd) {
                vector<int> val = {l+1 , r};
                res.push_back(val);
            }
            else if(r == freeStart) {
                vector<int> val = {l , r-1};
                res.push_back(val);
            }
        }

        return res;
    }
};