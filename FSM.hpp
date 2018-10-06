#ifndef FSM_HPP
#define FSM_HPP

class FSM {
public:
    virtual void process(double delta) = 0;

};

class StateBase {
    public:
    virtual ~StateBase() = default;
};

template <int i>
class State: public StateBase {
    public:
    virtual void process(double delta) = 0;
};

#endif