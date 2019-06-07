#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;

string get_file_name() { 
    string filenm;
    cout << "Input the name of the new readings file:\n";
    cin >> filenm;
    return filenm;
}
void get_wreadings(string filenm, Weather& w) {
    ifstream rfile(filenm);
    if (!rfile) {
        cout << "Could not read input file: " << filenm << endl;
        get_wreadings(get_file_name(), w);
    }
    else {
        int m, d, y;
        double temp, hum, ws;
        while (rfile >> m >> d >> y >> temp >> hum >> ws) {
            WReading wr = WReading(Date(d, m, y), temp, hum, ws);
            w.add_reading(wr);
        }
        rfile.close();
    }
}


int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));
    string filenm = get_file_name();
    get_wreadings(filenm, irkutsk);
    cout << irkutsk << endl;
}
