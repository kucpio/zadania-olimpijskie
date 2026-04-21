/*
    Opis problemu:
    Dany jest nieskierowany graf. Trzeba sprawdzić, czy da się przypisać
    wierzchołkom taką kolejność, aby dla każdego istotnego wierzchołka
    odpowiednio dobrana liczba jego sąsiadów była ustawiona wcześniej.
    Jeśli tak, należy wypisać poprawną numerację wierzchołków,
    a jeśli nie, wypisać "NIE".

    Idea rozwiązania:
    Najpierw próbujemy skierować krawędzie tak, aby budowany graf skierowany
    odzwierciedlał zależności pomiędzy wierzchołkami. Startujemy z wierzchołka 1
    i dokładamy kolejne wierzchołki wtedy, gdy "poznały" już połowę swoich
    sąsiadów. Jeśli w pewnym momencie pojawia się sprzeczność albo nie uda się
    skierować wszystkich krawędzi, odpowiedź brzmi "NIE".

    Gdy uda się zbudować graf skierowany, liczymy stopnie wejściowe
    i wykonujemy topologiczne sortowanie. Otrzymana kolejność wyznacza
    szukaną numerację wierzchołków.

    Zastosowane techniki:
    - budowanie grafu skierowanego na podstawie grafu nieskierowanego,
    - kolejka BFS / symulacja procesu aktywacji wierzchołków,
    - sortowanie topologiczne DAG-a.
*/

#include <bits/stdc++.h>

#define ST first
#define ND second
#define S size()

using namespace std;

constexpr int maxN = 10e5 + 7;

int n, m, lo = 0;
int l[maxN] = {0};       // ile "obsłużonych" sąsiadów ma już dany wierzchołek
int o[maxN] = {0};       // wynikowa pozycja wierzchołka w porządku
int sto[maxN] = {0};     // stopnie wejściowe w grafie skierowanym
int cwk[maxN] = {0};     // czy wierzchołek jest już w kolejce
bool Godw[maxN] = {false}; // czy wierzchołek został już przetworzony

vector<int> topo;        // kolejność topologiczna
vector<int> graf[maxN];  // graf nieskierowany
vector<int> Sgraf[maxN]; // zbudowany graf skierowany

void wczytaj()
{
    pair<int, int> w;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> w.ST;
        cin >> w.ND;
        graf[w.ST].push_back(w.ND);
        graf[w.ND].push_back(w.ST);
    }
}

void skieruj_krawedzie()
{
    queue<int> kolejka;
    int t;

    // Zaczynamy proces od wierzchołka 1.
    kolejka.push(1);
    cwk[1] = 1;

    while (!kolejka.empty())
    {
        t = kolejka.front();
        kolejka.pop();

        Godw[t] = true;
        cwk[t] = 0;

        for (int i = 0; i < graf[t].S; i++)
        {
            int v = graf[t][i];

            if (!Godw[v])
            {
                // Jeśli sąsiad jest już w kolejce, a znów próbujemy go aktywować,
                // to według logiki zadania pojawia się sprzeczność.
                if (cwk[v])
                {
                    cout << "NIE";
                    exit(0);
                }

                // Skierowujemy krawędź t -> v.
                lo++;
                Sgraf[t].push_back(v);
                l[v]++;

                // Gdy wierzchołek "zobaczy" połowę swoich sąsiadów,
                // może zostać aktywowany i wrzucony do kolejki.
                // W kodzie jest specjalny wyjątek dla wierzchołka 2.
                if (l[v] == graf[v].S / 2 && v != 2)
                {
                    kolejka.push(v);
                    cwk[v] = 1;
                }
            }
        }
    }

    // Jeśli nie udało się skierować wszystkich krawędzi, rozwiązanie nie istnieje.
    if (lo < m)
    {
        cout << "NIE";
        exit(0);
    }
}

void policz_wchodzace()
{
    // Liczymy stopnie wejściowe w grafie skierowanym.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < Sgraf[i].S; j++)
        {
            sto[Sgraf[i][j]]++;
        }
    }
}

void topsort()
{
    queue<int> q;
    int w;

    // Startujemy od wierzchołków bez krawędzi wchodzących.
    for (int i = 1; i <= n; i++)
    {
        if (!sto[i])
            q.push(i);
    }

    while (!q.empty())
    {
        w = q.front();
        q.pop();
        topo.push_back(w);

        for (int i = 0; i < Sgraf[w].S; i++)
        {
            sto[Sgraf[w][i]]--;
            if (!sto[Sgraf[w][i]])
                q.push(Sgraf[w][i]);
        }
    }
}

void policz()
{
    // Nadajemy każdemu wierzchołkowi jego pozycję w kolejności topologicznej.
    for (int i = 0; i < topo.S; i++)
    {
        o[topo[i]] = i + 1;
    }
}

void odpowiedz()
{
    cout << "TAK\n";

    for (int i = 1; i <= n; i++)
    {
        cout << o[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    skieruj_krawedzie();
    policz_wchodzace();
    topsort();
    policz();
    odpowiedz();

    return 0;
}
