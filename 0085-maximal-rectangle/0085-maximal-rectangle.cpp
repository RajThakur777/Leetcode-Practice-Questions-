class Solution {
public:
    //nsr
    vector<int> nsr(vector<int> &heights) {
        int n = heights.size();

        vector<int> right(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = n;
            }
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    right[i] = n;
                }
                else {
                    right[i] = st.top();
                }
            }
            st.push(i);
        }        
        return right;
    }

    //nsl
    vector<int> nsl(vector<int> &heights) {
        int n = heights.size();

        vector<int> left(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            if(st.empty()) {
                left[i] = -1;
            }
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    left[i] = -1;
                }
                else {
                    left[i] = st.top();
                }
            }
            st.push(i);
        }        
        return left;
    }

    int area(vector<int> &heights) {
        int ans = 0;

        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);

        for(int i=0; i<heights.size(); i++) {
            int width = right[i] - left[i] - 1;
            
            ans = max(ans , heights[i] * width);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> grid(m , vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1') {
                    grid[i][j] = 1;
                }
                else {
                    grid[i][j] = 0;
                }
            }
        }

        int ans = area(grid[0]);

        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] += grid[i-1][j];
                }
            }

            ans = max(ans , area(grid[i]));
        }
        return ans;
    }
};