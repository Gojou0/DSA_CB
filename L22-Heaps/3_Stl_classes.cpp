#include<iostream>
#include<queue> // heap is priority queue inside STL
#include<functional>
using namespace std;

class Student {
    public:
    int age;
    int marks;
    string name;

    Student(int a, int m, string x){
        age = a;
        marks = m;
        name = x;
    }

    void print(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl << endl;
    }
};

class myclass {
    public:
    bool operator() (Student a, Student b) {
        return a.marks > b.marks;
    }
};

int main(){
    // priority_queue<int> h;  // Max heap (default)

    priority_queue<Student, vector<Student>, myclass> h;

    Student a(21, 88, "Dev");
    Student b(20, 89, "Daksh");
    Student c(19, 100, "Pankaj");

    h.push(a);
    h.push(b);
    h.push(c);
    

    while (!h.empty()){
        Student x = h.top();
        x.print();
        
        h.pop();
    }
}