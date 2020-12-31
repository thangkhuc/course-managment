#include "Student.h"

extern Student* top;

Student::Student(){
    vorname = "";
    nachname = "";
}

Student :: Student(Student& student){ //Kopierkonstruktor
    vorname = student.getVorname();
    nachname = student.getNachname();
    naechsteStudent = student.getNaechsteStudent();
    martikelnummer = student.getMartikelnummer();
}

void eintragen(){
    Student* p_student = new Student;

    string _vorname, _nachname;
    cout << "Geben Sie Ihre Vorname ein" << endl;
    fflush(stdin);
    getline(cin, _vorname);
    cout << "Geben Sie Ihre Nachname ein" << endl;
    fflush(stdin);
    getline(cin, _nachname);

    p_student->setVorname(_vorname);
    p_student->setNachname(_nachname);
    p_student->martikelnummerGenerator();
    p_student->setNaechsteStudent(top);
    top = p_student;
    p_student->printStudent();
}

void studentLoeschen(){
    Student* p = findStudent();
    Student* _p = top;

    while(true){
        if (p != top) {
            while (_p->getNaechsteStudent() != p) // suche den Student am vorne
                _p = _p->getNaechsteStudent();

            p->setVorname(_p->getVorname());   // mit dem Wert des vornen Studenten ersetzen
            p->setNachname(_p->getNachname()); // aber die Adresse bleibt unveraendert
            p->setMartikelnummer(_p->getMartikelnummer());

            p = _p;
            _p = top;
        }
        else {
            top = p->getNaechsteStudent();
            break;
        }
    }
}

void Student :: printStudent(){
    cout << "Name: " << vorname << " " << nachname << endl;
    cout << "Martikelnummer: " << martikelnummer << endl;
}

void testausgeben(Student student){
    Student* p = &student;
    while (true){
        cout << "Name: " << p->getVorname() << " " << p->getNachname() << endl;
        cout << "Martikelnummer: " << p->getMartikelnummer() << endl;

        if (p->getNaechsteStudent() == NULL)
            break;
        p = p->getNaechsteStudent();
    }
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

Student* findStudent(){ //return NULL wenn es solchen Student nicht gibt
    string _martikelnummer;
    int betrag;

    cout << "Geben Sie die Martikelnummer ein: " << endl;
    fflush(stdin);
    getline(cin, _martikelnummer);

    betrag = typUmwandlung(_martikelnummer);

    Student* p = top;
    while (true) {
        if (p == NULL){
            cout << "es gibt diese Martikelnummer nicht" << endl;
            return NULL;
        }
        if (betrag == p->getMartikelnummer()) {
            return p;
            break;
        }
        p = p->getNaechsteStudent();
    }
}

int Student ::getMartikelnummer(){
    return martikelnummer;
}

string Student :: getVorname(){
    return vorname;
}

string Student :: getNachname(){
    return nachname;
}

Student* Student :: getNaechsteStudent(){
    return naechsteStudent;
}

void Student :: setMartikelnummer(int _martikelnummer){
    martikelnummer = _martikelnummer;
}

void Student :: setVorname(string _vorname){
    vorname = _vorname;
}

void Student :: setNachname(string _nachname){
    nachname = _nachname;
}

void Student :: setNaechsteStudent(Student* _student){
    naechsteStudent = _student;
}

void Student :: martikelnummerGenerator(){
    time_t time1 = time(NULL);
    martikelnummer = (rand() * time1) % (999999 - 100000 + 1) + 100000;
}

Student :: ~Student(){}
