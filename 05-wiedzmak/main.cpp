/*
    Zadanie:
    Mamy n miast połączonych m drogami. Każda droga ma koszt przejścia
    oraz może wymagać posiadania pewnego zestawu typów uprawnień / przedmiotów
    / umiejętności. Dodatkowo w niektórych miastach można zdobyć kolejne typy.
    Trzeba znaleźć minimalny koszt dotarcia z miasta 1 do miasta n.

    Pomysł:
    Zwykły Dijkstra po samych miastach nie wystarczy, bo możliwość przejścia
    danej drogi zależy od tego, co już zebraliśmy po drodze. Dlatego stan
    opisujemy parą:
        (aktualne_miasto, maska_posiadanych_typów)

    - maska bitowa przechowuje informację, które typy już mamy,
    - po wejściu do miasta automatycznie dodajemy do maski wszystko,
      co można w nim zdobyć,
    - drogą możemy przejść tylko wtedy, gdy jej wymagana maska jest
      podzbiorem naszej aktualnej maski.

    Na takim grafie stanów uruchamiamy algorytm Dijkstry.
    przejscie[v][mask] oznacza minimalny koszt dotarcia do miasta v
    z dokładnie takim zestawem zdobytych typów.

    Złożoność:
    Liczba stanów to O(n * 2^p), bo dla każdego miasta rozważamy wszystkie maski.
    Każde przejście w Dijkstrze działa standardowo z kolejką priorytetową,
    więc całość ma złożoność rzędu:
        O((n * 2^p + m * 2^p) log(n * 2^p))
    co jest akceptowalne dla małego p.
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int maxN = 2 * 1e2 + 7;
constexpr int maxM = (1 << 13) + 7;
constexpr int INF = 1e9 + 7;

// graf[v] przechowuje listę krawędzi:
// (dokąd, (koszt_przejścia, wymagana_maska))
vector<pair<int, pair<int, int>>> graf[maxN];

int n, m, p, k;

// maska_kowala[v] = typy, które zdobywamy w mieście v
int maska_kowala[maxN];

void wczytaj()
{
    int mk, im, x, v, w, t, u, maska;

    cin >> n >> m >> p >> k;

    // Wczytanie informacji o miastach, w których można zdobyć typy.
    for (int i = 0; i < k; i++)
    {
        cin >> mk >> im;
        mk--;

        for (int j = 0; j < im; j++)
        {
            cin >> x;
            x--;
            maska_kowala[mk] |= (1 << x);
        }
    }

    // Wczytanie dróg:
    // v, w - końce drogi
    // t    - koszt przejścia
    // u    - liczba wymaganych typów
    for (int i = 0; i < m; i++)
    {
        cin >> v >> w >> t >> u;

        maska = 0;

        for (int j = 0; j < u; j++)
        {
            cin >> x;
            x--;
            maska += (1 << x);
        }

        v--;
        w--;

        graf[v].push_back(make_pair(w, make_pair(t, maska)));
        graf[w].push_back(make_pair(v, make_pair(t, maska)));
    }
}

void dijkstry()
{
    // przejscie[v][mask] = minimalny koszt dotarcia do miasta v
    // z zestawem typów równym mask.
    int przejscie[maxN][maxM];

    int miasto, maska, nm, o, v, wynik = INF;
    pair<int, int> mm;

    // Trzymamy w kolejce:
    // (-koszt, (miasto, maska))
    // Minus przy koszcie, bo priority_queue w C++ jest domyślnie max-heapem.
    priority_queue<pair<int, pair<int, int>>> kolejka;

    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < maxM; j++)
            przejscie[i][j] = INF;

    // Zaczynamy w mieście 0 i od razu zbieramy wszystko,
    // co można w nim zdobyć.
    przejscie[0][maska_kowala[0]] = 0;
    kolejka.push(make_pair(0, make_pair(0, maska_kowala[0])));

    while (!kolejka.empty())
    {
        mm = kolejka.top().second;
        kolejka.pop();

        miasto = mm.first;
        maska = mm.second;

        // Próbujemy przejść każdą krawędzią wychodzącą z bieżącego miasta.
        for (int i = 0; i < graf[miasto].size(); i++)
            // Możemy przejść tylko wtedy, gdy wymagania drogi
            // są zawarte w aktualnej masce.
            if ((graf[miasto][i].second.second | maska) == maska)
            {
                v = graf[miasto][i].first;

                // Po wejściu do nowego miasta zbieramy dostępne tam typy.
                nm = (maska_kowala[v] | maska);

                // Koszt nowego stanu.
                o = przejscie[miasto][maska] + graf[miasto][i].second.first;

                if (o < przejscie[v][nm])
                {
                    przejscie[v][nm] = o;
                    kolejka.push(make_pair(-o, make_pair(v, nm)));
                }
            }
    }

    // Szukamy najlepszego kosztu dotarcia do miasta n-1
    // niezależnie od końcowej maski.
    for (int i = 0; i < (1 << p); i++)
        if (przejscie[n - 1][i] < wynik)
            wynik = przejscie[n - 1][i];

    if (wynik == INF)
        wynik = -1;

    cout << wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    dijkstry();

    return 0;
}
