#ifndef V_INPUTMANAGER_H_INCLUDED
#define V_INPUTMANAGER_H_INCLUDED

void InputManager (InputState &inputstate) {
    inputstate.IsMovingUp.previous = inputstate.IsMovingUp.current;
    inputstate.IsMovingDown.previous = inputstate.IsMovingDown.current;
    inputstate.IsMovingLeft.previous = inputstate.IsMovingLeft.current;
    inputstate.IsMovingRight.previous = inputstate.IsMovingRight.current;
    inputstate.IsHit.previous = inputstate.IsHit.current;
    inputstate.state.previous = inputstate.state.current;

    inputstate.IsMovingUp.current = (GetAsyncKeyState('W') & 0x8000);
    inputstate.IsMovingDown.current = (GetAsyncKeyState('S') & 0x8000);
    inputstate.IsMovingLeft.current = (GetAsyncKeyState('A') & 0x8000);
    inputstate.IsMovingRight.current = (GetAsyncKeyState('D') & 0x8000);
    inputstate.IsHit.current = (GetAsyncKeyState(VK_SPACE) & 0x8000);
    inputstate.state.current = (GetAsyncKeyState('P') & 0x8000);

    switch (currentState) {
        case GameState::play:
            if (inputstate.state.isPressed()) {
                currentState = GameState::pause;
            }
            break;
        case GameState::pause:
            if (inputstate.state.isPressed()) {
                currentState = GameState::play;
            }
            break;
    }
}

#endif // V_INPUTMANAGER_H_INCLUDED
