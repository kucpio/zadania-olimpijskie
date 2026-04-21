/*
    Zadanie:
    Danych jest n elementów opisanych przez dwie wartości a i b.
    Trzeba posortować je malejąco według wartości ilorazu a / b.
    Jeśli dwa elementy mają taki sam iloraz, to wcześniej ma się pojawić
    ten o mniejszym numerze wejściowym.

    Pomysł:
    Każdemu elementowi zapamiętujemy:
    - jego numer z wejścia,
    - wartość a,
    - wartość b.

    Następnie sortujemy wszystkie elementy własnym komparatorem.
    Żeby porównywać ilorazy a / b bez dzielenia, używamy porównania
    krzyżowego:
        a1 / b1 > a2 / b2  <=>  a1 * b2 > a2 * b1
    Dzięki temu unikamy dodatkowych problemów związanych z dokładnością
    porównań na liczbach zmiennoprzecinkowych.

    Po posortowaniu wypisujemy numery elementów w uzyskanej kolejności.

    Złożoność:
    Sortowanie działa w czasie O(n log n), a pamięciowo używamy O(n).
*/

#include "bits/stdc++.h"

using namespace std;

struct sklad {
    int i;      // numer elementu w wejściu
    double a;   // pierwsza wartość
    double b;   // druga wartość
};

vector<sklad> elementy;

// Komparator do sortowania malejąco po wartości a / b.
// Przy remisie bierzemy mniejszy numer wejściowy.
bool sorotwanie(const sklad &x, const sklad &y)
{
    if (x.a * y.b > y.a * x.b)
        return true;
    else if (x.a * y.b < y.a * x.b)
        return false;
    else
        return (x.i < y.i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    double a;
    double b;
    sklad s;

    cin >> n;

    // Wczytujemy elementy i zapamiętujemy ich oryginalne numery.
    for (int i = 0; i < n; i++) {
        s.i = i + 1;
        cin >> s.a;
        cin >> s.b;
        elementy.push_back(s);
    }

    // Sortowanie według zadanego porządku.
    sort(elementy.begin(), elementy.end(), sorotwanie);

    // Wypisujemy numery elementów po posortowaniu.
    for (int i = 0; i < n; i++) {
        cout << elementy[i].i << "\n";
    }

    return 0;
}
