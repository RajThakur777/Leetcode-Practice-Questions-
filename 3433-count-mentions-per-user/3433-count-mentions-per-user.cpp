class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(),
            [&](const vector<string>& lth, const vector<string>& rth) {

                int lth_timestamp = 0;
                int rth_timestamp = 0;

                try {
                    lth_timestamp = stoi(lth[1]);
                    rth_timestamp = stoi(rth[1]);
                } catch (const std::invalid_argument& e) {
                    return false;
                }

                if (lth_timestamp != rth_timestamp) {
                    return lth_timestamp < rth_timestamp;
                }

                if (rth[0] == "OFFLINE") {
                    return false;
                }

                return true;
            });

        vector<int> online(numberOfUsers , 0);

        vector<int> ans(numberOfUsers);

        for(int i = 0; i < n; i++) {
            string s1 = events[i][0];
            string s2 = events[i][1];
            string s3 = events[i][2];

            if(s1 == "MESSAGE") {
                if(s3 == "HERE") {
                    for(int i=0; i<numberOfUsers; i++) {
                        if(online[i] <= stoi(s2)) {
                            ans[i]++;
                        }
                    }
                }
                else if(s3 == "ALL") {
                    for(int i = 0; i < ans.size(); i++) {
                        ans[i]++;
                    }
                }
                else { 
                    string str = s3;

                    int num = 0;
                    for(int i=0; i<str.size(); i++) {
                        if(isdigit(str[i])) {
                            num = (num * 10) + (str[i] - '0');
                        }

                        if((i + 1 == str.size()) || (str[i + 1] == ' ')) {
                            ans[num]++;
                            num = 0;
                        }
                    }
                }
            }
            else if(s1 == "OFFLINE") {
                int num = 0;
                int time = 0;

                try {
                    num = stoi(s3);
                    time = stoi(s2);
                } catch (const std::invalid_argument& e) {
                }

                online[num] = time + 60;
            }
        }
        return ans;
    }
};
