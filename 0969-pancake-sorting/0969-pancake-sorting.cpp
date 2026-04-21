class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int i = arr.size();
        vector<int> vec;
        while (i != 0) {
            if (arr[i - 1] == i) {
                i--;
            } else {
                int x;
                for (int j = 0; j < i; j++) {
                    if (arr[j] == i) {
                        x = j;
                        break;
                    }
                }
                vec.push_back(x + 1);
                reverse(arr.begin(), arr.begin() + x + 1);
                vec.push_back(i);
                reverse(arr.begin(), arr.begin() + i);
                i--;
            }
        }
        return vec;
    }
};