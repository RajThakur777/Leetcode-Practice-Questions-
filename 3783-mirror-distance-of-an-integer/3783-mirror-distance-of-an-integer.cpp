class Solution {
public:
    int mirrorDistance(int n) {  
        string str = to_string(n); 

        reverse(str.begin() , str.end());

        int idx = -1;
        for(int i=0; i<str.size(); i++) {
            if(str[i] != '0') {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            int rev = stoi(str);

            return abs(n - rev);
        }

        string newStr;
        for(int i=idx; i<str.size(); i++) {
            newStr += str[i];
        }

        int rev = stoi(newStr);
        
        return abs(n - rev);
    }
};