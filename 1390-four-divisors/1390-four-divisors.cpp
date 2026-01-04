class Solution {
public:

    vector<int> generateDivisors(int n) {
        vector<int> res;

        for(int i=1; i*i<=n; i++) {
            if(n % i == 0) {
                res.push_back(i);

                if(i != (n / i)) {
                    res.push_back((n / i));
                }
            }
        }
        return res;
    }
  
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for(int i=0; i<nums.size(); i++) {
            vector<int> div = generateDivisors(nums[i]);

            if(div.size() == 4) {
                sum += div[0];
                sum += div[1];
                sum += div[2];
                sum += div[3];
            }
        }      
        return sum;
    }
};