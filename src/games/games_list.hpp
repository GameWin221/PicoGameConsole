#ifndef GAMES_LIST_HPP
#define GAMES_LIST_HPP

struct GameInfo
{
    void (*game_init_fn)(); 
    void (*game_exit_fn)(); 
    void (*game_update_fn)(const struct ConsoleInput& input, const struct ConsoleTiming& timing); 
};

extern GameInfo game_demo_info;

#endif