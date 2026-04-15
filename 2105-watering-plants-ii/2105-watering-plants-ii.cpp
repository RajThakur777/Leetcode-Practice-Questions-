class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();

        int i = 0;
        int j = n-1;

        int ans = 0;
        int t1 = capacityA;
        int t2 = capacityB;

        while(i <= j) {
            if(i != j) {
                if(capacityA >= plants[i]) {
                    capacityA -= plants[i];
                    i++;
                }
                else {
                    ans++;
                    capacityA = (t1 - plants[i]);
                    i++;
                }

                if(capacityB >= plants[j]) {
                    capacityB -= plants[j];
                    j--;
                }
                else {
                    ans++;
                    capacityB = (t2 - plants[j]);
                    j--;
                }
            }
            else {
                if(capacityA >= capacityB) {
                    if(capacityA >= plants[i]) {
                        break;
                    }
                    else {
                        ans++;
                        break;
                    }
                }
                else {
                    if(capacityB >= plants[j]) {
                        break;
                    }
                    else {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};