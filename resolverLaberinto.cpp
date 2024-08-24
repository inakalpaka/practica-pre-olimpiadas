#include <iostream>
#include <vector>

bool PuedoLLegar(std::vector<std::vector<char>> &laberinto, int x, int y)
{
    if (x < 0 || y < 0 || x >= laberinto.size() || y >= laberinto[0].size())
    {
        return false;
    }

    if (laberinto[x][y] == 'G')
    {
        return true;
    }

    if (laberinto[x][y] == '#' || laberinto[x][y] == 'R')
    {
        return false;
    }

    laberinto[x][y] = 'R';

    if (PuedoLLegar(laberinto, x + 1, y))
    {
        return true;
    }
    if (PuedoLLegar(laberinto, x, y + 1))
    {
        return true;
    }
    if (PuedoLLegar(laberinto, x - 1, y))
    {
        return true;
    }
    if (PuedoLLegar(laberinto, x, y - 1))
    {
        return true;
    }

    laberinto[x][y] = '.';

    return false;
}

int main()
{
    std::vector<std::vector<char>> laberinto = {
        {'S', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '#', '.', 'G'},
        {'#', '#', '.', '.', '.', '#'}};

    int startX, startY;
    for (int i = 0; i < laberinto.size(); ++i)
    {
        for (int j = 0; j < laberinto[i].size(); ++j)
        {
            if (laberinto[i][j] == 'S')
            {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    std::cout << PuedoLLegar(laberinto, startX, startY) << std::endl;
    return 0;
}
