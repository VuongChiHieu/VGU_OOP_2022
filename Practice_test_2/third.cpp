#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

// class data type for center point
class Point {
    public:
        double x;
        double y;
        Point(){}
        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }
};

class TwoDShape {
    public:
        Point center_point;
        TwoDShape(){}
        TwoDShape(Point point) {
            this->center_point.x = point.x;
            this->center_point.y = point.y;
        }
        void print(){
            cout<< "Center point: (" << center_point.x << ", " << center_point.y << ")" << endl;
        }
        double compute_distance(const TwoDShape &shape) {
            return sqrt(pow(center_point.x - shape.center_point.x, 2) + pow(center_point.y - shape.center_point.y, 2));
        }
        //virtual function so derived functions will be called instead
        //print out random stuff to debug
        //if this is printed out, smt is wrong
        virtual double perimeter(){
            cout << "based" << endl;
            return 0.00;
        }
        virtual double area(){
            cout << "based" << endl;
            return 0.00;
        };
};

class Circle: public TwoDShape {
    public:
        double radius;
        Circle(Point point, double radius) : TwoDShape(point) {
            this->radius = radius;
        }
        void print() {
            cout<< "Center point: (" << center_point.x << ", " << center_point.y << ")" << endl;
            cout<< "Radius: " << radius << endl;
        }
        double perimeter() {
            return 2 * 3.14 * radius;
        }
        double area() {
            return 3.14 * pow(radius,2);
        }
};

class Rectangle: public TwoDShape {
    public:
        double width;
        double height;
        Rectangle(Point point, double width, double height) : TwoDShape(point) {
            this->width = width;
            this->height = height;
        }
        void print() {
            cout<< "Center point: (" << center_point.x << ", " << center_point.y << ")" << endl;
            cout<< "Width: " << width << endl;
            cout<< "Height: " << height << endl;
        }
        double perimeter() {
            return 2 * (width + height);
        }
        double area() {
            return width*height;
        }
};

class Square: public TwoDShape {
    public:
        double side;
        Square(Point point, double side) : TwoDShape(point) {
            this->side = side;
        }
        void print() {
            cout<< "Center point: (" << center_point.x << ", " << center_point.y << ")" << endl;
            cout<< "Side: " << side << endl;
        }
        double perimeter() {
            return 4 * side;
        }
        double area() {
            return pow(side,2);
        }
};

void compute_total_area (vector<TwoDShape*> vect) {
    double area;
    for (TwoDShape* shape : vect) {
        area += shape->area();
    }
    cout << "The total area of all shapes in the vector is: " << area << endl;
}

void print_perti_desc (vector<TwoDShape*> vect) {
    vector<double> peri;
    for (TwoDShape* shape : vect) {
        peri.push_back(shape->perimeter());
    }
    sort(peri.begin(), peri.end(), greater<double>());
    cout << "The perimeter for each shapes in decreased order is: ";
    for (double perimeter : peri)
        cout << perimeter << " ";
    cout << endl;
}

// for demonstration: object slicing
void compute_total_area (vector<TwoDShape> vect) {
    double area;
    for (TwoDShape shape : vect) {
        area += shape.area();
    }
    cout << "The total area of all shapes in the vector is: " << area << endl;
}

int main () {
    Circle circle = Circle(Point(1,2), 3);
    TwoDShape *ptr1 = &circle;

    Rectangle rectangle = Rectangle(Point(3,4), 5, 6);
    TwoDShape *ptr2 = &rectangle;

    Square square = Square(Point(5,6), 4);
    TwoDShape *ptr3 = &square;

    //create vector of based class pointer
    vector<TwoDShape *> vect;
    vect.push_back(ptr1);
    vect.push_back(ptr2);
    vect.push_back(ptr3);

    print_perti_desc(vect);
    compute_total_area(vect);

    //test individual derived class functions
    cout << rectangle.area() << endl;
    cout << rectangle.perimeter() << endl;

    //create vector of based class
    //this code block is to show case object slicing
    // NOT THE SOLUTION
    vector<TwoDShape> based_vect;
    Circle circle = Circle(Point(1,2), 3);
    Rectangle rectangle = Rectangle(Point(3,4), 5, 6);
    Square square = Square(Point(5,6), 4);
    based_vect.push_back(circle);
    based_vect.push_back(rectangle);
    based_vect.push_back(square);
    compute_total_area(based_vect);

    return 0;
}
