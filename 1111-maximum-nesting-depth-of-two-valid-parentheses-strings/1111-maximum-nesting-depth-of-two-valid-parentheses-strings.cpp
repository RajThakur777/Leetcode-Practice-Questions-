class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        stack<pair<char , int>> st;

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(seq[i] == '(') {
                if(st.empty()) {
                    ans.push_back(0);
                    st.push({'(' , 0});
                }
                else {
                    auto it = st.top();

                    int v = it.second;

                    int r = !v;

                    ans.push_back(r);
                    st.push({'(' , r});
                }
            }
            else {
                auto it = st.top();

                int v = it.second;

                ans.push_back(v);

                st.pop();
            }
        }

        return ans;
    }
};