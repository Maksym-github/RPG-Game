#ifndef INPUTSTATE_H_INCLUDED
#define INPUTSTATE_H_INCLUDED
#include <string>

enum class GameState {
    play,
    pause
};

GameState currentState = GameState::play;

struct ButtonState {
    bool current = false;
    bool previous = false;

    bool isPressed() const {
        return current && !previous;
    }
};

struct InputState {
    ButtonState IsMovingUp;
    ButtonState IsMovingDown;
    ButtonState IsMovingRight;
    ButtonState IsMovingLeft;
    ButtonState IsHit;
    ButtonState state;
};

#endif // INPUTSTATE_H_INCLUDED
