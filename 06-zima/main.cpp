/*
    Zadanie:
    Mamy drzewo o n wierzchołkach, a każda krawędź ma wagę c.
    Program dzieli krawędzie na parzyste i nieparzyste, sumuje ich wkład
    do wyniku bazowego, a następnie znajduje w drzewie najlepszą ścieżkę,
    którą opłaca się "odjąć" od tej sumy.

    Pomysł:
    Najpierw liczymy wartość początkową:
    - dla krawędzi parzystej dodajemy c,
    - dla krawędzi nieparzystej dodajemy c + 1.

    Następnie wykonujemy DFS i robimy DP na drzewie.
    Dla każdego syna wyznaczamy wartość przejścia przez jego poddrzewo:
    - jeśli krawędź do syna ma wagę nieparzystą, to zyskujemy +1,
    - jeśli ma wagę parzystą, to tracimy 1.

    Dzięki temu dla każdego wierzchołka liczymy dwie najlepsze wartości
    schodzące w dół do jego poddrzew. Suma dwóch najlepszych takich zejść
    daje najlepszą ścieżkę przechodzącą przez ten wierzchołek.

    Ostatecznie:
    - w = najlepsza wartość ścieżki w całym drzewie,
    - odpowiedź = wartość bazowa - w.

    Złożoność:
    Całość działa w czasie O(n), bo wykonujemy jedno przejście DFS-em
    i potem jedno przejście po wierzchołkach.
*/

#include <bits/stdc++.h>

#define LL long long int

using namespace std;

int n;

// Suma wkładów od krawędzi nieparzystych i parzystych.
LL odd = 0LL, even = 0LL;

// Najlepsza wartość ścieżki, którą można odjąć od wyniku bazowego.
int w = 0;

// wy[v] = najlepsza wartość jednej ścieżki schodzącej w dół z v.
// we[v] = druga najlepsza taka wartość dla v.
int we[1000007] = {0};
int wy[1000007] = {0};

// Lista sąsiedztwa drzewa:
// (sąsiad, waga krawędzi)
vector<pair<int, int>> drzweo[1000007];

void wejscie()
{
    int a, b, c;

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        drzweo[a].push_back(make_pair(b, c));
        drzweo[b].push_back(make_pair(a, c));

        // Liczymy wartość bazową.
        if (c % 2)
            odd += (c + 1);
        else
            even += c;
    }
}

void dfs(int o, int r)
{
    int d;
    int pn = 0;   // najlepsze zejście w dół z o
    int dn = 0;   // drugie najlepsze zejście w dół z o

    for (auto u : drzweo[o]) {
        if (r == u.first)
            continue;

        dfs(u.first, o);

        // Wkład ścieżki przez dziecko zależy od parzystości krawędzi.
        if (u.second % 2)
            d = wy[u.first] + 1;
        else
            d = wy[u.first] - 1;

        // Trzymamy dwie najlepsze wartości.
        if (d >= pn) {
            dn = pn;
            pn = d;
        }
        else if (d > dn) {
            dn = d;
        }
    }

    wy[o] = pn;
    we[o] = dn;
}

void odpowiedz()
{
    // Najlepsza ścieżka przechodząca przez i
    // to suma dwóch najlepszych zejść z tego wierzchołka.
    for (int i = 1; i <= n; i++) {
        w = max(w, we[i] + wy[i]);
    }

    cout << even + odd - (LL)w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wejscie();
    dfs(1, 0);
    odpowiedz();

    return 0;
}
