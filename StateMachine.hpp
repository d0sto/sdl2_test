#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <vector>
#include <map>

class StateMachine {
  protected:
    enum State {
        VEL_UP,
        VEL_DOWN,
        VEL_LEFT,
        VEL_RIGHT,

        STILL_UP,
        STILL_DOWN,
        STILL_LEFT,
        STILL_RIGHT,
    };

    State activeState;

    virtual void advance(State state) = 0;
    virtual bool isComplete() = 0;

    virtual void runState() = 0;

    std::map< State, std::vector<State> > possibleTransitions;
};
#endif
