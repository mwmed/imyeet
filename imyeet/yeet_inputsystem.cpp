#include "yeet_inputsystem.h"
bool current_key_state[256];
bool old_key_state[256];
void imyeet::inputmanager::on_update()
{
    for (int i = 0; i < 256; i++) {
        old_key_state[i] = current_key_state[i]; // store the current state in the previous state container

        current_key_state[i] = GetAsyncKeyState(i);

    }
}

bool imyeet::inputmanager::is_key_up(const int key)
{
    return (!current_key_state[key] && old_key_state[key]);
}

bool imyeet::inputmanager::is_key_down(const int key)
{
    return current_key_state[key];

}
