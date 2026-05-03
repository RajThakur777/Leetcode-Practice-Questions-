class Solution {
public:
    bool rotateString(string s, string goal) {   
        for(int i=0; i<s.size(); i++) {
            string str = s;

            reverse(str.begin() + 1 , str.end());
            reverse(str.begin() , str.end());

            if(str == goal) {
                return true;
            }

            s = str;
        }
        return false;
    }
};