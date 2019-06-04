#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n) {
    ++n;
}


void inc_with_pointer(int* iptr) {
    (*iptr)++;
}


void inc_with_reference(int& n) {
    ++n;
}


Thing** create_array_of_things(int n) {
    Thing** things = new Thing* [n];
    for (int i=0; i < n; ++i) {
        Thing* thing_ptr = new Thing(i);
        things[i] = thing_ptr;
    }
    return things;
}

void print_all_things(Thing** things, int n) {
    for (int i=0; i<n; ++i) {
        cout << things[i]->val;
    cout << endl;
    }
}

void double_all_things(Thing** things, int n) {
    for (int i=0; i<n; ++i) {
        things[i]->val *= 2;
    }
}

void delete_all_things(Thing** things, int n) {
    for (int i=0; i<n; ++i) {
        delete things[i];
    }
    delete[] things;
}


void assignTA(Student* s, Student* ta) {
    s->ta = ta;
}

void printTAs(vector<Student*>& students) {
    for (Student* s : students) {
        if (s->ta == nullptr) {
            cout << s->name << " has no TA\n";
        }
        else {
            cout << s->name << " has TA " << s->ta->name << endl;
        }
    }
}
