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
    Student(string, string);

    friend class Kursverwaltung;

    void printStudent() const;
    void eintragen();
    void remove();

    void setMartikelnummer(int martikelnummer);
    void setVorname(string _vorname);
    void setNachname(string _nachname);
    void setNaechsteStudent(Student* _student);
    string   getVorname() const;
    string   getNachname() const;
    Student* getNaechsteStudent() const;
    Student* getTop() const;
    int      getMartikelnummer() const;

private:
    string vorname;
    string nachname;
    int martikelnummer;
    Student* naechsteStudent;
    static int martikelnummerArray;
    static Student* top;
};

int typUmwandlung(string _martikelnummer);
#endif // STUDENT_H
