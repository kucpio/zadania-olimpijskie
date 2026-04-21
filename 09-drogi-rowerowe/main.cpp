/*
    Opis problemu:
    Dany jest graf skierowany. Dla każdego wierzchołka trzeba policzyć,
    ile innych wierzchołków jest z niego osiągalnych.

    Idea rozwiązania:
    Najpierw wyznaczamy silnie spójne składowe grafu. Wszystkie wierzchołki
    w jednej SCC mają taki sam zbiór osiągalnych składowych, więc można
    skompresować graf do grafu kondensacji, który jest DAG-iem.

    Następnie dla każdej składowej obliczamy, ile wierzchołków można osiągnąć
    z tej składowej w grafie kondensacji. Robimy to dynamicznie w porządku
    topologicznym, sumując rozmiary osiągalnych składowych.

    Na końcu każdemu wierzchołkowi przypisujemy wynik jego składowej
    i odejmujemy 1, aby nie liczyć samego siebie.

    Zastosowane techniki:
    - algorytm Kosaraju do znajdowania silnie spójnych składowych,
    - budowa grafu kondensacji SCC,
    - sortowanie topologiczne DAG-a,
    - dynamic programming na DAG-u.
*/

#include <bits/stdc++.h>

#define MAX_N 100007

using namespace std;

int n, m;
int kolor = 0;  // liczba silnie spójnych składowych

vector<int> graf[MAX_N];     // graf oryginalny
vector<int> odwr[MAX_N];     // graf odwrócony
vector<int> Tgraf[MAX_N];    // niewykorzystywane w finalnym rozwiązaniu
vector<int> Sgraf[MAX_N];    // graf kondensacji SCC
vector<int> TSgraf[MAX_N];   // odwrócony graf kondensacji
vector<int> kolejnosc;       // kolejność kończenia DFS-a

int moc[MAX_N] = {0};        // rozmiar każdej SCC
int topo[MAX_N] = {0};       // porządek topologiczny SCC
int sto[MAX_N] = {0};        // stopnie wejściowe w grafie kondensacji
int wy[MAX_N] = {0};         // wynik DP dla SCC
int sp[MAX_N] = {0};         // numer SCC, do której należy wierzchołek
bool odw[MAX_N] = {false};   // odwiedzenie w pierwszym DFS-ie

void wczytaj()
{
    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        odwr[b].push_back(a);
    }
}

// Pierwszy DFS z algorytmu Kosaraju:
// zapisujemy wierzchołki w kolejności kończenia przetwarzania.
void DFS(int v)
{
    odw[v] = true;
    for (int i = 0; i < (int)graf[v].size(); i++)
    {
        if (!odw[graf[v][i]])
            DFS(graf[v][i]);
    }
    kolejnosc.push_back(v);
}

// Drugi DFS po grafie odwróconym:
// nadajemy numery SCC i jednocześnie budujemy graf kondensacji.
void SCC(int v, int kol)
{
    sp[v] = kol;

    for (int i = 0; i < (int)odwr[v].size(); i++)
    {
        int u = odwr[v][i];

        if (sp[u] == 0)
            SCC(u, kol);
        else if (sp[u] != kolor)
        {
            // Krawędź między dwiema różnymi SCC w grafie kondensacji.
            Sgraf[sp[u]].push_back(kolor);
            TSgraf[kolor].push_back(sp[u]);
        }
    }
}

void przygotuj()
{
    // 1. DFS-y w grafie oryginalnym.
    for (int i = 1; i <= n; i++)
    {
        if (!odw[i])
            DFS(i);
    }

    // 2. DFS-y w grafie odwróconym w odwrotnej kolejności kończenia.
    for (int i = (int)kolejnosc.size() - 1; i >= 0; i--)
    {
        if (sp[kolejnosc[i]] == 0)
            SCC(kolejnosc[i], ++kolor);
    }

    // 3. Liczymy stopnie wejściowe w grafie kondensacji.
    for (int i = 1; i <= kolor; i++)
    {
        for (int j = 0; j < (int)Sgraf[i].size(); j++)
        {
            sto[Sgraf[i][j]]++;
        }
    }

    // 4. Liczymy rozmiar każdej składowej SCC.
    for (int i = 1; i <= n; i++)
    {
        moc[sp[i]]++;
    }
}

void toposort()
{
    queue<int> q;
    int w, k = 0;

    for (int i = 1; i <= kolor; i++) {
        if (sto[i] == 0) {
            q.push(i);
        }
    }

    while (q.size() > 0) {
        w = q.front();
        q.pop();
        k++;
        topo[k] = w;

        for (int i = 0; i < (int)Sgraf[w].size(); i++) {
            sto[Sgraf[w][i]]--;
            if (sto[Sgraf[w][i]] == 0) {
                q.push(Sgraf[w][i]);
            }
        }
    }
}

// Funkcja pomocnicza, niewykorzystywana w ostatecznym rozwiązaniu.
void transponuj()
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int)graf[i].size(); j++) {
            Tgraf[graf[i][j]].push_back(i);
        }
}

void policz(void)
{
    // Przechodzimy po SCC w odwrotnej kolejności topologicznej.
    // Dzięki temu znamy już wyniki wszystkich składowych osiągalnych dalej.
    for (int i = kolor; i >= 1; i--)
    {
        for (int j = 0; j < (int)TSgraf[topo[i]].size(); j++)
        {
            wy[TSgraf[topo[i]][j]] += (wy[topo[i]] + moc[topo[i]]);
        }
    }

    // Każda SCC osiąga także wszystkie swoje własne wierzchołki.
    for (int i = 1; i <= kolor; i++)
    {
        wy[i] += moc[i];
    }
}

void wypisz(void)
{
    for (int i = 1; i <= n; i++)
        cout << wy[sp[i]] - 1 << "\n";
}

// Funkcje pomocnicze do debugowania.
void wypisz_graf()
{
    for (int i = 1; i <= kolor; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < (int)TSgraf[i].size(); j++)
        {
            cout << TSgraf[i][j] << " ";
        }
        cout << "\n";
    }
}

void wypiszz()
{
    /*for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << sp[i] << "\n";
    }*/
    for (int i = 1; i <= kolor; i++)
    {
        cout << topo[i] << "\n";
    }
    /*for (int i = 1; i <= kolor; i++)
    {
        cout << moc[i] << "\n";
    }*/
    /*for (int i = 1; i <= kolor; i++)
    {
        cout << wy[i] << "\n";
    }*/
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    przygotuj();
    toposort();
    policz();
    wypisz();

    return 0;
}
