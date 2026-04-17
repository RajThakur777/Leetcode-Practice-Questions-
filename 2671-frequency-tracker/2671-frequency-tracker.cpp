class FrequencyTracker {
public:
    unordered_map<int , int> mpp1; //ele -> freq;
    unordered_map<int , int> mpp2; //freq -> count;

    FrequencyTracker() {
    }
    
    void add(int number) {
        if(mpp1.find(number) == mpp1.end()) {
            mpp1[number]++;
            mpp2[1]++;
        }
        else {
            int freq = mpp1[number];
            mpp2[freq]--;
            if(mpp2[freq] == 0) {
                mpp2.erase(freq);
            }

            mpp1[number]++;
            mpp2[freq+1]++;
        }
    }
    
    void deleteOne(int number) {
        if(mpp1.find(number) != mpp1.end()) {
            int freq = mpp1[number];
            mpp1[number]--;
            if(mpp1[number] == 0) {
                mpp1.erase(number);
            }

            mpp2[freq]--;
            if(mpp2[freq] == 0) {
                mpp2.erase(freq);
            }

            mpp2[freq-1]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        if(mpp2.find(frequency) != mpp2.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */