// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-underground-system/
// Date: 6th Nov, 2022
// Tags: hash, hash-table

class UndergroundSystem {
public:
    unordered_map<string, vector<int>> completedTrips;
    unordered_map<int, pair<string, int>> ongoingTrips;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        ongoingTrips[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto trip = ongoingTrips[id];
        ongoingTrips.erase(id);
        completedTrips[ trip.first + ";"  + stationName ].push_back(t-trip.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto tripTimes = completedTrips[startStation + ";"  + endStation];
        double time = 0;
        for(auto t: tripTimes)
        {
            time+=t;
        }
        return time/tripTimes.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
