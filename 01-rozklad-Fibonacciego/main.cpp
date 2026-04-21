/*
    Zadanie:
    Dla każdej liczby k wykonujemy operację:
    zamieniamy k na min |k - F_i|, gdzie F_i jest liczbą Fibonacciego.
    Trzeba policzyć, po ilu takich krokach dojdziemy do 0.

    Pomysł:
    Najpierw generujemy wszystkie liczby Fibonacciego, które mieszczą się
    w zakresie long long. Następnie dla każdej liczby k symulujemy proces:
    w każdym kroku sprawdzamy wszystkie liczby Fibonacciego i wybieramy tę,
    która daje najmniejszą różnicę względem aktualnego k.
    Nową wartością k staje się właśnie ta minimalna różnica.

    Złożoność:
    Jeśli dla danej liczby wykonamy t kroków, to złożoność wynosi O(t * MN),
    czyli tutaj praktycznie O(t), bo MN = 87 jest stałe.
*/
#include "bits/stdc++.h"
using namespace std;

const int MN = 87;
long long fib[MN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib[0] = 1;
    fib[1] = 1;

    // Generowanie ciągu Fibonacciego: 1, 1, 2, 3, 5, ...
    for (int i = 2; i < MN; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int p;
    cin >> p;

    while (p--) {
        long long k;
        cin >> k;

        int r = 0;

        // Symulujemy kolejne przejścia, aż k spadnie do 0.
        while (k > 0) {
            long long n = k;

            // Szukamy liczby Fibonacciego najbliższej aktualnemu k.
            for (int j = 0; j < MN; j++)
                n = min(n, abs(k - fib[j]));

            k = n;
            r++;
        }

        cout << r << "\n";
    }

    return 0;
}
