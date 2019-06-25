#include <iostream>
#include "vector.h"

using namespace std;

//Prints the Vector Element by Element
    void print_vector(const MyVec& v) {
        for (int i=0; i < v.size(); ++i) {
            cout << v[i] << ' ';
        }
    }

//Default Constructor for MyVec
    MyVec::MyVec() {
        sz = 0;
        capacity = 1;
        data = new int[capacity];
    }

//Size & Integer Constructor for MyVec
    MyVec::MyVec(int size, int val){
        sz = size;
        capacity = sz * 2;
        data = new int[capacity];
        for (int i=0; i < sz; i++) {
            data[i] = val;
        }
    }

//Copy Constructor for MyVec
    MyVec::MyVec(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[capacity];
        for (int i=0; i < capacity; ++i) {
            data[i] = v2.data[i];
        }
    }

//Destructor for MyVec
    MyVec::~MyVec() {
        delete[] data;
    }

//Operator Overload: =
    MyVec& MyVec::operator=(const MyVec& v2) {
        delete[] data;
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[v2.capacity];
        for (int i=0; i < v2.capacity; ++i) {
            data[i] = v2.data[i];
        }
        return *this;

    }

//Operator Overload: ==
    bool operator==(MyVec& v1, MyVec& v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        else {
            for (int i=0; i < v1.size(); ++i) {
                if (v1[i] != v2[i]) {
                    return false;
                }
            }
            return true;
        }
    }

//Pushes Element to the Back of the Vector
    void MyVec::push_back(int val) {
        if (sz == capacity) {
            int* old_data = data;
            capacity *= 2;
            data = new int[capacity];
            for (int i = 0; i < sz; ++i) {
                data[i] = old_data[i];
            }
            delete[] old_data;
        }
        data[sz++] = val;
    }

//Operator Overload: []
    int MyVec::operator[](int i) const {
        return data[i];
    }

//Operator Overload: [] by Reference
    int& MyVec::operator[](int i) {
        return data[i];
    }


//Iterator for MyVec:
    MyVec::Iterator MyVec::begin() const {
    return MyVec::Iterator(data);
    }

    MyVec::Iterator MyVec::end() const {
        return MyVec::Iterator(data + size());
    }