#include "bits/stdc++.h"

using namespace std;

vector <int> wierzcholki;

int main() {

    int n;
    int m;

    int a;
    int b;

    int s = 0;
    int j = 0;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    wierzcholki.reserve(n+7);

    for (int i = 0; i <= n; i++)
        wierzcholki.push_back(0);

    for (int i = 0; i < m; i++)
    {
        cin >> a;
        cin >> b;

        wierzcholki[a]++;
        wierzcholki[b]++;
    }

    for (int i = 1; i <= n; i++)
       s += (wierzcholki[i] * (n - 1 - wierzcholki[i]))/2;


    //cout << s;

    j = ((n*(n-1)*(n-2))/6)-s;

    cout << j;

    exit(0);
}
