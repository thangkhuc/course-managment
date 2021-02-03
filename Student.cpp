#include "Student.h"

Student* Student :: top = NULL;
Student* Student :: ende = NULL;
int Student :: martikelnummerArray = 100000;

Student::Student()
{
    vorname = "";
    nachname = "";
    martikelnummer = martikelnummerArray;
    martikelnummerArray++;
    setPreviousStudent(NULL);
    setNextStudent(NULL);
}

Student :: Student(string vorname, string nachname) : vorname(vorname), nachname(nachname)
{
    setPreviousStudent(NULL);
    martikelnummer = martikelnummerArray;
    martikelnummerArray++;
    if (ende == NULL)
        ende = this;

    if (top != NULL)
        top->setPreviousStudent(this);
    this->setNextStudent(top);
    top = this;
}

Student :: Student(Student* student) //Kopierkonstruktor
{
    vorname = student->getVorname();
    nachname = student->getNachname();
    setPreviousStudent(NULL);
    setNextStudent(NULL);
    martikelnummer = student->getMartikelnummer();
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

    if (ende == NULL)
        ende = this;

    if (top != NULL)
        top->setPreviousStudent(this);

    this->setNextStudent(top);
    top = this;
    this->printStudent();
}

void Student :: remove()
{
    if (this == ende) {
        ende = this->getPreviousStudent();
        this->getPreviousStudent()->setNextStudent(NULL);
    }
    else if (this == top) {
        top = this->getNextStudent();
        this->getNextStudent()->setPreviousStudent(NULL);
    }
    else {
        this->getPreviousStudent()->setNextStudent(this->getNextStudent());
        if (this->getNextStudent() != NULL)
            this->getNextStudent()->setPreviousStudent(this->getPreviousStudent());
    }

    cout << "Student " << vorname << " " << nachname << " wird geloescht!" << endl;
    delete this;
}

void Student :: printStudent() const
{
    cout << "Name: " << vorname << " " << nachname << endl;
    cout << "Martikelnummer: " << martikelnummer << endl;
}

int typUmwandlung(string _martikelnummer)
{
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

Student* Student :: getNextStudent() const {return next;}

Student* Student :: getTop() const {return top;}

Student* Student :: getPreviousStudent() const {return previous;}

void Student :: setMartikelnummer(int _martikelnummer) {martikelnummer = _martikelnummer;}

void Student :: setVorname(string _vorname) {vorname = _vorname;}

void Student :: setNachname(string _nachname) {nachname = _nachname;}

void Student :: setNextStudent(Student* _student) {next = _student;}

void Student :: setPreviousStudent(Student* student) {previous = student;}
