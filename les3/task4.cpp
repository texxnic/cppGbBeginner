#include <iostream>
#include <string>

using namespace std;

class Card
{
private:
    enum suit
    {
        bubi,
        trefi,
        chervi,
        piki
    };
    enum value
    {
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        J,
        Q,
        K,
        A
    };
    bool m_position = false;
    value m_value = two;
    suit m_suit = bubi;

public:
    Card()
    {
        std::cout << "Создать карту" << std::endl;
    };
    void Flip()
    {
        m_position = !(m_position);
    };
    int GetValue()
    {
        int valueCard[13] = {
            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 1};
        return valueCard[m_value];
    };
    ~Card()
    {
        std::cout << "Удалить карту" << std::endl;
    };
};

int main()
{
    Card card;
    std::cout << "Значение карты: " << card.GetValue() << std::endl;
    return 1;
}