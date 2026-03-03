#include <bits/stdc++.h>

#define REP(a,n) for (int a=0; a<(n); a++)

using namespace std;

constexpr int maxN = 1e5+7;

int n, iledol, goraod, gorakoniec, ilew = 0;
int dol[maxN];
int gora[maxN];
int jest[maxN];
int wynik[1000007];

void wczytaj()
{
    cin >> n;
    REP(a, 2*n)
    {
        cin >> gora[a];
        gora[a]--;
    }

}

void licz()
{
    iledol = goraod = 0;
    gorakoniec = 2*n;
    while (goraod!=gorakoniec)
    {
        int A = gora[goraod++];
        if (jest[A])
        {
            int B = dol[--iledol];
            jest[B] = 0;
            wynik[ilew++] = iledol;
            if (B==gora[goraod])
                ++goraod;
            else
                gora[--goraod] = B;
            gora[--goraod] = A;
            while (iledol && dol[iledol-1]==gora[goraod])
                --iledol, ++goraod;
        }
        else
        {
            jest[A] = 1;
            dol[iledol++] = A;
        }
    }
}

void wypisz()
{
    cout << ilew << "\n";
    REP(a, ilew)
    {
        cout << wynik[a]+1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    licz();
    wypisz();

    exit(0);
}
