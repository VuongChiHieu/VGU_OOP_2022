#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        double imagine;
    public:
        Complex(){}
        Complex(double real, double imagine) {
            this->real = real;
            this->imagine = imagine;
        }
        Complex(const Complex &complex_obj) {
            imagine = complex_obj.imagine;
            real = complex_obj.real;
        }
        Complex operator+(const Complex &complex_obj) {
            Complex complex_num;
            complex_num.real = real + complex_obj.real;
            complex_num.imagine = imagine + complex_obj.imagine;
            return complex_num;
        }
        bool operator==(const Complex &complex_obj) {
            return (real == complex_obj.real) && (imagine == complex_obj.imagine);
        }
        void operator=(const Complex &complex_obj) {
            imagine = complex_obj.imagine;
            real = complex_obj.real;
        }

        //extra function to show result easier
        //print in format: real +/- imagine i (example: 6 - 9i)
        void print_complex() {
            cout << noshowpos << this->real;
            cout << showpos << this->imagine << "i" << endl;
        }
};

int main () {
    Complex n1 = Complex(3,-2);
    Complex n2 = Complex(6,9);

    //initialized new object with copy constructor
    Complex n3 = Complex(n2);
    //print n3 to check result
    n3.print_complex();

    //example for operator +
    Complex sum = n1+n2;
    sum.print_complex();

    //example for operator =
    Complex n4 = n1;
    n4.print_complex();

    //example for operator ==
    bool equal = n2==n3;
    cout << equal << endl; 

    return 0;
}
