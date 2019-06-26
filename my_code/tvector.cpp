#include <iostream>
#include "tvector.h"

using namespace std;

//Prints the Vector Element by Element
    template <typename T>
    void print_vector(const MyVec<T>& v) {
        for (int i=0; i < v.size(); ++i) {
            cout << v[i] << ' ';
        }
    }

//Copy Constructor for MyVec
    template <typename T>
    MyVec<T>::MyVec(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[capacity];
        for (int i=0; i < capacity; ++i) {
            data[i] = v2.data[i];
        }
    }

//Destructor for MyVec
    template <typename T>
    MyVec<T>::~MyVec() {
        delete[] data;
    }

//Operator Overload: =
    template <typename T>
    MyVec<T>& MyVec<T>::operator=(const MyVec& v2) {
        delete[] data;
        sz = v2.sz;
        capacity = v2.capacity;
        data = new T[v2.capacity];
        for (int i=0; i < v2.capacity; ++i) {
            data[i] = v2.data[i];
        }
        return *this;

    }

//Operator Overload: ==
    template <typename T>
    bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
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
    template <typename T>
    void MyVec<T>::push_back(T val) {
        if (sz == capacity) {
            T* old_data = data;
            capacity *= 2;
            data = new T[capacity];
            for (int i = 0; i < sz; ++i) {
                data[i] = old_data[i];
            }
            delete[] old_data;
        }
        data[sz++] = val;
    }

//Operator Overload: []
    template <typename T>
    T MyVec<T>::operator[](T i) const {
        return data[i];
    }

//Operator Overload: [] by Reference
    template <typename T>
    T& MyVec<T>::operator[](T i) {
        return data[i];
    }


// //Iterator for MyVec:
//     template <typename T>
//     MyVec::Iterator MyVec::begin() const {
//     return MyVec::Iterator(data);
//     }

//     tempalte <typename T>
//     MyVec::Iterator MyVec::end() const {
//         return MyVec::Iterator(data + size());
//     }