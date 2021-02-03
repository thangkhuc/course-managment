#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Student{
private:
    string vorname;
    string nachname;
    int martikelnummer;
    Student* next;
    Student* previous;
    static int martikelnummerArray;
    static Student* top;
    static Student* ende;
public:
    Student();
    Student(Student& student);
    Student(string, string);
    Student(Student*); //kopierkonstruktur

    friend class Kursverwaltung;

    void printStudent() const;
    void eintragen();
    void remove();

    void setMartikelnummer(int martikelnummer);
    void setVorname(string _vorname);
    void setNachname(string _nachname);
    void setNextStudent(Student* _student);
    void setPreviousStudent(Student* student);
    string   getVorname() const;
    string   getNachname() const;
    Student* getNextStudent() const;
    Student* getTop() const;
    Student* getPreviousStudent() const;
    int      getMartikelnummer() const;
};
int typUmwandlung(string _martikelnummer);
#endif // STUDENT_H
