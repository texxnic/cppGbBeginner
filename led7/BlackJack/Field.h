#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Colours.h"

class Field
{

    const std::string t_bj_ = R"(

.____                                            __    
|    |    __ __  ____   ____ ___________ _______|  | __
|    |   |  |  \/    \ /  _ \\____ \__  \\_  __ \  |/ /
|    |___|  |  /   |  (  <_> )  |_> > __ \|  | \/    < 
|_______ \____/|___|  /\____/|   __(____  /__|  |__|_ \
        \/          \/       |__|       \/           \/
        .__  __  .__     
__  _  _|__|/  |_|  |__  
\ \/ \/ /  \   __\  |  \ 
 \     /|  ||  | |   Y  \
  \/\_/ |__||__| |___|  /
                      \/ 
___.   .__                 __         __               __    
\_ |__ |  | _____    ____ |  | __    |__|____    ____ |  | __
 | __ \|  | \__  \ _/ ___\|  |/ /    |  \__  \ _/ ___\|  |/ /
 | \_\ \  |__/ __ \\  \___|    <     |  |/ __ \\  \___|    < 
 |___  /____(____  /\___  >__|_ \/\__|  (____  /\___  >__|_ \
     \/          \/     \/     \/\______|    \/     \/     \/
                   .___             
_____    ____    __| _/             
\__  \  /    \  / __ |              
 / __ \|   |  \/ /_/ |              
(____  /___|  /\____ |   /\ /\ /\ /\
     \/     \/      \/   \/ \/ \/ \/
        )";

    const std::string t_menu_ = R"(
                                     +-------------------------------------+
                                     |                 MENU                |
                                     +-------------------------------------+ 
                                     |             1. NEW GAME             |
                                     +-------------------------------------+ 
                                     |             2. LOAD GAME            |
                                     +-------------------------------------+ 
                                     |               3. EXIT               |
                                     +-------------------------------------+
    )";

    const std::string t_player_ = R"(
                                     +-------------------------------------+
                                     |                 MENU                |
                                     +-------------------------------------+ 
                                     |           1. SINGLE-PLAYER          |
                                     +-------------------------------------+
                                     |           2. PLAYER VS PLAYER       |
                                     +-------------------------------------+
                                     |                3. BACK              |
                                     +-------------------------------------+
    )";

    bool is_continue_ = true,
        is_single_player_ = false,
        is_multi_player_ = false,
        is_menu_ = true;

    const int max_n_m_players_ = 6;
    const int max_n_s_players_ = 1;

public:
    Field();
    std::string title_bj() const;
    std::string title_menu() const;
    std::string title_player() const;

    std::vector<std::string> vGetNamePlayers() const;
    std::vector<std::string> names;

    int max_players = 0;

    void set_continue();
    void set_single();
    void set_multi();
    void set_menu();
    void menu_main();
    void menu_player();

    bool get_continue() const;
    bool get_single() const;
    bool get_multi() const;
    bool get_menu() const;

    int get_max_s_players() const;
    int get_max_m_players() const;

    ~Field();
};