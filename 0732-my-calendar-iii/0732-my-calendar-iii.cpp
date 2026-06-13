class MyCalendarThree {
public:
    map<int , int> mpp;

    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {   
        mpp[startTime] += 1;
        mpp[endTime] -= 1;

        int cnt = 0;
        int ans = 0;

        for(auto it : mpp) {
            cnt += it.second;
            ans = max(ans , cnt);
        }

        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */