#include <bits/stdc++.h>

#define ST first
#define ND second
#define S size()

using namespace std;

constexpr int maxN = 10e5+7;

int n, m, lo = 0;
int l[maxN] = {0};
int o[maxN] = {0};
int sto[maxN] = {0};
int cwk[maxN] = {0};
bool Godw[maxN] = {false};
vector <int> topo;
vector <int> graf[maxN];
vector <int> Sgraf[maxN];

void wczytaj()
{
    pair <int, int> w;
    int d = 0;

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
    queue <int> kolejka;
    int t;

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

            if (!Godw[graf[t][i]])
            {
                if (cwk[graf[t][i]])
                {
                    cout << "NIE";
                    exit(0);
                }
                lo++;
                Sgraf[t].push_back(graf[t][i]);
                l[graf[t][i]]++;
                if (l[graf[t][i]] == graf[graf[t][i]].S/2 && graf[t][i] != 2)
                {
                    kolejka.push(graf[t][i]);
                    cwk[graf[t][i]] = 1;
                }
            }
        }
    }
    if (lo < m)
    {
        cout << "NIE";
        exit(0);
    }
}

void policz_wchodzace()
{

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
    queue <int> q;
    int w;
    for (int i = 1; i <= n; i++)
    {
        if (!sto[i])
            q.push(i);
    }

    while(!q.empty())
    {
        w = q.front();
        q.pop();
        topo.push_back(w);
        for (int i = 0; i < Sgraf[w].S; i++)
        {
            sto[Sgraf[w][i]]--;
            if(!sto[Sgraf[w][i]])
                q.push(Sgraf[w][i]);
        }
    }
}

void policz()
{
    for (int i = 0; i < topo.S; i++)
    {
        o[topo[i]] = i+1;
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

    exit(0);
}
