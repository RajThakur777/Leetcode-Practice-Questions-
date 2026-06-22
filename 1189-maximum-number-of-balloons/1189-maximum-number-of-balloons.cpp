class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();

        map<char , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[text[i]]++;
        }

        if((mpp.find('b') == mpp.end()) || (mpp.find('a') == mpp.end()) || (mpp.find('l') == mpp.end()) || (mpp.find('o') == mpp.end()) || (mpp.find('n') == mpp.end())) {
            return 0;
        }

        if(mpp['l'] <= 1 || mpp['o'] <= 1) {
            return 0;
        }

        int ans = INT_MAX;

        for(auto it : mpp) {
            if(it.first == 'a' || it.first == 'b' || it.first == 'n') {
                ans = min(ans , it.second);
            }
        }

        int val = min((mpp['l'] / 2) , (mpp['o'] / 2));

        return min(val , ans);
    }
};