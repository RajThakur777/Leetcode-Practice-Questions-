class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int ans = 0;

        unordered_map<char , int> mpp;
        int i = 0;
        int maxi = 0;

        for(int j=0; j<n; j++) {
            mpp[answerKey[j]]++;
            maxi = max(maxi , mpp[answerKey[j]]);

            while((j - i + 1) - maxi > k) {
                mpp[answerKey[i]]--;
                maxi = 0;
                for(auto it : mpp) {
                    maxi = max(maxi , it.second);
                }
                i++;
            }
            ans = max(ans , (j - i + 1));
        }      
        return ans;
    }
};