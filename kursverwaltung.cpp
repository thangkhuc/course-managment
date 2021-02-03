#include "kursverwaltung.h"

vector<Kurs*> Kursverwaltung :: kursArray;

Kursverwaltung :: ~Kursverwaltung()
{
    Student* p_student = nullptr; // delete all the students
    while (p_student->top != NULL) {
        p_student = p_student->top;
        p_student->remove();
    }

    for (unsigned i = 0; i < kursArray.size(); i++)
        delete kursArray[i];
}

void Kursverwaltung :: menu(){
    cout << "\t\t------------------" << endl;
    cout << "\t\t| KURSVERWALTUNG |" << endl;
    cout << "\t\t------------------" << endl;
    cout << "(1) Kurs\n(2) Student\n(3) Testfall\n(4) Verlassen" << endl;

    int eingabe;
    while(true){
        cin >> eingabe;
        if (eingabe == 1 || eingabe == 2 || eingabe == 3 || eingabe == 4)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    switch (eingabe) {
    case 1: {kurs(); break;}
    case 2: {student(); break;}
    case 3: {testfall(); menu(); break;};
    }
}

void Kursverwaltung :: testfall()
{
    Student* student1 = new Student("dinh thang", "Khuc");
    Student* student2 = new Student("Anfang", "Annika");
    Student* student3 = new Student("Informatrix", "Ingo");
    Student* student4 = new Student("Mustermann", "Maximilian");
    Student* student5 = new Student("Schnellinger", "Sabine");
    Student* student6 = new Student("Zausel", "Zacharias");
    Kurs* kurs1 = new Kurs("PAD");
    Kurs* kurs2 = new Kurs("TGI");
    kurs1->addStudent(student1);
    kurs1->addStudent(student2);
    kurs1->addStudent(student5);
    kurs2->addStudent(student3);
    kurs2->addStudent(student4);
    kurs2->addStudent(student6);
    kurs2->addStudent(student1);
    kursArray.push_back(kurs1);
    kursArray.push_back(kurs2);
}

void Kursverwaltung :: kurs(){
    cout << "\t\t--------" << endl;
    cout << "\t\t| KURS |" << endl;
    cout << "\t\t--------" << endl;
    cout << "(1) Kurs anlegen\n(2) Kurs anzeigen\n(3) Add Student"
            "\n(4) Alle Kurse anzeigen\n(5) Remove Student\n(6) Menu" << endl;

    int eingabe;
    while(true){
        cin >> eingabe;
        if (eingabe == 1 || eingabe == 2 || eingabe == 3 || eingabe == 4 || eingabe == 5 || eingabe == 6)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    switch (eingabe) {
        case 1:
        {
            Kurs * newKurs = new Kurs;
            newKurs->anlegen();
            kursArray.push_back(newKurs);
            kurs();
            break;
        }
        case 2:
        {
            Kurs* p = findKurs();
            if (p != NULL)
                p->printKurs();
            kurs();
            break;
        }
        case 3:
        {
            Kurs* p_kurs = findKurs();
            Student* p_student = findStudent();

            if (p_student != NULL || p_kurs != NULL)
                p_kurs->addStudent(p_student);
            kurs();
            break;
        }
        case 4: {printKurs(); kurs(); break;}
        case 5:
        {
            Kurs* p_kurs = findKurs();
            Student* p_student = findStudent();

            if (p_kurs != NULL || p_student != NULL)
                p_kurs->removeStudent(p_student->getMartikelnummer());

            kurs();
            break;
        }
        case 6: {menu(); break;}
    }
}

void Kursverwaltung :: printStudent() const
{
    Student* p_student = NULL;
    p_student = p_student->top;

    if (p_student == NULL) cout << "Es gibt noch keinen Student" << endl;
    else {
        cout.width(28);
        cout << left << "Name";
        cout.width(28);
        cout << left << "|Vorname";
        cout.width(28);
        cout << left << "|Matrikelnummer" << endl;
        for (int i = 0; i < 71;i++ ) cout << "=";
        cout << endl;
    }

    while (p_student != NULL) {
        cout.width(30);
        cout << left << p_student->getNachname();
        cout.width(30);
        cout << left << p_student->getVorname();
        cout.width(30);
        cout << left << p_student->getMartikelnummer() << endl;
        p_student = p_student->getNextStudent();
    }
}

void Kursverwaltung :: printKurs() const
{
    for (unsigned i = 0; i < kursArray.size(); i++ ) {
        if (kursArray[i]->teilnehmerTop== NULL)
            cout << "Es gibt keinen Studenten in diesem Kurs." << endl;
        else{
            cout.width(28);
            cout << right <<"Kurs: " << kursArray[i]->kursName << "\n" << endl;
            cout << right << "Vorname\t\t\t|Nachname\t\t|Matrikelnummer" << endl;
            cout << "=============================================================" << endl;
            Student* p = kursArray[i]->teilnehmerTop;
            while(p != NULL) {
                cout.width(25);
                cout << left << p->getVorname() << " ";
                cout.width(25);
                cout << left << p->getNachname();
                cout << p->getMartikelnummer() << endl;
                p = p->getNextStudent();
            }
        }
        cout << endl;
    }
}

void Kursverwaltung :: student()
{
    cout << "\t\t-----------" << endl;
    cout << "\t\t| STUDENT |" << endl;
    cout << "\t\t-----------" << endl;
    cout << "(1) Student eintragen\n(2) Student suchen\n(3) Student loeschen\n(4) Alle Studente anzeigen\n(5) Menue" << endl;

    int eingabe;
    while(true){
        cin >> eingabe;
        if (eingabe == 1 || eingabe == 2 || eingabe == 3 || eingabe == 4 || eingabe == 5)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    switch (eingabe) {
    case 1:
    {
        Student* newStudent = new Student;
        newStudent->eintragen();
        student();
        break;
    }
    case 2:
    {
        Student* p_Student;
        p_Student = findStudent();
        if (p_Student != NULL)
            p_Student->printStudent();
        student();
    }
    case 3:
    {
        Student* p_Student= findStudent();
        if (p_Student != 0) {
            p_Student->remove();
        }
        student();
        break;
    }
    case 4: {studentSortieren(); printStudent(); student(); break;}
    case 5: {menu(); break;}
    }
}

Kurs* Kursverwaltung :: findKurs(){ // return NULL wenn es keinen solchen Kurs gibt
    string _kursName;

    cout << "Geben Sie die Kursname ein: " << endl;
    fflush(stdin);
    getline(cin, _kursName);

    for (unsigned int i = 0; i < kursArray.size() ; ++i ) {
        if (_kursName == kursArray[i]->getKursname())
            return kursArray[i];
    }
    cout << "Es gibt diesen Kurs nicht" << endl;
    return NULL;
}

Student* Kursverwaltung :: findStudent() //return NULL wenn es solchen Student nicht gibt
{
    string _martikelnummer;
    int betrag;

    cout << "Geben Sie die Martikelnummer ein: " << endl;
    fflush(stdin);
    getline(cin, _martikelnummer);

    betrag = typUmwandlung(_martikelnummer);

    Student* p = NULL;
    p = p->top;

    while (true) {
        if (p == NULL){
            cout << "es gibt diese Martikelnummer nicht" << endl;
            return NULL;
        }
        if (betrag == p->getMartikelnummer()) {
            return p;
            break;
        }
        p = p->getNextStudent();
    }
}

void Kursverwaltung :: studentSortieren()
{
   Student* p = NULL;
   Student* q = NULL;
   Student* speicherP = NULL;
   p = p->top->getNextStudent();
   q = q->top;

   while (p != NULL) {
       q = p->getPreviousStudent();
       speicherP = p->getNextStudent();
       while (q != NULL && q->getNachname() > p->getNachname()) {
            if (q != p->top)
                q->getPreviousStudent()->setNextStudent(p);
            else
                p->top = p;

            if (p != p->ende)
                p->getNextStudent()->setPreviousStudent(q);
            else
                p->ende = q;

            p->setPreviousStudent(q->getPreviousStudent());
            q->setNextStudent(p->getNextStudent());

            p->setNextStudent(q);
            q->setPreviousStudent(p);

            q = p->getPreviousStudent();
       }
       p = speicherP;
   }
}
