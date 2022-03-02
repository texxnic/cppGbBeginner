#include <iostream>
#include <vector>

#include "ArrayInt.h"
#include "Card.h"
#include "Hand.h"

int uniqueValue(std::vector<int> &vec)
{
    int count = 1;
    std::sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); i++)
        if (vec[i - 1] != vec[i])
            count++;
    return count;
}

int main()
{
    std::cout << "TASK 1" << std::endl;
    ArrayInt arrint(4);
    arrint[0] = 4;
    arrint[1] = 7;
    arrint[2] = 2;
    arrint[3] = 8;

    arrint.print();

    arrint.push_back(5);
    arrint.insertBefore(13, 1);

    arrint.print();

    arrint.pop_back();
    arrint.resize(10);

    arrint.print();

    arrint.pop_front();

    arrint.print();

    arrint.sort();

    arrint.print();

    std::cout << "TASK 2" << std::endl;

    std::vector<int> vec{0, 15, 19, 35, 8, 5, 5, 6, 7, 33};
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << "[" << vec[i] << "] ";
    std::cout << std::endl
              << "Уникальных значений: " << uniqueValue(vec) << std::endl;

    std::cout << "TASK 3" << std::endl;
    Card *one = new Card(Card::ten, Card::trefi);
    Card *two = new Card(Card::A, Card::bubi);
    Card *three = new Card(Card::six, Card::piki);

    Hand hand;
    hand.Add(one);
    hand.Add(two);
    hand.Add(three);
    std::cout << "Сумма очков карт: " << hand.GetValue() << std::endl;
    hand.Clear();

    return 0;
}
