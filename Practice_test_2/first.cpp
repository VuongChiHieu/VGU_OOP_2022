#include <iostream>
#include<tuple>
using namespace std;

class Employee {
    private:
        int employee_id;
        string employee_name;
        string gender;
        int department_id;
    public:
        Employee(){}
        Employee(int e_id, string e_name, string e_gender, int d_id) {
            this->employee_id = e_id;
            this->employee_name = e_name;
            this->gender = e_gender;
            this->department_id = d_id;
        }
        void set_info(int e_id, string e_name, string e_gender, int d_id) {
            this->employee_id = e_id;
            this->employee_name = e_name;
            this->gender = e_gender;
            this->department_id = d_id;
        }

        // You can return all attributes at once using tuple
        // tuple <int, string, string, int> get_info() {
        //     tuple <int, string, string, int> info = make_tuple(this->employee_id, this->employee_name, this->gender, this->department_id);
        //     return info;
        // }

        int get_employee_id() {
            return this->employee_id;
        }
        string get_employee_name(){
            return this->employee_name;
        }
        string get_gender() {
            return this->gender;
        }
        int get_department_id(){
            return this->department_id;
        }
        
        void print_info() {
            cout << "Employee's name: " << this->employee_name << endl;
            cout << "Employee's id: " << this->employee_id << endl;
            cout << "Employee's gender: " << this->gender << endl;
            cout << "Employee's department: " << this->department_id << endl;
        }
};

class Manager: public Employee {
    public:
        Manager (int e_id, string e_name, string e_gender, int d_id): Employee(e_id, e_name, e_gender, d_id) {}
};

int main () {
    Employee one = Employee(1, "Hieu", "male", 1);
    one.set_info(2, "Vy", "female", 2);
    Manager two = Manager(2, "Vinh", "male", 1);
    one.print_info();
    two.print_info();
}
