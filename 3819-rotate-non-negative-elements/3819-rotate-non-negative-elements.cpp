class Solution {
public:

    void rotateLeft(vector<int> &pos , int k) {
        int turns = k % pos.size();

        reverse(pos.begin() , pos.begin() + turns);
        reverse(pos.begin() + turns , pos.end());

        reverse(pos.begin() , pos.end());
        
    }
    
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> pos;
        for(int i=0; i<n; i++) {
            if(nums[i] >= 0) {
                pos.push_back(nums[i]);
            }
        }

        if(pos.size() == 0) return nums;

        rotateLeft(pos , k);

        int l = 0;
        int idx = 0;
        while(l < pos.size()) {
            if(nums[idx] >= 0) {
                nums[idx] = pos[l];
                idx++;
                l++;
            }
            else {
                idx++;
            }
        }
        return nums;
    }
};