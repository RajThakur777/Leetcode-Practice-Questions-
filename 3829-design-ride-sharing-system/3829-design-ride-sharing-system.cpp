class RideSharingSystem {
public:
    vector<int> rider;
    vector<int> driver;
    set<int> st;
    
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(!rider.empty() && !driver.empty()) {
            int v1 = rider[0];
            int v2 = driver[0];

            st.insert(v1);

            auto it = find(rider.begin() , rider.end() , v1);

            auto it2 = find(driver.begin() , driver.end() , v2);

            if(it != rider.end()) {
                 rider.erase(it);
            }

            if(it2 !=  driver.end()) {
                 driver.erase(it2);
            }

            return {v2 , v1};
        }
        else {
            return {-1 , -1};
        }
    }
    
    void cancelRider(int riderId) {
        if(st.find(riderId) != st.end()) {
            return;
        }

        st.erase(riderId);
        auto it = find(rider.begin() , rider.end() , riderId);

        if(it != rider.end()) {
            rider.erase(it);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */