#include <bits/stdc++.h>

#define LL long long int

using namespace std;

int n;
LL odd = 0LL, even = 0LL;
int w = 0;

int we[1000007] = {0};
int wy[1000007] = {0};

vector<pair<int, int>> drzweo[1000007];

void wejscie()
{
    int a, b, c;

    cin >> n;

    for(int i=1; i<n; i++) {
        cin >> a >> b >> c;
        drzweo[a].push_back(make_pair(b, c));
        drzweo[b].push_back(make_pair(a, c));
        if(c%2)
            odd+=(c+1);
        else
            even+=c;
    }

}

void dfs(int o, int r) {
    int d;
    int pn = 0;
    int dn = 0;

    for (auto u : drzweo[o]) {

        if(r == u.first)
            continue;

        dfs(u.first, o);
        
        if(u.second%2)
            d = wy[u.first] + 1;
        else
            d = wy[u.first] - 1;

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
    for(int i = 1; i<=n; i++) {
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