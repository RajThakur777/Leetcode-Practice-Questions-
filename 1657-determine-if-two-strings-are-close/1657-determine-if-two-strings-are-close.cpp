class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char , int> mpp1,mpp2;
        for(int i=0; i<word1.size(); i++) {
            mpp1[word1[i]]++;
        }

        for(int i=0; i<word2.size(); i++) {
            mpp2[word2[i]]++;
        }

        for(int i=0; i<word2.size(); i++) {
            if(mpp1.find(word2[i]) == mpp1.end()) {
                return false;
            }
        }

        vector<int> arr1 , arr2;

        for(auto it : mpp1) {
            arr1.push_back(it.second);
        }

        for(auto it : mpp2) {
            arr2.push_back(it.second);
        }

        sort(arr1.begin() , arr1.end());
        sort(arr2.begin() , arr2.end());

        for(auto x : arr1) {
            cout<<x<<endl;
        }

        for(auto x : arr2) {
            cout<<x<<endl;
        }

        return (arr1 == arr2);
    }
};