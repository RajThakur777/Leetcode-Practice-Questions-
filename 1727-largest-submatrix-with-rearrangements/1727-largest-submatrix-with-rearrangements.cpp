class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> grid(m , vector<int>(n));

        for(int j=0; j<n; j++) {
            grid[0][j] = matrix[0][j];
        }

        for(int j=0; j<n; j++) {
            for(int i=1; i<m; i++) {
                if(matrix[i][j] == 0) {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] += grid[i-1][j];
                    grid[i][j]++;
                }
            }
        }

        int ans = 0;

        int val = n;

        for(int i=0; i<m; i++) {
            sort(grid[i].begin() , grid[i].end());

            for(int j=0; j<n; j++) {
                ans = max(ans , ((grid[i][j] * (val - j))));
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans;

        // unordered_map<int , vector<int>> mpp;

        // for(int j=0; j<n; j++) {
        //     for(int i=0; i<m; i++) {
        //         if(matrix[i][j] == 0) {
        //             mpp[i].push_back(0);
        //         }
        //         else {
        //             if(i == 0) {
        //                 mpp[i].push_back(1);
        //             }
        //             else {
        //                 vector<int> vec = mpp[i-1];
        //                 int val = 0;
        //                 for(int k=0; k<vec.size(); k++) {
        //                     if(k == j) {
        //                         val = vec[k];
        //                         break;
        //                     }
        //                 }
        //                 mpp[i].push_back(val+1);
        //             }
        //         }
        //     }
        // }

        // int ans = 0;
        // for(auto it : mpp) {
        //     vector<int> vec = it.second;

        //     sort(vec.begin() , vec.end());

        //     int sz = vec.size();

        //     for(int j=0; j<vec.size(); j++) {
        //         ans = max(ans , (vec[j] * (sz - j)));
        //     }
        // }

        // for(auto it : mpp) {
        //     cout<<it.first<<" ";
        //     for(auto t : it.second) {
        //         cout<<t<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};