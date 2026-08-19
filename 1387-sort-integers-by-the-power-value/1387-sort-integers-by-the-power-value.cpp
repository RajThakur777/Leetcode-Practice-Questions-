class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int , int>> arr;

        for(int i=lo; i<=hi; i++) {
            int ele = i;
            int cnt = 0;

            while(ele != 1) {
                if(ele % 2 == 0) {
                    ele /= 2;
                }
                else {
                    int v = ele;
                    int r = (3 * v) + 1;

                    ele = r;
                }

                cnt++;
            }

            arr.push_back({cnt , i});
        }

        sort(arr.begin() , arr.end());

        return arr[k-1].second;
    }
};