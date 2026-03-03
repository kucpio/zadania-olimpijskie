#include <bits/stdc++.h>

using namespace std;

constexpr int maxN = 2*1e2+7;
constexpr int maxM = (1<<13)+7;
constexpr int INF = 1e9+7;

vector <pair<int, pair<int, int>>> graf[maxN];

int n, m, p, k;

int maska_kowala[maxN];

void wczytaj()
{
    int mk, im, x, v, w, t, u, maska;

    cin >> n >> m >> p >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> mk >> im;

        mk--;

        for (int j = 0; j < im; j++)
        {
            cin >> x;
            x--;
            maska_kowala[mk] |= (1<<x);
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> v >> w >> t >> u;

        maska = 0;

        for (int j = 0; j < u; j++)
        {
            cin >> x;
            x--;
            maska += (1<<x);
        }
        v--;
        w--;
        graf[v].push_back(make_pair(w, make_pair(t, maska)));
        graf[w].push_back(make_pair(v, make_pair(t, maska)));
    }
}

void dijkstry()
{
    int przejscie[maxN][maxM];
    int miasto, maska, nm, o, v, wynik = INF;
    pair<int, int> mm;
    priority_queue<pair<int, pair<int, int>>> kolejka;

    for (int i = 0; i < maxN; i++)
        for (int j = 0; j < maxM; j++)
            przejscie[i][j] = INF;

    przejscie[0][maska_kowala[0]] = 0;
    kolejka.push(make_pair(0, make_pair(0, maska_kowala[0])));

    while(!kolejka.empty())
    {
        mm = kolejka.top().second;
        kolejka.pop();
        miasto = mm.first;
        maska = mm.second;

        for (int i = 0; i < graf[miasto].size(); i++)
            if (((graf[miasto][i].second.second)|maska) == maska)
            {
                v = graf[miasto][i].first;
                nm = (maska_kowala[v]|maska);
                o = przejscie[miasto][maska]+graf[miasto][i].second.first;

                if (o < przejscie[v][nm])
                {
                    przejscie[v][nm] = o;
                    kolejka.push(make_pair(-o, make_pair(v, nm)));
                }
            }
    }

    for (int i = 0; i < (1<<p); i++)
        if (przejscie[n-1][i] < wynik)
            wynik = przejscie[n-1][i];

    if(wynik == INF)
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

    exit(0);
}