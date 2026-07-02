class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();

        string r1;
        string r2;

        int i = 0;
        int j = 0;

        while(i < m || j < n) {
            while(i < m && version1[i] != '.') {
                r1 += version1[i];
                i++;
            }

            while(j < n && version2[j] != '.') {
                r2 += version2[j];
                j++;
            }

            if(r1.empty()) {
                r1 += '0';
            }

            if(r2.empty()) {
                r2 += '0';
            }

            int num1 = stoi(r1);
            int num2 = stoi(r2);

            if(num1 > num2) {
                return 1;
            }
            else if(num2 > num1) {
                return -1;
            }

            r1 = "";
            i++;

            r2 = "";
            j++;
        }
        return 0;
    }
};