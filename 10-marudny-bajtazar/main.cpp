#include  <bits/stdc++.h>

using namespace std;

const int maxK = 17;
constexpr int maxM = 10e4+7;
constexpr int maxR = (1<<(maxK+1))+7;
int n, m, k;
string s = "0";

int zamiany[maxM] = {0};
int drzewo[maxR] = {0};
int ip[maxK+1];


void wczytaj() {
    string w;

    cin >> n >> m >> w;
    
    for(int i = 1; i <= m; i++)
        cin >> zamiany[i];
    k = min(maxK, n);
    
    s += w;
    for (int i = 1; i <= maxK+7; i++)
        s += "0";
    
}

void dodaj(int p, int op)
{
    int x = 0;
    int l = 0;

    for(int i = p; i<= p + k - 1 && i<=n; i++)
    {
        l++;
        if(s[i]=='0')
            x+=x+1;
        else
            x+=x+2;
        if(op>0)
        {
            if (!drzewo[x])
                ip[l]++;
            drzewo[x]++;
        }
        else if(op < 0)
        {
            drzewo[x]--;
            if (!drzewo[x])
                ip[l]--;
        }
    }
}

void zaaktualizuj()
{
    for(int i=1; i<=n;i++)
        dodaj(i, +1);
}

void zamien_popraw(int p)
{
    int l, r;
    l = max(1, p - k + 1);
    r = min(p + k - 2, n);
    for(int i=l; i<=r;i++)
        dodaj(i, -1);

    if(s[p] == '1')
        s[p] = '0';
    else
        s[p] = '1';

    for(int i=l; i<=r;i++)
        dodaj(i, 1);
}

int znajdz()
{
    for(int i=1; i<=k;i++)
    {
        if(ip[i]<(1<<i))
            return i;
    }
}

void policz()
{
    cout << znajdz() << "\n";
    for(int i=1; i<=m; i++)
    {
        zamien_popraw(zamiany[i]);
        cout << znajdz() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    zaaktualizuj();
    policz();

    exit(0);
}
