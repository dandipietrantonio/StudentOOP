#include <iostream>
#include <string>
#include <vector>
#include "weather.h"

using namespace std;

//Constructor for Weather Class
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

//Output for Weather Class
ostream& operator<<(ostream& os, const Weather& w){
    os << w.get_name() << " rating: " << w.get_rating() << "; " << w.my_loc << endl;
    for (WReading wreading: w.wreadings) { 
        os << wreading << endl;
    }
    return os;
}

//Output for GPS Class
ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
    return os;
}

//Output for WReading Class
ostream& operator<<(ostream& os, const WReading& wr){
    os << wr.date << " " << wr.temperature << " " << wr.humidity << " " << wr.windspeed;
    return os;
}

//Methods for Weather Class
    string Weather::get_name() const {
        return station_nm;
    }

    void Weather::set_rating(int new_rating) {
        rating = new_rating;
    }

    int Weather::get_rating() const {
        return rating;
    }

    void Weather::add_reading(WReading wr) {
        wreadings.push_back(wr);
    }
