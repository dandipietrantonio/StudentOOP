#include <iostream>
#include <string>
#include <vector>
#include "weather.h"

using namespace std;

//Weather Class
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

//GPS Class
    //Output for GPS Class
    ostream& operator<<(ostream& os, const GPS& gps){
        os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
        return os;
    }

//WReading Class
    //Output for WReading Class
    ostream& operator<<(ostream& os, const WReading& wr){
        os << wr.date << " " << wr.temperature << " " << wr.humidity << " " << wr.windspeed;
        return os;
    }

//Image Class:
    //Constructor for Image Class
    Image::Image(int w, int h, std::string flnm)
        : width(w), height(h), filename(flnm)
    {
        image_buf = new char[image_sz()];
    }
    //Copy Constructor for Image Class:
    Image::Image(const Image& img2) {
        copy_fields(img2);
    }

    //Deconstructor for Image Class
    Image::~Image() {
        if (image_buf != nullptr) {delete image_buf;}
    }

    //Assignment Overload for Image Class
    Image& Image::operator=(const Image& img2) {
        if (image_buf != nullptr) {delete image_buf;}
        copy_fields(img2);
        return *this;
    }

    //Width * Height for Image Class
    int Image::image_sz() const {
        return width * height;
    }

    //Copying Fields Method for Image Class
    void Image::copy_fields(const Image& img2) {
        height = img2.height;
        width = img2.width;
        filename = img2.filename;
        image_buf = new char[img2.image_sz()];
        for (int i = 0; i < img2.image_sz(); ++i) {
            image_buf[i] = img2.image_buf[i];
        }
    }

    //Display Method for Image Class
    string Image::display(string s) {
        return "Displaying image " + s;
    }