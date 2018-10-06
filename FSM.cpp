#include "FSM.hpp"

// namespace FSMStates {
//     enum STATES {
//         JUMP_STATE = 0,
//         IDLE_STATE = 1
//     };
// };
// //typedef STATES States;

// class JumpState: public State<FSMStates::JUMP_STATE> {
// public:
//     void process(double delta) override {
//         std::cout << "JumpState process!" << std::endl;
//     }

// };

// class ExampleMachine: public FSM {
// public:
//     FSMStates::STATES state;
//     JumpState jumpState;
//     void process(double delta) override {
//         std::cout << "ExampleMachine process!" << std::endl;
//         std::cout << "State is: " << state << std::endl;
//         switch (state) {
//             case FSMStates::JUMP_STATE:
//                 jumpState.process(delta);
//                 break;
//             default:
//                 std::cout << "ERROR default process!" << std::endl;
//                 break;
//         }
//     }
// };