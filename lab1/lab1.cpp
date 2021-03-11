// SPC.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include "RandomNumberGenerator.h"

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

void FillPi(std::vector<int>& pi,  int LiczbaZadan, int tryb)
{
    RandomNumberGenerator Obiekt(1);
    int wartosc, counter =0;
    std::vector<int> previous;
    previous.clear();
    pi.clear();

    if (tryb == 1)
    {
        for (int i = 0; i < LiczbaZadan; i++)
        {
            pi.push_back(i + 1);
        }
    }
}

int main()
{
    RandomNumberGenerator Obiekt(1);
    int LiczbaZadan, tryb;
    std::vector<std::pair<int, int>> Lista;
    std::vector<int> C1, S1, pi;

    C1.push_back(0);

    std::cout << "Wprowadz liczbe zadan: ";
    std::cin >> LiczbaZadan;
    std::cout << "Podaj tryb generowania wektora PI(1,2): ";
    std::cin >> tryb;

   
    FillPi(pi, LiczbaZadan, tryb);
    std::cout<<"PI:" << pi;


    for (int i = 0; i < LiczbaZadan; i++)
    {
        int r = Obiekt.nextInt(1,30);
        int p = Obiekt.nextInt(1,30);

        Lista.push_back(std::make_pair(r, p));
    }


    for (int i = 0; i < LiczbaZadan; i++)
    {
        int a = pi[i]-1;

        S1.push_back(std::_Max_value(Lista[a].first, C1[i]));
        C1.push_back(S1[i] + Lista[a].second);
    }
   
    std::cout << Lista;
    std::cout<<"C1:" << C1;

    


}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
