#pragma once

#include<string>
#include<iostream>

using namespace std;

class Originator {

    int state;

public:

    Originator();

    class Memento;

    Memento* GetMemento();
    void SetState(int);
    void DumpState();

    class Memento {

        friend class Originator;

    private:

        int state;
        Originator* originator;

    public:

        Memento();
        void Restore();

    };


};

Originator::Originator() : state(0) {

}

void Originator::SetState(int s) {
    state = s;
}

void Originator::DumpState() {
    cout << "State: " << state << endl;
}

Originator::Memento::Memento() : state(0) {}

Originator::Memento* Originator::GetMemento() 
{
    Originator::Memento* m = new Originator::Memento();
    m->originator = this;
    m->state = state;
    return m;
}


void Originator::Memento::Restore() {

    originator->state = state;
}
