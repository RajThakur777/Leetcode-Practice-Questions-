class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) { 
        int n = asteroids.size();

        sort(asteroids.begin() , asteroids.end());

        long long sum = mass;
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(sum >= asteroids[i]) {
                sum += asteroids[i];
                cnt++;
            }
            else {
                break;
            }
        } 
        return (cnt == n);
    }
};