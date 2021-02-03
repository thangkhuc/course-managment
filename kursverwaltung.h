#ifndef KURSVERWALTUNG_H
#define KURSVERWALTUNG_H
#include "Kurs.h"

class Kursverwaltung
{
private:
    static vector<Kurs*> kursArray;
public:
    ~Kursverwaltung();

    void menu();
    void kurs();
    void student();
    void testfall();
    Kurs* findKurs();
    Student* findStudent();
    void printStudent() const;
    void printKurs() const;
    void studentSortieren();
};

#endif // KURSVERWALTUNG_H
