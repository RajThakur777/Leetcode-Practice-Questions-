class UndergroundSystem {
public:
    map<int , pair<string , int>> mpp;
    map<pair<string , string> , pair<int , int>> mpp2;
    UndergroundSystem() { 
    }
    
    void checkIn(int id, string stationName, int t) { 
        mpp[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = mpp[id];
        string st = it.first;
        int time = it.second;

        int final_time = t - time;
        pair<string , string> p = {st , stationName};

        if(mpp2.find(p) != mpp2.end()) {
            int v1 = mpp2[p].first;
            int cnt = mpp2[p].second;
            mpp2[p] = {final_time + v1 , cnt+1};
        }
        else {
            mpp2[p] = {final_time , 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it = mpp2[{startStation , endStation}];

        double sum = it.first;
        double cnt = it.second;

        double avg = (sum) / (cnt);

        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */