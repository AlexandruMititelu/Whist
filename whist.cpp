#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::pair<int, int> getOrRemoveRandomlyCards(std::set<std::pair<int, int>> &cards, int counter = 0)
{
    int temp = rand() % cards.size();    
    auto it = cards.begin();

    for(int j = 0; j < temp; j++)
    {
        it++;
    }
    
    if(counter == 0)
        cards.erase(it);
    else
    {
        auto tempIt = it;

        cards.erase(it);
        return *tempIt;;
    }
}

std::set<std::pair<int, int>> initializeCards(std::set<std::pair<int, int>> cards, int nrOfPlayers, int nrOfCards) // Sa lasi nr corect de carti in pachet
{
    int nrOfCardsRemoved = cards.size() - nrOfPlayers * nrOfCards;
    
    for(int i = 0; i < nrOfCardsRemoved; i++)
    {   
        getOrRemoveRandomlyCards(cards);
    }

    return cards;
}

void initializeWhist(std::vector<std::vector<std::pair<int, int>>> &players, 
                     std::set<std::pair<int, int>> cards, int nrOfCards) // Sa distribui cartile
{
    for(int i = 0; i < players.size(); i++)
    {
        for(int j = 0; j < nrOfCards; j++)
        {
            players.at(i).at(j) = getOrRemoveRandomlyCards(cards, 1);
        }
    }
}

void testThis(std::vector<std::vector<std::pair<int, int>>> players) // Ca sa o testezi
{
    for(int i = 0; i < players.size(); i++)
    {
        for(int j = 0; j < players.at(i).size(); j++)
        {
            std::cout << "Player " << i << " has cards: " << players.at(i).at(j).first << " " 
                      << players.at(i).at(j).second << std::endl;
        }
    }
}

int main()
{
    std::cout << "Enter number of players \n";
    int nr, nrOfCards;;
    std::cin  >> nr;
    std::cout << "Enter number of cards for this round (max 8, min 0) \n";
    std::cin  >> nrOfCards;
    
    std::vector<std::vector<std::pair<int, int>>> players(nr, std::vector<std::pair<int, int>>(nrOfCards));
    std::set<std::pair<int, int>> cards = { {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, 
                                           {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9}, 
                                           {0, 10}, {0, 11}, {0, 12}, {0, 13}, {0, 14}, 
                                           {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, 
                                           {1, 6}, {1, 7}, {1, 8}, {1, 9}, {1, 10}, {1, 11},
                                           {1, 12}, {1, 13}, {1, 14}, {2, 0}, {2, 1}, {2, 2}, 
                                           {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9},
                                           {2, 10}, {2, 11}, {2, 12}, {2, 13}, {2, 14}, {3, 0}, {3, 1}, 
                                           {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {3, 8}, 
                                           {3, 9}, {3, 10}, {3, 11}, {3, 12}, {3, 13}, {3, 14}, 
                                        };  

    std::set<std::pair<int, int>> cardsForThisMatch = initializeCards(cards, players.size(), nrOfCards);
    initializeWhist(players, cardsForThisMatch, nrOfCards); 

    testThis(players);

    return 0;
}