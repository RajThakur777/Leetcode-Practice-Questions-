class Solution {
public:

    int VowelCnt(string s) {
        int cnt = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt++;
            }
        }
        return cnt;
    }
    
    string reverseWords(string s) {
       int n = s.size();

       string ans;

       string first;

       int i = 0; 
       while(i < n && s[i] != ' ') {
           first += s[i];
           i++;
       }

       int vowel = VowelCnt(first);

       while(i < n && s[i] == ' ') {
           i++;
       }

       ans += first;
       ans += ' '; 

       string str; 
       for(int k=i; k<n; k++) {
           if(s[k] == ' ') {
               int cnt2 = VowelCnt(str);

               if(cnt2 == vowel) {
                   reverse(str.begin() , str.end());

                   ans += str;
                   ans += ' ';
                   str.clear();
               }
               else {
                   ans += str;
                   ans += ' ';
                   str.clear();
               }
           }
           else {
               str += s[k];
           }
       } 

       if(first.size() == n) {
           return first;
       }
       else {
           int cnt2 = VowelCnt(str);

           if(cnt2 == vowel) {
               reverse(str.begin() , str.end());
           }

           ans += str;
           
           return ans;
       } 
    }
};