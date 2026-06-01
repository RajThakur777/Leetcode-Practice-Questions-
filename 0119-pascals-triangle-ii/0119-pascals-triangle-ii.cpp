class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;

        vector<vector<int>> p(numRows);

        if(numRows >= 1) p[0] = {1};
        if(numRows >= 2) p[1] = {1 , 1};

        for(int i=2; i<numRows; i++) {
            vector<int> prev = p[i-1];

            vector<int> new_row;
            new_row.push_back(1);

            for(int j=0; j<prev.size()-1; j++) {
                new_row.push_back(prev[j] + prev[j+1]);
            }

            new_row.push_back(1);

            p[i] = new_row;
        }

        return p[rowIndex];
    }
};