#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string gender;

public:
    Person(string _name, int _age, string _gender) : name(_name), age(_age), gender(_gender) {}
    void showPersonData();
};

void Person::showPersonData() {
    cout << "My name is: " << name << endl;
    cout << "My age is: " << age << endl;
    cout << "My gender is: " << gender << endl;
}

class Student : public Person {
private:
    string facultad;
    string code;
    int scores[4] = { 0 };
    float average = 0;

public:
    Student(string _name, int _age, string _gender, string _facultad, string _code)
        : Person(_name, _age, _gender), facultad(_facultad), code(_code) {}
    void ShowStudentData();
    void randomScores();
    void showScores();
};

void Student::ShowStudentData() {
    cout << "Faculty: " << facultad << endl;
    cout << "Student code: " << code << endl;
}

void Student::randomScores() {
    size_t totalSize = sizeof(scores);
    int d = static_cast<int>(totalSize / sizeof(scores[0]));

    for (int i = 0; i < d; i++) scores[i] = 1 + rand() % 20;
}

void Student::showScores() {
    size_t totalSize = sizeof(scores);
    int d = static_cast<int>(totalSize / sizeof(scores[0]));

    for (int i = 0; i < d; i++) cout << "Score [" << i + 1 << "]" << scores[i] << endl;
}

// Variables Globales //
Student aula[3] = {
        Student("John", 20, "Male", "Computer Science", "12345"),
        Student("Alice", 22, "Female", "Engineering", "67890"),
        Student("Bob", 19, "Male", "Biology", "54321")
};

void mostrarAula();

int main() {
    srand(time(NULL));
    mostrarAula();


    return 0;
}

void mostrarAula() {
    // Mostrar la información de los estudiantes
    for (int i = 0; i < 3; i++) {
        aula[i].ShowStudentData();
        aula[i].randomScores();
        aula[i].showScores();
        cout << endl;
    }
}