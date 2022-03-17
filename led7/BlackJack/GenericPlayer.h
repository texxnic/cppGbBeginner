#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Colours.h"
#include "Card.h"
#include "Hand.h"

class GenericPlayer : public Hand
{
protected:
    std::string player_name_;

    friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
    {
        out << "     " << Colours::Code::S_BRICHT_GREEN << player.player_name_ << "     " << Colours::Code::S_BRICHT_YELLOW << "     " << player.get_total() << Colours::Code::DEFAULT << "\n";
        if (!player.v_cards_on_hand_.empty())
        {
            for (size_t i = 0; i < 6; i++)
            {
                for (auto it = player.v_cards_on_hand_.begin(); it != player.v_cards_on_hand_.end(); ++it)
                {
                    if ((*it)->get_card_open())
                    {
                        switch (i)
                        {
                        case 0:
                            out << "  " << "         " << "  ";
                            break;
                        case 1:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 2:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->get_card_suit(*(*it)) == "\004" || (*it)->get_card_suit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->get_card_suit(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->get_card_suit(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 3:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->get_card_suit(*(*it)) == "\004" || (*it)->get_card_suit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->get_card_rank(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->get_card_rank(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 4:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->get_card_suit(*(*it)) == "\004" || (*it)->get_card_suit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->get_card_suit(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->get_card_suit(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 5:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        default: ;
                        }
                    }
                    else
                    {
                        switch (i)
                        {
                        case 0:
                            out << "  " << "         " << "  ";
                            break;
                        case 1:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 2:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " XXXXXXX " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 3:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " X<<+>>X " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 4:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " XXXXXXX " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 5:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        default: ;
                        }

                    }
                }
                out << std::endl;

            }

            if (player.is_boosted())
                std::cout << "\n" << player.player_name_ << " busts with " << player.get_total() << " points!\n";
        }
        else
        {
            out << "No cards on hand.\n\n\n\n\n\n";
        }
        return out;
    }

public:
    explicit GenericPlayer(const std::string& name = "");

    virtual bool is_hitting() const = 0;
    bool is_boosted() const;

    ~GenericPlayer() override;

};