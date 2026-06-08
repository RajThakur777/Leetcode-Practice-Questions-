class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> less_element;
        vector<int> equal_element;
        vector<int> greater_element;

        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) {
                less_element.push_back(nums[i]);
            }
            else if(nums[i] > pivot) {
                greater_element.push_back(nums[i]);
            }
            else {
                equal_element.push_back(nums[i]);
            }
        }

        vector<int> arr;
        int i = 0;

        while(i < less_element.size()) {
            arr.push_back(less_element[i]);
            i++;
        }

        i = 0;
        while(i < equal_element.size()) {
            arr.push_back(equal_element[i]);
            i++;
        }

        i = 0;
        while(i < greater_element.size()) {
            arr.push_back(greater_element[i]);
            i++;
        }

        return arr;
    }
};