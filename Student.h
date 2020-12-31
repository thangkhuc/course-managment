#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student{
public:

    Student();
    Student(Student& student);
    ~Student();

    void martikelnummerGenerator();
    void setMartikelnummer(int martikelnummer);
    void setVorname(string _vorname);
    void setNachname(string _nachname);
    void setNaechsteStudent(Student* _student);
    int getMartikelnummer();
    string getVorname();
    string getNachname();
    Student* getNaechsteStudent();
    void printStudent();

private:
    string vorname;
    string nachname;
    int martikelnummer;
    Student* naechsteStudent;
};

Student* findStudent();
void studentLoeschen();
void eintragen();
int typUmwandlung(string _martikelnummer);
void testausgeben(Student student);
#endif // STUDENT_H
