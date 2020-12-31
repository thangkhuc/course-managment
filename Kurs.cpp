#include "Kurs.h"

Kurs :: Kurs(){
     kursName = "";
}

void Kurs :: printKurs(){
    if (teilnehmer.size() == 0)
        cout << "Es gibt keinen Studenten in diesem Kurs." << endl;
    else{
        cout.width(28);
        cout << right <<"Kurs: " << kursName << "\n" << endl;
        cout.width(23);
        cout << right << "Studentenname";
        cout.width(23);
        cout <<right << "Martikelnummer\n" << endl;
        for (unsigned int i = 0; i < teilnehmer.size() ; ++i ) {
            cout.width(15);
            cout << right << teilnehmer[i]->getVorname() << " ";
            cout << teilnehmer[i]->getNachname();
            cout.width(20);
            cout << right << teilnehmer[i]->getMartikelnummer() << endl;
        }
    }
}

Kurs* kursSuchen(){ // return NULL wenn es keinen solchen Kurs gibt
    string _kursName;

    cout << "Geben Sie die Kursname ein: " << endl;
    fflush(stdin);
    getline(cin, _kursName);

    for (unsigned int i = 0; i < kursArray.size() ; ++i ) {
        if (_kursName == kursArray[i]->kursName)
            return kursArray[i];
    }
    cout << "Es gibt diesen Kurs nicht" << endl;
    return NULL;
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

Kurs :: ~Kurs(){}
