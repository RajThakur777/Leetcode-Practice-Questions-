class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) { 
        int n = plants.size();

        int ans = 0;

        int total = capacity;

        for(int i=0; i<n; i++) {
            if(plants[i] <= capacity) {
                ans++;
                capacity -= plants[i];
            }
            else {
                ans += (i) + (i + 1);
                capacity = (total - plants[i]);  
            }
        }
        return ans;
    }
};