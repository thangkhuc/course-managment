#include "Student.h"

Student* Student :: top = NULL;
int Student :: martikelnummerArray = 100000;

Student::Student(){
    vorname = "";
    nachname = "";
    martikelnummer = martikelnummerArray;
    martikelnummerArray++;
}

Student :: Student(string vorname, string nachname) : vorname(vorname), nachname(nachname)
{
    martikelnummer = martikelnummerArray;
    martikelnummerArray++;
    this->setNaechsteStudent(top);
    top = this;
}

Student :: Student(Student& student){ //Kopierkonstruktor
    vorname = student.getVorname();
    nachname = student.getNachname();
    naechsteStudent = student.getNaechsteStudent();
    martikelnummer = student.getMartikelnummer();
}

void Student :: eintragen()
{
    string vorname, nachname;

    cout << "Geben Sie Ihre Nachname ein: " << endl;
    fflush(stdin);
    getline(cin, nachname);
    this->setNachname(nachname);

    cout << "Geben Sie Ihre Vorname ein: " << endl;
    fflush(stdin);
    getline(cin, vorname);
    this->setVorname(vorname);

    this->setNaechsteStudent(top);
    top = this;
    this->printStudent();
}

void Student :: remove()
{
    if (this != top) {
        Student* p_Vorne= top;

        while (p_Vorne->getNaechsteStudent() != this) // suche den Student am vorne
            p_Vorne = p_Vorne->getNaechsteStudent();

        p_Vorne->setNaechsteStudent(this->getNaechsteStudent());
    }
    else
        top = this->getNaechsteStudent();

    cout << "Student " << vorname << " " << nachname << " wird geloescht!" << endl;
    delete this;
}

void Student :: printStudent() const
{
    cout << "Name: " << vorname << " " << nachname << endl;
    cout << "Martikelnummer: " << martikelnummer << endl;
}

int typUmwandlung(string _martikelnummer){
    unsigned int betrag = 0;
    unsigned int pos = 0;

    while (pos < _martikelnummer.length()) {
        if (isdigit(_martikelnummer.at(pos)))
            betrag = betrag * 10 + _martikelnummer.at(pos) - '0';
        pos++;
    }

    return betrag;
}

int Student ::getMartikelnummer() const {return martikelnummer;}

string Student :: getVorname() const {return vorname;}

string Student :: getNachname() const {return nachname;}

Student* Student :: getNaechsteStudent() const {return naechsteStudent;}

Student* Student :: getTop() const {return top;};

void Student :: setMartikelnummer(int _martikelnummer) {martikelnummer = _martikelnummer;}

void Student :: setVorname(string _vorname) {vorname = _vorname;}

void Student :: setNachname(string _nachname) {nachname = _nachname;}

void Student :: setNaechsteStudent(Student* _student) {naechsteStudent = _student;}
