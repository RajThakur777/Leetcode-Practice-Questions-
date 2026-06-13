class MyCalendarTwo {
public:
    map<int , int> mpp;

    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) { 
        mpp[startTime] += 1;
        mpp[endTime] -= 1;

        int cnt = 0;
        for(auto it : mpp) {
            cnt += it.second;

            if(cnt >= 3) {
                mpp[startTime] -= 1;
                mpp[endTime] += 1;
                return false;
            }
        }
        return true;  
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */