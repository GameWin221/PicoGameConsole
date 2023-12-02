#ifndef CONSOLE_CORE_HPP
#define CONSOLE_CORE_HPP

extern void console_core_load_game(const struct GameInfo& game_info);

// NEVER call inside a game's update function (will lead to infinite recursion)
extern void console_core_update_game(const struct ConsoleInput& input, const struct ConsoleTiming& timing);

#endif