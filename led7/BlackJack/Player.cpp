#include "Player.h"

Player::Player(const std::string& name)
    : GenericPlayer(name) {}

bool Player::is_hitting() const
{
    const bool is_set_answer = true;
    std::cout << "Player " << player_name_ << ", do you need another card?\nEnter 'Y' - Yes or 'N' - No\n";
    while (is_set_answer)
    {
        switch (_getch())
        {
        case 'y':
            return is_set_answer;
        case 'Y':
            return is_set_answer;
        case 'n':
            return !is_set_answer;
        case 'N':
            return !is_set_answer;
        default: ;
        }
    }
}

void Player::win() const
{
    std::cout << "Player " << player_name_ << " Winner! \n";
}

void Player::lose() const
{
    std::cout << "Player " << player_name_ << " loses.\n";
}

void Player::push()
{
    std::cout << "Players " << " draw.\n";
}

Player::~Player() {}