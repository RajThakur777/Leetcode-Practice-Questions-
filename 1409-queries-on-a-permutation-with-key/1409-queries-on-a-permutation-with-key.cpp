class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();

        vector<int> v(m);
        for(int i=0; i<m; i++) {
            v[i] = (i + 1);
        }

        vector<int> res(n);

        for(int i=0; i<n; i++) {
            int x = queries[i];
            int idx = -1;

            for(int j=0; j<v.size(); j++) {
                if(v[j] == x) {
                    idx = j;
                    break;
                }
            }

            cout<<idx<<" "<<endl;

            res[i] = idx;

            // for(int k=0; k<v.size(); k++) {
            //     cout<<v[k]<<" ";
            // }
            // cout<<endl;

            reverse(v.begin() , v.begin() + idx + 1);

            reverse(v.begin() + 1 , v.begin() + idx + 1);

            // for(int k=0; k<v.size(); k++) {
            //     cout<<v[k]<<" ";
            // }
            // cout<<endl;
        }
        return res;
    }
};