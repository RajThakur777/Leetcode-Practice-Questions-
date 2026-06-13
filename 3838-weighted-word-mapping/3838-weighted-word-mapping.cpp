class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<char , int> mpp;

        for(int i=0; i<weights.size(); i++) {
            int val = weights[i];
            char ch = i + 'a';

            mpp[ch] = val;
        }

        string res;

        vector<char> vec(26);
        char ch = 'z';

        for(int i=0; i<26; i++) {
            vec[i] = ch;
            ch--;
        }

        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            int sum = 0;

            for(int j=0; j<str.size(); j++) {
                sum += mpp[str[j]];
            }

            sum %= 26;

            cout<<sum<<endl;

            char ch = vec[sum];

            res += ch;
        }
        return res;
    }
};