#include <iostream>

using namespace std;

class State {
public:
    virtual void handle() = 0;
};

class ConcreteStateA : public State {
public:
    void handle() override {
        cout << "Handling request in State A" << endl;
    }
};

class ConcreteStateB : public State {
public:
    void handle() override {
        cout << "Handling request in State B" << endl;
    }
};

class Context {
    State* state;
public:
    void setState(State* state) {
        this->state = state;
    }

    void request() {
        state->handle();
    }
};

int main() {
    Context context;

    ConcreteStateA stateA;
    ConcreteStateB stateB;

    context.setState(&stateA);
    context.request();

    context.setState(&stateB);
    context.request();

    return 0;
}
