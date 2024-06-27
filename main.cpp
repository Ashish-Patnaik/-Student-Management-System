#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

void addStudent(vector<Student>&students){
    Student newStudent;
    cout<< "Enter Student ID: ";
    cin >> newStudent.id;
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin,newStudent.name);
    cout<< "Enter Student age: ";
    cin>> newStudent.age;
    cout << "Enter Student Course: ";
    cin.ignore();
    getline(cin, newStudent.course);
    
    students.push_back(newStudent);
    cout<<"Student added succesfully"<<endl;
}

void displayStudent(const vector<Student>&students){
    if(students.empty()){
        cout<<"No students to display"<<endl;
        return ;
    }
    cout<<"Student records"<<endl;
    for(const auto& student : students){
        cout<<" ID: "<<student.id<<"\n"<<" Student Name: "<<student.name<<"\n"<<" Age: "<<student.age<<"\n"<<" Course: "<<student.course<<"\n"<<endl;
    }
}
 void deleteStudent(vector<Student>&students){
     int id;
     cout<<"Enter Student ID to delete: ";
     cin>>id;
     
     auto it = find_if(students.begin(),students.end(),[id](const Student& student){
         return student.id==id;
     });
     if (it != students.end()) {
        students.erase(it);
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
 }
int main(){
    vector<Student> students;
    int choice;
    while(true){
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                addStudent(students);
                break; 
            case 2:
                displayStudent(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    }
    return 0;
}