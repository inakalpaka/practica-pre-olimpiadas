#include <iostream>
#include <vector>
#include <algorithm>

bool estaOrdenado(std::vector<int> arreglo)
{
    for (int i = 0; i < arreglo.size() - 1; i++)
    {
        if (arreglo[i] > arreglo[i + 1])
        {
            return false;
        }
    }
    return true;
}

void sePuedeOrdenar(int largoDelArreglo, std::vector<int> arreglo)
{
    int left = -1, right = -1;

    for (int i = 0; i < largoDelArreglo - 1; i++)
    {
        if (arreglo[i] > arreglo[i + 1])
        {
            left = i;
            break;
        }
    }

    if (left == -1)
    {
        std::cout << "yes\n"
                  << 1 << " " << 1 << std::endl;
        return;
    }

    for (int i = largoDelArreglo - 1; i > 0; i--)
    {
        if (arreglo[i] < arreglo[i - 1])
        {
            right = i;
            break;
        }
    }

    std::reverse(arreglo.begin() + left, arreglo.begin() + right + 1);

    if (estaOrdenado(arreglo))
    {
        std::cout << "yes\n" << left + 1 << " " << right + 1 << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arreglo(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arreglo[i];
    }

    sePuedeOrdenar(n, arreglo);

    return 0;
}
