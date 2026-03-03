#include <bits/stdc++.h>

#define LL long long int

using namespace std;

constexpr int maxNM = 1e6+7;

int m, n, mwygrywajacy, wynik = 0;
bool wygrywajacy[maxNM];
bool sprzedane[maxNM];
int ostatni[maxNM] = {0};
LL wyniki[maxNM];

void wczytaj_policz()
{
    int w, s = 0;
    LL k = 0LL;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> w;
        wygrywajacy[w] = true;
        mwygrywajacy = w;
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> w;
        if (!ostatni[w])
            ostatni[w] = w;

        s = 0;

        for (; ostatni[w] <= mwygrywajacy && s < w; ostatni[w] += w)
        {
            if (!sprzedane[ostatni[w]])
            {
                sprzedane[ostatni[w]] = true;
                s++;
                if (wygrywajacy[ostatni[w]])
                {
                    wyniki[wynik] = k + (LL)s;
                    wynik++;
                }
            }
        }
        k += (int)w;
    }
}

void wypisz()
{
    cout << wynik << "\n";

    for (int i = 0; i < wynik; i++)
        cout << wyniki[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj_policz();
    wypisz();

    exit(0);
}