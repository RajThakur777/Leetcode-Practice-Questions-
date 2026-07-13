class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {   
        string str = "123456789";

        vector<int> ans;

        for(int i=0; i<str.size(); i++) {
            for(int j=i; j<str.size(); j++) {
                string s = str.substr(i , (j - i + 1));

                long long num = stol(s);

                if(num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin() , ans.end());
        
        return ans;
    }
};