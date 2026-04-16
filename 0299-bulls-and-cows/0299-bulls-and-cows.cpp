class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();

        int correct = 0;
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                correct++;
            }
        }

        unordered_map<char , int> mpp;
        for(int i=0; i<n; i++) {
            if(secret[i] != guess[i]) {
                mpp[secret[i]]++;
            }
        }

        int not_correct = 0;

        for(int i=0; i<n; i++) {
            if(secret[i] != guess[i]) {
                if(mpp.find(guess[i]) != mpp.end()) {
                    not_correct++;
                    mpp[guess[i]]--;
                    if(mpp[guess[i]] == 0) {
                        mpp.erase(guess[i]);
                    }
                }
            }
        }

        string s1 = to_string(correct) + "A";
        string s2 = to_string(not_correct) + "B";

        return s1 + s2;
    }
};