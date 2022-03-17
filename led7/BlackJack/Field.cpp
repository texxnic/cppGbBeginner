#include "Field.h"

Field::Field() {}

std::string Field::title_bj() const
{
    std::ostringstream title_return;
    title_return << t_bj_;
    return title_return.str();
}

std::string Field::title_menu() const
{
    std::ostringstream title_return;
    title_return << t_menu_;
    return title_return.str();
}

std::string Field::title_player() const
{
    std::ostringstream titleReturn;
    titleReturn << t_player_;
    return titleReturn.str();
}

void Field::set_continue()
{
    is_continue_ = !is_continue_;
}

void Field::set_single()
{
    is_single_player_ = !is_single_player_;
}

void Field::set_multi()
{
    is_multi_player_ = !is_multi_player_;
}

void Field::set_menu()
{
    is_menu_ = !is_menu_;
}

bool Field::get_continue() const
{
    return is_continue_;
}

bool Field::get_single() const
{
    return is_single_player_;
}

bool Field::get_multi() const
{
    return is_multi_player_;
}

bool Field::get_menu() const
{
    return is_menu_;
}


int Field::get_max_s_players() const
{
    return max_n_s_players_;
}

int Field::get_max_m_players() const
{
    return max_n_m_players_;
}

void Field::menu_main()
{
    do
    {
        Console::clear_console();
        std::cout << Colours::Code::S_BRICHT_GREEN << title_menu() << Colours::Code::DEFAULT << "\n";
        switch (_getch())
        {
        case '1':
            menu_player();
            break;
        case '2':
            break;
        case '3':
            set_menu();
            set_continue();
            break;
        default:
            break;
        }
        if (!get_menu())
            break;
    } while (is_menu_);
}

void Field::menu_player()
{
    do
    {
        Console::clear_console();
        std::cout << Colours::Code::S_BRICHT_GREEN << title_player() << Colours::Code::DEFAULT << "\n";

        switch (_getch())
        {
        case '1':
            set_single();
            max_players = get_max_s_players();
            names = vGetNamePlayers();
            Console::clear_console();
            set_menu();
            break;
        case '2':
            set_multi();
            max_players = get_max_m_players();
            names = vGetNamePlayers();
            Console::clear_console();
            set_menu();
            break;
        case '3':
            Console::clear_console();
            menu_main();
            break;
        default:
            break;
        }
    } while (is_menu_);
}

auto Field::vGetNamePlayers() const -> std::vector<std::string>
{
    std::vector<std::string> names;
    int countPlayers = 0;
    bool isSetNames = true;
    while (isSetNames)
    {
        std::string name;
        std::cout << "Enter name for " << ++countPlayers << " player : ";
        std::cin >> name;
        if (names.size() == 0)
        {
            names.push_back(name);
        }
        else
        {
            auto it = std::find(names.begin(), names.end(), name);
            while (it != names.end())
            {
                std::cout << "Enter another name for " << countPlayers << " player : ";
                std::cin >> name;
                it = std::find(names.begin(), names.end(), name);
            }
            names.push_back(name);
        }

        if (countPlayers == max_players)
        {
            Console::clear_console();
            isSetNames = false;
        }
        else if (countPlayers < max_players)
        {
            std::cout << "Do you need another player?\nEnter 'Y' - Yes or 'N' - No : \n";
            switch (_getch())
            {
            case 'y':
                isSetNames = true;
                continue;
            case 'Y':
                isSetNames = true;
                continue;
            case 'n':
                isSetNames = false;
                break;
            case 'N':
                isSetNames = false;
                break;
            default:
                continue;
            }
            if (countPlayers < max_players && !isSetNames)
            {
                Console::clear_console();
                break;
            }
        }
    }
    return names;
}

Field::~Field() {}