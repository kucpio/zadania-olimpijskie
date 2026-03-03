#include "bits/stdc++.h"

using namespace std;

struct sklad {
    int i;
    double a;
    double b;
};

vector < sklad > elementy;

bool sorotwanie(const sklad &x,
           const sklad &y)
{
    if (x.a * y.b > y.a * x.b)
        return true;
    else if (x.a * y.b < y.a * x.b)
        return false;
    else
        return (x.i < y.i);
}

int main() {

    int n;
    double a;
    double b;
    sklad s;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i=0; i<n; i++) {
        s.i = i + 1;
        cin >> s.a;
        cin >> s.b;
        elementy.push_back(s);
    }

    sort(elementy.begin(), elementy.end(), sorotwanie);

    for (int i=0; i<n; i++)
    {
        cout << elementy[i].i << "\n";
    }

    exit(0);
}