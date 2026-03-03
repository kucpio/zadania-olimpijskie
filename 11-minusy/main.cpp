#include "bits/stdc++.h"

using namespace std;

int main() {

    int n;
    char w;
    int l = 0;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    //cout << "-";

    for (int i = 1; i < n; i++)
    {
        cin >> w;

        if (w == '+' && l == 0)
        {
            cout << "(";
            l = 1;
        }

        if (w == '-' && l == 1)
        {
            cout << ")";
            l = 0;
        }

        cout << "-";

    }

    if (w == '+')
        cout << ")";

    exit(0);
}