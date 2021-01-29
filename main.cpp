#include "kursverwaltung.h"

Student* top = NULL;

int main()
{
    /*
     * 1) Alle Objekte Studenten und Kurse meines Programms liegen im Heap, da Objekte Studenten
     * 	 durch verketete Liste verbunden sind, deshalb ist es zwingend Objekte Studenten im Heap
     * 	 zu speichern, sonst  wird der Objekt nach jeder Funktionsende geloescht.
     *
     * 2) Vorteil: man muss die Groesse von Array voher initieren
     *
     * 3) Nachteil: es ist sehr aufwaendig, nach Daten zu suchen
     * 	  Knoten einzufuegen, zu loeschen und sortieren, da man ueber jedes Element
     *    von Top durch gehen muss
     *
     * 4) Ich wuerde vector verwenden, weil vector auch Vorteile von verketeter Liste hat aber
     * 	  es ist sehr einfacher, Elemente in Vector zu verarbeiten
     */

    Kursverwaltung kursverwaltung;
    kursverwaltung.menu();

    return 0;
}
