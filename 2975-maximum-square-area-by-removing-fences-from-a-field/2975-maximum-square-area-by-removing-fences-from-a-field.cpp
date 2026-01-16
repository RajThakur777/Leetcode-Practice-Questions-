class Solution {
public:
    const int mod = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int hz = hFences.size();
        int vz = vFences.size();

        long long ans = -1;

        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin() , hFences.end());
        sort(vFences.begin() , vFences.end());

        unordered_set<long long> width;
        for(int i=0; i<vFences.size(); i++) {
            for(int j=i+1; j<vFences.size(); j++) {
                long long wd = vFences[j] - vFences[i];

                width.insert(wd);
            }
        }

        for(int i=0; i<hFences.size(); i++) {
            for(int j=i+1; j<hFences.size(); j++) {
                long long ht = hFences[j] - hFences[i];

                if(width.find(ht) != width.end()) {
                    ans = max(ans , 1LL * ht * ht);
                }
            }
        }
        

        if(ans == -1) return -1;

        return (int)(ans % mod);
    }
};