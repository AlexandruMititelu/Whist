#include <iostream>
#include <vector>

void initializeWhist(std::vector<std::vector<std::pair<int, int>>> &players, 
                     std::vector<std::vector<int>> cardsMatrix)
{

    int n, y;
    
    for(int i = 0; i < players.size(); i++))
    {
        for(int j = 0; j < 8; j++)
        {
            n = rand() % 4;
            y = rand() % 15;

            while(cardsMatrix.at(n).at(y) == 0)
            {
                int temp = n;
                n = (i + 1 < cards.size())? n + 1 : n - 1;
                if(n - 1 < 0)  
                {
                    n++;

                }
            }
        }
    }




}

int main()
{
    std::cout << "Enter number of players \n";
    int nr;
    std::cin >> nr;

    std::vector<std::vector<std::pair<int, int>>> players(nr, std::vector<std::pair<int, int>>(8));
    std::set<std::pair<int, int> cardsMatrix = { {0, 0}, {0, 1}, {0, 2}, {0, 3} }; // Am pus doar 4, dar normal tb 4 simboluri a cate 15 carti, 
                                                                                   // ca sa reprezinte tot pachetul  

    std::vector<std::vector<int>> notUsedCards = initializeWhist(players, cardsMatrix);

    return 0;
}