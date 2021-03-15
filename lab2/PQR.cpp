#include <iostream>
#include <vector>
#include "RandomNumberGenerator.h"
#include <algorithm>

std::ostream& operator << (std::ostream& StrmWy, std::vector<int> wek)
{
    int LiczbaZadan = wek.size();
    StrmWy << "[";

    for (int j = 0; j < LiczbaZadan; j++)
    {
        if (j == LiczbaZadan - 1)
        {
            StrmWy << wek[j];
        }
        else
        {
            StrmWy << wek[j] << ", ";
        }

    }

    StrmWy << "]" << std::endl;

    return StrmWy;
}

std::ostream& operator << (std::ostream& StrmWy, std::vector<std::pair<int, int>> wek)
{
    int LiczbaZadan = wek.size();
    StrmWy << "r: [";

    for (int j = 0; j < LiczbaZadan; j++)
    {
        if (j == LiczbaZadan - 1)
        {
            StrmWy << wek[j].first;
        }
        else
        {
            StrmWy << wek[j].first << ", ";
        }

    }

    StrmWy << "]" << std::endl;
    StrmWy << "p: [";
    for (int j = 0; j < LiczbaZadan; j++)
    {
        if (j == LiczbaZadan - 1)
        {
            StrmWy << wek[j].second;
        }
        else
        {
            StrmWy << wek[j].second << ", ";
        }
    }
    StrmWy << "]" << std::endl;

    return StrmWy;
}

void addCQ(std::vector<int> q, std::vector<int> c, std::vector<int> *wynik)
{
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        wynik->push_back(q[i] + c[i + 1]);
    }
}

void FillPi(std::vector<int>& pi, int LiczbaZadan, int tryb)
{
    RandomNumberGenerator Obiekt(1);
    pi.clear();

    if (tryb == 1)
    {
        for (int i = 0; i < LiczbaZadan; i++)
        {
            pi.push_back(i + 1);
        }
    }
    if (tryb == 2)
    {
        for (int i = 0; i < LiczbaZadan; i++)
        {
            pi.push_back(i + 1);
        }
        std::random_shuffle(pi.begin(), pi.end());
        
    }
}

int main()
{
    RandomNumberGenerator Obiekt(1);
    int LiczbaZadan, tryb;
    std::vector<std::pair<int, int>> Lista;
    std::vector<int> C1, S1, pi, q, CQ;

    C1.push_back(0);
    

    std::cout << "Wprowadz liczbe zadan: ";
    std::cin >> LiczbaZadan;
    std::cout << "Podaj tryb generowania wektora PI(1,2): ";
    std::cin >> tryb;


    FillPi(pi, LiczbaZadan, tryb);
    std::cout << "PI:" << pi;

    for (int i = 0; i < LiczbaZadan; i++)
    {
        q.push_back(Obiekt.nextInt(1,29));
    }  // generowanie wektora q

    for (int i = 0; i < LiczbaZadan; i++)
    {
        int r = Obiekt.nextInt(1, 29);
        int p = Obiekt.nextInt(1, 29);

        Lista.push_back(std::make_pair(r, p));
    } // generowanie elementów r i p


    for (int i = 0; i < LiczbaZadan; i++)
    {
        int a = pi[i]-1;
        
            S1.push_back(std::_Max_value(Lista[a].first, C1[i]));
            C1.push_back(S1[i] + Lista[a].second);
    } // obliczenie S1, C1

    addCQ(q, C1, &CQ);

    std::cout << Lista;
    std::cout << "q:" << q;
    std::cout << "S1:" << S1;
    std::cout << "C1:" << C1;

    std::cout << "CQ: " << CQ;
    std::cout << *std::max_element(CQ.begin(), CQ.end()) << '\n';
}