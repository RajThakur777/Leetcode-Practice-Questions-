class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();

        map<char , int> mpp1;
        for(int i=0; i<n; i++) {
            mpp1[ransomNote[i]]++;
        }

        map<char , int> mpp2;
        for(int i=0; i<magazine.size(); i++) {
            mpp2[magazine[i]]++;
        }

        for(int i=0; i<ransomNote.size(); i++) {
            char ch = ransomNote[i];

            if(mpp2.find(ch) == mpp2.end() || mpp1[ch] > mpp2[ch]) {
                return false;
            }
        }
        return true;
    }
};