#ifndef KURS_H
#define KURS_H
#include "Student.h"
#include "vector"

class Kurs
{
private:
    string kursName;
    vector<Student*> teilnehmer;
public:
    Kurs();
    Kurs(string);

    void anlegen();
    void printKurs() const;
    void addStudent(Student& student);

    string getKursname() const;
};

#endif // KURS_H
