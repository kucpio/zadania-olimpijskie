/*
    Zadanie:
    Dany jest nieskierowany graf o n wierzchołkach i m krawędziach.
    Trzeba policzyć, ile trójek różnych wierzchołków nie ma dokładnie
    jednej krawędzi między sobą.

    Innymi słowy: liczymy wszystkie trójki, które zawierają
    0, 2 albo 3 krawędzie.

    Pomysł:
    Najpierw obliczamy stopień każdego wierzchołka.
    Dla ustalonego wierzchołka i możemy policzyć, ile trójek ma dokładnie
    jedną krawędź i jest ona incydentna z i:
        deg(i) * (n - 1 - deg(i))
    bo wybieramy:
    - jednego sąsiada i,
    - jednego niesąsiada i.

    Taka trójka z dokładnie jedną krawędzią zostanie policzona dokładnie
    dwa razy (raz z punktu widzenia jednego końca tej krawędzi i raz z drugiego),
    więc dzielimy sumę przez 2.

    Oznaczmy przez s liczbę trójek z dokładnie jedną krawędzią.
    Wszystkich trójek wierzchołków jest:
        C(n, 3) = n * (n - 1) * (n - 2) / 6
    więc odpowiedź to:
        C(n, 3) - s

    Złożoność:
    Obliczenie stopni działa w O(m),
    potem jedno przejście po wierzchołkach w O(n),
    więc całość ma złożoność O(n + m).
*/

#include "bits/stdc++.h"

using namespace std;

vector<int> wierzcholki;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;

    int a;
    int b;

    int s = 0;   // liczba trójek z dokładnie jedną krawędzią
    int j = 0;   // wynik końcowy

    cin >> n;
    cin >> m;

    wierzcholki.reserve(n + 7);

    // Inicjalizujemy tablicę stopni wierzchołków.
    for (int i = 0; i <= n; i++)
        wierzcholki.push_back(0);

    // Wczytujemy krawędzie i zwiększamy stopnie obu końców.
    for (int i = 0; i < m; i++) {
        cin >> a;
        cin >> b;

        wierzcholki[a]++;
        wierzcholki[b]++;
    }

    // Dla każdego wierzchołka liczymy liczbę par:
    // (sąsiad, niesąsiad).
    // Po zsumowaniu i podzieleniu przez 2 dostajemy liczbę trójek
    // z dokładnie jedną krawędzią.
    for (int i = 1; i <= n; i++)
        s += (wierzcholki[i] * (n - 1 - wierzcholki[i])) / 2;

    // Wszystkie trójki minus trójki z dokładnie jedną krawędzią.
    j = ((n * (n - 1) * (n - 2)) / 6) - s;

    cout << j;

    return 0;
}
