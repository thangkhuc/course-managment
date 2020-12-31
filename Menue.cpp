#include "Menue.h"

bool menu(){ // false fuer verlassen
    cout << "\t\tKURSVERWALTUNG" << endl;
    cout << "(1) Kurs\n(2) Student\n(3) verlassen" << endl;

    char eingabe;
    int betrag;

    while(true){
        cin >> eingabe;
        betrag = eingabe - '0';
        if (betrag == 1 || betrag == 2 || betrag == 3)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    if (betrag == 1)
        return kurs();
    else if (betrag == 2)
        return student();
    else
        return false;
}

bool kurs(){
    cout << "\t\tKURS" << endl;
    cout << "(1) Kurs anlegen\n(2) Kurs anzeigen\n(3) Add Student\n(4) Menue" << endl;

    char eingabe;
    int betrag;
    while(true){
        cin >> eingabe;
        betrag = eingabe - '0';
        if (betrag == 1 || betrag == 2 || betrag == 3)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    if (betrag == 1) {
        Kurs* newKurs = new Kurs;
        newKurs->anlegen();
        kursArray.push_back(newKurs);
        return true;
    }
    else if (betrag == 2){
        Kurs* p = kursSuchen();
        if (p != NULL)
            p->printKurs();
         return true;

    }
    else if (betrag == 3) {
        Student* p_student;
        Kurs* p_kurs = new Kurs;

        p_kurs = kursSuchen();
        p_student = findStudent();

        if (p_student == NULL || p_kurs == NULL)
            return true;
        else {
            p_kurs->addStudent(*p_student);
            return true;
        }
    }
    else{
        return menu();
    }
}


bool student(){
    cout << "\t\tSTUDENT" << endl;
    cout << "(1) Student eintragen\n(2) Student suchen\n(3) Student loeschen\n(4) Menue" << endl;

    char eingabe;
    int betrag;
    while(true){
        cin >> eingabe;
        betrag = eingabe - '0';
        if (betrag == 1 || betrag == 2 || betrag == 3 || betrag == 4)
            break;
        cout << "ungueltige Eingabe" << endl;
    }

    if (betrag == 1) {
        eintragen();
        return true;
    }
    else if (betrag == 2){
        Student* p_Student;
        p_Student = findStudent();
        if (p_Student != NULL)
            p_Student->printStudent();
        return true;
    }
    else if (betrag == 3) {
        studentLoeschen();
        return true;
    }
    else{
        return menu();
    }
}
