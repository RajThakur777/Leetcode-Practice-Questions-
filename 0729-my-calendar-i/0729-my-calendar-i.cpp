class MyCalendar {
public:
    map<int , int> mpp;

    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        mpp[startTime] += 1;
        mpp[endTime] -= 1;

        int cnt = 0;
        for(auto it : mpp) {
            cnt += it.second;

            if(cnt > 1) {
                mpp[startTime] -= 1;
                mpp[endTime] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */