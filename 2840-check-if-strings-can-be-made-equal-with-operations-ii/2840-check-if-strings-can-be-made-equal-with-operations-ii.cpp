class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();

        string str1;
        string str2;

        for(int i=0; i<n; i+=2) {
            str1 += s1[i];
            str2 += s2[i];
        }

        string str3;
        string str4;

        for(int i=1; i<n; i+=2) {
            str3 += s1[i];
            str4 += s2[i];
        }

        sort(str1.begin() , str1.end());
        sort(str2.begin() , str2.end());
        sort(str3.begin() , str3.end());
        sort(str4.begin() , str4.end());

        return ((str1 == str2) && (str3 == str4));
    }
};