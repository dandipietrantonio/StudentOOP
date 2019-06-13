#include <iostream>
#include <string>
#include <vector>
#include "weather.h"

using namespace std;


Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
    copy_fields(img2);
}

Image::~Image() {
    if (image_buf != nullptr) {delete image_buf;}
}

Image& Image::operator=(const Image& img2) {
    if (image_buf != nullptr) {delete image_buf;}
    copy_fields(img2);
    return *this;
 }

int Image::image_sz() const {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
    height = img2.height;
    width = img2.width;
    filename = img2.filename;
    image_buf = new char[img2.image_sz()];
    for (int i = 0; i < img2.image_sz(); ++i) {
        image_buf[i] = img2.image_buf[i];
    }
}


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}

//Constructor for Weather Class
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}

//Output for Weather Class COMMENTED OUT FOR TESTING
// ostream& operator<<(ostream& os, const Weather& w){
//     os << w.get_name() << " rating: " << w.get_rating() << "; " << w.my_loc << endl;
//     for (WReading wreading: w.wreadings) { 
//         os << wreading << endl;
//     }
//     return os;
// }

//Output for GPS Class
ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
    return os;
}

//Output for WReading Class - TEMP. COMMENTED OUT FOR TESTING
// ostream& operator<<(ostream& os, const WReading& wr){
//     os << wr.date << " " << wr.temperature << " " << wr.humidity << " " << wr.windspeed;
//     return os;
// }

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
