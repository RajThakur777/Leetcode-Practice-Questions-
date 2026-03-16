class Solution {
public:
    int m;
    int n;

    bool isValid(int r , int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        set<int> st;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int ele = grid[i][j];

                int mini = min(m , n);

                st.insert(grid[i][j]);

                int top_r = i;
                int top_c = j;

                for(int side=1; side<=mini; side++) {
                    int side_len = side;

                    int sum = 0;

                    int left_r = i + side_len;
                    int left_c = j - side_len;

                    int right_r = i + side_len;
                    int right_c = j + side_len;

                    int bottom_r = i + (2 * side_len);
                    int bottom_c = j;

                    if(!isValid(left_r , left_c) || !isValid(right_r , right_c) || !isValid(bottom_r , bottom_c)) {
                        break;
                    }

                    int k1 = top_r;
                    int k2 = top_c;

                    while(k1 != left_r && k2 != left_c) {
                        sum += grid[k1][k2];
                        k1++;
                        k2--;
                    }

                    sum += grid[k1][k2];

                    while(k1 != bottom_r && k2 != bottom_c) {
                        sum += grid[k1][k2];
                        k1++;
                        k2++;
                    }

                    sum += grid[k1][k2];

                    while(k1 != right_r && k2 != right_c) {
                        sum += grid[k1][k2];
                        k1--;
                        k2++;
                    }

                    sum += grid[k1][k2];

                    while(k1 != top_r && k2 != top_c) {
                        sum += grid[k1][k2];
                        k1--;
                        k2--;
                    }

                    sum -= grid[left_r][left_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[right_r][right_c];

                    st.insert(sum);
                }
            }
        }
        vector<int> vec;
        for(auto it : st) {
            vec.push_back(it);
        }

        sort(vec.rbegin() , vec.rend());

        if(vec.size() >= 3) {
            return {vec[0] , vec[1] , vec[2]};
        }
        return vec;
    }
};