class Solution {
public:

    bool isPossible(string str , int number , int sum , int idx) {
        if(idx == str.size()) {
            return (sum == number);
        }

        for(int i=idx; i<str.size(); i++) {
            sum += (stoi(str.substr(idx , i-idx+1)));
            if(isPossible(str , number , sum , i+1) == true) {
                return true;
            }
            sum -= (stoi(str.substr(idx , i-idx+1)));
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for(int i=1; i<=n; i++) {
            int num = i;
            int sq = (i * i);

            if(isPossible(to_string(sq) , num , 0 , 0)) {
                sum += sq;
            }
        }
        return sum;
    }
};