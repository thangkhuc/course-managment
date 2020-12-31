#ifndef KURS_H
#define KURS_H
#include "Student.h"
#include "vector"


class Kurs{
public:
    Kurs();
    ~Kurs();

    string kursName;
    vector<Student*> teilnehmer;

    void anlegen();
    void printKurs();
    void addStudent(Student& student);
};

extern vector<Kurs*> kursArray;
Kurs* kursSuchen();
#endif // KURS_H
