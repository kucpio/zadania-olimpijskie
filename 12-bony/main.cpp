/*
    Opis problemu:
    Dane są dwie grupy liczb:
    - liczby wygrywające,
    - kolejne wartości opisujące etapy sprzedaży / przydziału.

    Dla każdej wartości w z drugiej grupy rozpatrywane są kolejne wielokrotności
    liczby w. W danym etapie wybieranych jest dokładnie w jeszcze niesprzedanych
    liczb będących wielokrotnościami w. Jeśli wśród nowo sprzedanych liczb
    pojawi się liczba wygrywająca, należy zapisać moment jej uzyskania.

    Idea rozwiązania:
    Dla każdej liczby w zapamiętujemy wskaźnik ostatni[w], który mówi,
    od której wielokrotności trzeba kontynuować dalsze szukanie.
    Dzięki temu dla tej samej wartości nie zaczynamy za każdym razem od nowa.

    Tablica sprzedane[] przechowuje informację, które liczby zostały już
    wykorzystane wcześniej. W każdej operacji przechodzimy po wielokrotnościach w
    i wybieramy pierwsze w takie liczby, które jeszcze nie zostały sprzedane.

    Jeśli nowo sprzedana liczba jest oznaczona jako wygrywająca,
    zapisujemy chwilę jej uzyskania. Moment ten to:
        liczba wszystkich wcześniej przetworzonych elementów + numer aktualnie
        sprzedawanego elementu w bieżącej partii.

    Zastosowane techniki:
    - symulacja procesu,
    - iterowanie po wielokrotnościach,
    - zapamiętywanie miejsca wznowienia dla każdej wartości,
    - tablice logiczne do oznaczania wykorzystanych i specjalnych liczb.
*/

#include <bits/stdc++.h>

#define LL long long int

using namespace std;

constexpr int maxNM = 1e6 + 7;

int m, n, mwygrywajacy, wynik = 0;

// wygrywajacy[x] = czy liczba x jest liczbą wygrywającą
bool wygrywajacy[maxNM];

// sprzedane[x] = czy liczba x została już wcześniej wykorzystana
bool sprzedane[maxNM];

// ostatni[w] = od której wielokrotności liczby w kontynuujemy dalsze szukanie
int ostatni[maxNM] = {0};

// zapisane momenty trafienia na liczby wygrywające
LL wyniki[maxNM];

void wczytaj_policz()
{
    int w, s = 0;
    LL k = 0LL;  // ile elementów zostało już "obsłużonych" w poprzednich etapach

    cin >> m;

    // Wczytanie liczb wygrywających.
    for (int i = 0; i < m; i++)
    {
        cin >> w;
        wygrywajacy[w] = true;
        mwygrywajacy = w;
    }

    cin >> n;

    // Przetwarzanie kolejnych etapów.
    for (int i = 0; i < n; i++)
    {
        cin >> w;

        // Jeśli pierwszy raz widzimy tę wartość,
        // zaczynamy od jej najmniejszej dodatniej wielokrotności.
        if (!ostatni[w])
            ostatni[w] = w;

        s = 0;

        // Szukamy kolejnych niesprzedanych wielokrotności liczby w,
        // aż znajdziemy ich dokładnie w albo wyjdziemy poza zakres.
        for (; ostatni[w] <= mwygrywajacy && s < w; ostatni[w] += w)
        {
            if (!sprzedane[ostatni[w]])
            {
                sprzedane[ostatni[w]] = true;
                s++;

                // Jeśli trafiliśmy na liczbę wygrywającą,
                // zapisujemy moment jej uzyskania.
                if (wygrywajacy[ostatni[w]])
                {
                    wyniki[wynik] = k + (LL)s;
                    wynik++;
                }
            }
        }

        // Do łącznej liczby przetworzonych elementów dokładamy rozmiar partii.
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

    return 0;
}
