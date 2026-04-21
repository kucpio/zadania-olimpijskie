/*
    Opis problemu:
    Dane są dwa ciągi liczb. Celem jest maksymalizacja liczby dopasowanych
    powtórzeń tej samej wartości w obu ciągach, z zachowaniem kolejności.

    Idea rozwiązania:
    Dla każdej pozycji wyznaczamy poprzednie wystąpienie tej samej wartości.
    Następnie wykonujemy dynamic programming podobne do klasycznego LCS,
    ale rozszerzone o dodatkowe warunki, które pilnują, żeby poprawnie
    łączyć pary równych wartości w obu ciągach.

    Zastosowane techniki:
    - dynamic programming na sekwencjach,
    - przechowywanie poprzednich wystąpień,
    - wariant problemu LCS.
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int maxNM = 1e3 * 15 + 7;

int n[2];
int ciag[2][maxNM];
int ostatni[2][maxNM];
int pr[maxNM];
int sumy[maxNM];

void wczytaj()
{
    cin >> n[0] >> n[1];
    
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n[j]; i++)
        {
            cin >> ciag[j][i];
            ostatni[j][i] = 0;

            // Szukamy poprzedniego wystąpienia tej samej wartości.
            for (int k = i - 1; k > 0; k--)
                if (ciag[j][i] == ciag[j][k])
                {
                    ostatni[j][i] = k;
                    break;
                }
        }
}

void policz()
{
    for (int i = 1; i <= n[0]; i++)
        if (ostatni[0][i] != 0)
            for (int j = 1; j <= n[1]; j++)
                if (
                    // Przepisanie lepszego wyniku z lewego prefiksu.
                    pr[j - 1] > pr[j]

                    ||

                    // Próba dopasowania kolejnej pary tej samej wartości
                    // z zachowaniem poprawnej kolejności w obu ciągach.
                    (ciag[0][i] == ciag[1][j]
                     && ostatni[1][j] != 0
                     && pr[j] == pr[ostatni[1][j] - 1]
                     && sumy[ostatni[1][j] - 1] < ostatni[0][i])
                   )
                {
                    pr[j]++;
                    sumy[j] = i;
                }

    cout << pr[n[1]] * 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    policz();

    return 0;
}
