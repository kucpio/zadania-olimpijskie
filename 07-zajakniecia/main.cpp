/*
    Zadanie:
    Dane są dwa ciągi. Chcemy znaleźć maksymalną liczbę par jednakowych
    wartości, które da się dobrać w obu ciągach z zachowaniem kolejności,
    przy czym każda wybrana wartość musi wystąpić co najmniej drugi raz
    w swoim ciągu. Na końcu wypisujemy dwa razy tyle, ile takich par udało się
    utworzyć.

    Pomysł:
    Dla każdej pozycji i w obu ciągach wyznaczamy ostatnie wcześniejsze
    wystąpienie tej samej wartości:
        ostatni[j][i]
    Dzięki temu wiemy, czy element może domknąć parę z poprzednim
    wystąpieniem tej samej liczby.

    Następnie przechodzimy po pierwszym ciągu. Interesują nas tylko pozycje i,
    które mają wcześniejsze takie samo wystąpienie, czyli mogą być końcem pary.
    Dla każdej takiej pozycji próbujemy aktualizować DP po drugim ciągu.

    Znaczenie tablic:
    - pr[j]   : maksymalna liczba dopasowanych par po rozpatrzeniu prefiksu
                pierwszego ciągu i pierwszych j elementów drugiego ciągu,
    - sumy[j] : pozycja w pierwszym ciągu, do której dochodzi rozwiązanie
                zapisane w pr[j].

    Przejście:
    Możemy poprawić wynik dla j, jeśli:
    1. lewy prefiks daje lepszy wynik niż aktualny,
       czyli pr[j-1] > pr[j],
    albo
    2. elementy na pozycjach i i j są równe, oba mają wcześniejsze wystąpienie
       tej samej wartości, a dodatkowo wcześniejsze części rozwiązania nie
       nachodzą na siebie.

    Po każdej takiej poprawie zwiększamy liczbę dopasowanych par o 1.

    Wynik:
    pr[n[1]] oznacza liczbę dopasowanych par, a program wypisuje
    2 * pr[n[1]], czyli łączną liczbę elementów należących do tych par.

    Złożoność:
    - wyznaczenie tablicy ostatnich wystąpień w obecnej wersji: O(n^2),
    - właściwe DP: O(n[0] * n[1]).
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int maxNM = 1e3 * 15 + 7;

// Długości obu ciągów.
int n[2];

// Dwa wejściowe ciągi.
int ciag[2][maxNM];

// ostatni[j][i] = poprzednia pozycja tej samej wartości co ciag[j][i].
// Jeśli brak wcześniejszego wystąpienia, to 0.
int ostatni[2][maxNM];

// Tablice DP.
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
        // Interesują nas tylko elementy, które mają wcześniejsze takie samo wystąpienie.
        if (ostatni[0][i] != 0)
            for (int j = 1; j <= n[1]; j++)
                if (
                    // Możemy po prostu przepisać lepszy wynik z lewego prefiksu.
                    pr[j - 1] > pr[j]

                    ||

                    // Albo domknąć nową parę odpowiadających sobie wartości.
                    (ciag[0][i] == ciag[1][j]
                     && ostatni[1][j] != 0
                     && pr[j] == pr[ostatni[1][j] - 1]
                     && sumy[ostatni[1][j] - 1] < ostatni[0][i])
                   )
                {
                    pr[j]++;
                    sumy[j] = i;
                }

    // Każda dopasowana para wnosi 2 elementy do odpowiedzi.
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
