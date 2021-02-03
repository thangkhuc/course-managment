#include "Kurs.h"

Kurs :: Kurs() : kursName(""), teilnehmerTop(NULL), teilnehmerEnde(NULL) {}

Kurs :: Kurs(string name) : kursName(name), teilnehmerTop(NULL), teilnehmerEnde(NULL) {}

void Kurs :: printKurs() const
{
    if (teilnehmerTop == NULL)
        cout << "Es gibt keinen Studenten in diesem Kurs." << endl;
    else{
        cout.width(28);
        cout << right <<"Kurs: " << kursName << "\n" << endl;
        cout << right << "Vorname\t\t\t|Nachname\t\t|Matrikelnummer" << endl;
        cout << "=============================================================" << endl;
        Student* p = teilnehmerTop;
        while(p != NULL) {
            cout.width(25);
            cout << left << p->getVorname() << " ";
            cout.width(25);
            cout << left << p->getNachname();
            cout << p->getMartikelnummer() << endl;
            p = p->getNextStudent();
        }
    }
}

void Kurs :: anlegen(){
    string kursname;
    cout << "Kursname: " << endl;
    fflush(stdin);
    getline(cin, kursname);
    kursName = kursname;
}

void Kurs :: addStudent(Student* student){
    Student* p = new Student(student);
    if (teilnehmerEnde == NULL)
        teilnehmerEnde = p;

    if (teilnehmerTop != NULL)
        teilnehmerTop->setPreviousStudent(p);
    p->setNextStudent(teilnehmerTop);
    teilnehmerTop = p;
    studentSort();
}

void Kurs :: studentSort()
{
   Student* p = NULL;
   Student* q = NULL;
   Student* speicherP = NULL;
   p = teilnehmerTop->getNextStudent();
   q = teilnehmerTop;

   while (p != NULL) {
       q = p->getPreviousStudent();
       speicherP = p->getNextStudent();
       while (q != NULL && q->getNachname() > p->getNachname()) {
            if (q != teilnehmerTop)
                q->getPreviousStudent()->setNextStudent(p);
            else
                teilnehmerTop = p;

            if (p != teilnehmerEnde)
                p->getNextStudent()->setPreviousStudent(q);
            else
                teilnehmerEnde = q;

            p->setPreviousStudent(q->getPreviousStudent());
            q->setNextStudent(p->getNextStudent());

            p->setNextStudent(q);
            q->setPreviousStudent(p);

            q = p->getPreviousStudent();
       }
       p = speicherP;
   }
}

void Kurs :: removeStudent(int matrikelnummer)
{
    Student* p = teilnehmerTop;
    while(p != NULL){
        if (p->getMartikelnummer() == matrikelnummer) {
            if (p == teilnehmerEnde) {
                teilnehmerEnde = p->getPreviousStudent();
                p->getPreviousStudent()->setNextStudent(NULL);
            }
            else if (p == teilnehmerTop) {
                teilnehmerTop = p->getNextStudent();
                p->getNextStudent()->setPreviousStudent(NULL);
            }
            else {
                p->getPreviousStudent()->setNextStudent(p->getNextStudent());
                if (p->getNextStudent() != NULL)
                    p->getNextStudent()->setPreviousStudent(p->getPreviousStudent());
            }

            cout << "Student " << p->getVorname() << " " << p->getNachname() << " wird geloescht!" << endl;
            delete p;
            break;
        }
    }
}

string Kurs :: getKursname() const {return kursName;}
