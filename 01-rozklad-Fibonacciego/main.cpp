#include "bits/stdc++.h"

using namespace std;

const int MN = 87;

long long int fib[MN];

int main() {

    int p;
    long long int k;
    int r = 0;
    long long int n;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i < MN; i++)
        fib[i] = fib[i-1] + fib[i-2];



    cin >> p;

    for (int i = 0; i < p; i ++)
    {
        cin >> k;
        r = 0;

        while (k > 0)
        {
            n = k;

            for (int j = 0; j < MN; j++)
                n = min(n, abs(k-fib[j]));

            k = n;
            r++;
        }

        cout << r << "\n";

    }

    exit(0);
}