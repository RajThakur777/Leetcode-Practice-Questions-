class Solution {
public:
   map<int , set<int>> mpp;

   bool isPrime(int x) {
    if(x < 2) {
        return false;
      }

    for(int i=2; i*i<=x; i++) {
        if(x % i == 0) {
            return false;
        }
      }
      return true;
    }

   void solve() {
    for(int i=1; i<=1000; i++) {
        for(int j=1; j*j<=i; j++) {
            if((i % j == 0)) {
                mpp[i].insert(j);

                if((j != (i / j))) {
                       mpp[i].insert((i / j));
                    }
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size(); 

        solve();  

        // for(auto it : mpp) {
        //     cout<<it.first<<" ";
        //     for(auto t : it.second) {
        //         cout<<t<<" ";
        //     }
        //     cout<<endl;
        // }

        set<int> ans;

        for(int i=0; i<n; i++) {
            int ele = nums[i];

            set<int> st = mpp[ele];

            for(auto t : st) {
                if(isPrime(t)) {
                    ans.insert(t);
                }
            }
        }
        return ans.size();
    }
};