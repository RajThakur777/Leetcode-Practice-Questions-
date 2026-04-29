class Solution {
public:
    int findLUSlength(string a, string b) {
        int m = a.size();
        int n = b.size();

        if(a == b) return -1;

        return (m >= n ? m : n);
    }
};