#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << roll << "\t" << name << "\t" << marks << endl;
    }
};

int main() {
    Student s;
    fstream file;
    int choice;

    do {
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            file.open("students.dat", ios::out | ios::app);
            s.input();
            file.write((char*)&s, sizeof(s));
            file.close();
        } 
        else if (choice == 2) {
            file.open("students.dat", ios::in);
            cout << "\nRoll\tName\tMarks\n";
            while (file.read((char*)&s, sizeof(s))) {
                s.display();
            }
            file.close();
        }
    } while (choice != 3);

    return 0;
}
