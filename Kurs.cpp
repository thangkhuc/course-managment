#include "Kurs.h"

Kurs :: Kurs()
{
    kursName = "";
}

Kurs :: Kurs(string name) : kursName(name) {}

void Kurs :: printKurs() const
{
    if (teilnehmer.size() == 0)
        cout << "Es gibt keinen Studenten in diesem Kurs." << endl;
    else{
        cout.width(28);
        cout << right <<"Kurs: " << kursName << "\n" << endl;
        cout << right << "Vorname\t\t\t|Nachname\t\t|Matrikelnummer" << endl;
        cout << "=============================================================" << endl;
        for (unsigned int i = 0; i < teilnehmer.size() ; ++i ) {
            cout.width(25);
            cout << left << teilnehmer[i]->getVorname() << " ";
            cout.width(25);
            cout << left << teilnehmer[i]->getNachname();
            cout << teilnehmer[i]->getMartikelnummer() << endl;
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

void Kurs :: addStudent(Student &student){
    teilnehmer.push_back(&student);
}

string Kurs :: getKursname() const {return kursName;}
