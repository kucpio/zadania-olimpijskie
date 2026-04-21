/*
    Zadanie:
    Dostajemy ciąg długości 2n, w którym każda liczba z zakresu [1, n]
    występuje dokładnie dwa razy. Program symuluje pewien proces
    przenoszenia elementów między "górą" i "dołem" oraz zapisuje kolejne
    pozycje, na których wykonywane są operacje.

    Pomysł:
    Traktujemy tablicę "gora" jak wejściowy ciąg, po którym przesuwamy się
    wskaźnikiem. Dodatkowo utrzymujemy stos "dol", na który odkładamy liczby,
    które pojawiły się pierwszy raz.

    Jeśli liczba A pojawia się pierwszy raz, to wrzucamy ją na stos.
    Jeśli pojawia się drugi raz, to zdejmujemy element ze szczytu stosu
    i wykonujemy odpowiednią operację "dopasowania". Zapisujemy wtedy
    aktualny rozmiar stosu jako wynik jednej operacji.

    Kluczowe jest to, że program nie realizuje operacji wprost na strukturze
    typu listy czy deque, tylko bardzo sprytnie symuluje cały proces
    na dwóch tablicach i wskaźnikach. Dzięki temu działa liniowo.

    Znaczenie struktur:
    - gora[]  : aktualnie przetwarzany ciąg elementów,
    - dol[]   : stos elementów otwartych, ale jeszcze niezamkniętych,
    - jest[]  : informacja, czy dana liczba znajduje się obecnie na stosie,
    - wynik[] : kolejne zapisane odpowiedzi.

    Złożoność:
    Każdy element jest dodawany i usuwany stałą liczbę razy, więc całość
    działa w czasie O(n) i używa pamięci O(n).
*/

#include <bits/stdc++.h>

#define REP(a,n) for (int a = 0; a < (n); a++)

using namespace std;

constexpr int maxN = 1e5 + 7;

int n;
int iledol, goraod, gorakoniec, ilew = 0;

// "dol" działa jak stos aktualnie otwartych elementów.
int dol[maxN];

// "gora" przechowuje wejściowy ciąg, po którym poruszamy się wskaźnikiem.
int gora[maxN];

// jest[x] = 1, jeśli element x aktualnie znajduje się na stosie "dol".
int jest[maxN];

// Tablica odpowiedzi.
int wynik[1000007];

void wczytaj()
{
    cin >> n;

    // Wczytujemy 2n liczb i zmniejszamy je o 1,
    // żeby pracować na numeracji od 0.
    REP(a, 2 * n)
    {
        cin >> gora[a];
        gora[a]--;
    }
}

void licz()
{
    iledol = 0;      // aktualny rozmiar stosu "dol"
    goraod = 0;      // wskaźnik początku nieprzetworzonej części "gora"
    gorakoniec = 2 * n;

    while (goraod != gorakoniec)
    {
        int A = gora[goraod++];

        // Jeśli A jest już na stosie, to trafiliśmy na jego drugie wystąpienie.
        if (jest[A])
        {
            // Zdejmujemy element ze szczytu stosu.
            int B = dol[--iledol];
            jest[B] = 0;

            // Zapisujemy aktualną pozycję / rozmiar stosu jako wynik operacji.
            wynik[ilew++] = iledol;

            // Jeśli na wejściu od razu czeka para do domknięcia,
            // możemy przesunąć wskaźnik dalej.
            if (B == gora[goraod])
                ++goraod;
            else
                // W przeciwnym razie "odkładamy" B z powrotem do przetworzenia.
                gora[--goraod] = B;

            // A także cofamy A, bo ono też ma wrócić na początek kolejki zdarzeń.
            gora[--goraod] = A;

            // Dopóki szczyt stosu pasuje do najbliższego elementu na górze,
            // możemy od razu zamykać kolejne pary.
            while (iledol && dol[iledol - 1] == gora[goraod])
                --iledol, ++goraod;
        }
        else
        {
            // Pierwsze wystąpienie A: odkładamy je na stos.
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
        // Dodajemy 1, bo wewnętrznie liczyliśmy od 0.
        cout << wynik[a] + 1 << "\n";
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

    return 0;
}
