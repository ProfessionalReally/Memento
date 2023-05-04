#include "Header.h"

int main()
{
    Originator org;
    cout << "AS-IS:" << endl;
    org.SetState(1);
    org.DumpState();

    cout << "\ntake a memento\n" << endl;
    Originator::Memento* m1 = org.GetMemento();

    cout << "TO-BE:" << endl;
    org.SetState(2);
    org.DumpState();

    cout << "\nRestored:" << endl;
    m1->Restore();
    org.DumpState();
    delete m1;
}

