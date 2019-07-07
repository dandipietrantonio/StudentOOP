
#include <iostream>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

const double PI = 3.14159265358979323846;

/*
 * An exception to throw when we get a number too big.
 * */
class NoNegative : public exception {
public:
    NoNegative(int n)
        : badnum(n)
    {
    }

    const char* what() const throw() {
        string s = "Argument canot be negative: " + to_string(badnum);
        return s.c_str();
    }

private:
    int badnum;
};

class Sin {
    public:
        double operator()(double r) {
            return sin(r);
        }
};

class Cos {
    public:
        double operator()(double r) {
            return cos(r);
        }
};
void print_cos() {
    Cos ret = Cos();
    cout << "Cosine of 1 is " << ret(1) << endl;
}

class Tan {
    public:
        double operator()(double r) {
            return tan(r);
        }
};

void print_tan() {
    Tan ret = Tan();
    cout << "Tangent of 1 is " << ret(1) << endl;
}

class Secant {
    public:
        double operator()(double r) {
            return (1/cos(r));
        }
};
void print_secant() {
    Secant ret = Secant();
    cout << "Secant of 1 is " << ret(1) << endl;
}

double cube_func(double d, function<double(double)> f) {
    return f(d) * f(d) * f(d);
}

double half_func(double d, function<double(double)> f) {
    return f(d)/2;
}

double doubled_func(double d, function<double(double)> f) {
    return 2*f(d);
}

class NegativeNumber : public exception {
    public:
        NegativeNumber(int n) : arg(n) {}
        const char* what() const throw() {
            return "Cannot use a negative number for the fibonacci sequence!";
        }
    private:
        int arg;
};

class Fib {
    public:
        Fib() {
            for (int i = 0; i <= MAX_FIB; i++){
                fib_array[i] = NOT_CALCED;
            }
         }

        long long int operator()(long long int n) {
            if (n < 0) throw (NegativeNumber(n));
            else if (n <= 1) {
                fib_array[n+1] = 1;
                return fib_array[n+1];
            }
            else {
                fib_array[n+1] = operator()(n - 1) + operator()(n - 2);
                return fib_array[n+1];
            }
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    private:
        int* fib_array = new int[MAX_FIB];
};

double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}


int main() {
    const long long int FIB_NUM = -46;
    print_cos();
    print_tan();
    print_secant();

    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    Fib fib = Fib();
    try {
        long long int f = fib(FIB_NUM);
        cout << "fib(" << FIB_NUM << ") == " << f << endl;
    }
    catch (NegativeNumber& e) {
        cerr << "Got a negative argument for fib: " << e.what() << endl;
    }
    cout << "Fib 19 = " << fib(18) << endl;;

    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;
    d = cube_func(1, [](double arg) { return cos(arg);});
    cout << "Cube of cos 1 = " << d << endl;
    d = half_func(1, [](double arg) { return cos(arg);});
    cout << "Half of cos 1 = " << d << endl;
    d = doubled_func(1, [](double arg) { return cos(arg);});
    cout << "Two times cos 1 = " << d << endl;
}
