#ifndef KURS_H
#define KURS_H
#include "Student.h"
#include "vector"

class Kurs
{
private:
    string kursName;
    Student* teilnehmerTop;
    Student* teilnehmerEnde;
public:
    Kurs();
    Kurs(string);

    void anlegen();
    void printKurs() const;
    void addStudent(Student*);
    void studentSort();
    void removeStudent(int);
    string getKursname() const;

    friend class Kursverwaltung;
};

#endif // KURS_H
