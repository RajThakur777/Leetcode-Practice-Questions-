class Solution {
public:

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    static bool cmp(pair<int , pair<char , int>> p1 , pair<int , pair<char , int>> p2) {
        if(p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return (p1.second.second < p2.second.second);
    }
    
    string sortVowels(string s) {
        int n = s.size();

        int cnt_a = 0;
        int cnt_e = 0;
        int cnt_i = 0;
        int cnt_o = 0;
        int cnt_u = 0;

        int idx_a1 = 0;
        int idx_e1 = 0;
        int idx_i1 = 0;
        int idx_o1 = 0;
        int idx_u1 = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                cnt_a++;
            }
            else if(s[i] == 'e') {
                cnt_e++;
            }
            else if(s[i] == 'i') {
                cnt_i++;
            }
            else if(s[i] == 'o') {
                cnt_o++;
            }
            else if(s[i] == 'u'){
                cnt_u++;
            }
        }

        for(int i=0; i<n; i++) {
            if(s[i] == 'a') {
                idx_a1 = i;
                break;
            }
        }

         for(int i=0; i<n; i++) {
            if(s[i] == 'e') {
                idx_e1 = i;
                break;
            }
        }

         for(int i=0; i<n; i++) {
            if(s[i] == 'i') {
                idx_i1 = i;
                break;
            }
        }

         for(int i=0; i<n; i++) {
            if(s[i] == 'o') {
                idx_o1 = i;
                break;
            }
        }

         for(int i=0; i<n; i++) {
            if(s[i] == 'u') {
                idx_u1 = i;
                break;
            }
        }

        vector<pair<int , pair<char , int>>> vec;
        if(cnt_a > 0) {
            vec.push_back({cnt_a , {'a' , idx_a1}});
        }

        if(cnt_e > 0) {
            vec.push_back({cnt_e , {'e' , idx_e1}});
        }

         if(cnt_i > 0) {
            vec.push_back({cnt_i , {'i' , idx_i1}});
        }

         if(cnt_o > 0) {
            vec.push_back({cnt_o , {'o' , idx_o1}});
        }

         if(cnt_u > 0) {
            vec.push_back({cnt_u , {'u' , idx_u1}});
        }

        sort(vec.begin() , vec.end() , cmp);

        for(int i=0; i<vec.size(); i++) {
            cout<<vec[i].first<<" "<<vec[i].second.first<<endl;
        }

        string ans = s;
        int idx = 0;

        for(int i=0; i<vec.size(); i++) {
            auto it = vec[i];
            int freq = it.first;
            char ch = it.second.first;

            while(freq != 0 && idx < n) {
                if(isVowel(ans[idx])) {
                    ans[idx] = ch;
                    freq--;
                }
                idx++;
            }
        }
        return ans;
    }
};