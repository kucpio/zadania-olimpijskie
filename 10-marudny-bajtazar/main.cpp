/*
    Opis problemu:
    Dany jest binarny napis długości n. Następnie wykonujemy m operacji,
    z których każda zmienia jeden znak ('0' na '1' albo '1' na '0').
    Po stanie początkowym oraz po każdej zmianie trzeba wyznaczyć
    najmniejszą długość takiego binarnego podciągu spójnego, który
    nie występuje w aktualnym napisie.

    Idea rozwiązania:
    Dla każdej pozycji traktujemy kolejne fragmenty długości 1..k
    jako liczby binarne i zapisujemy informację, które wzorce występują.
    Nie ma sensu sprawdzać długości większych niż 17, bo liczba wszystkich
    wzorców rośnie wykładniczo, a dla danych ograniczeń wystarczy obserwować
    tylko krótkie fragmenty.

    Każdy fragment kodujemy jak przejście po pełnym drzewie binarnym:
    - przejście w lewo odpowiada znakowi '0',
    - przejście w prawo odpowiada znakowi '1'.
    Tablica drzewo[] zlicza, ile razy dany wzorzec występuje,
    a ip[len] przechowuje liczbę różnych wzorców długości len,
    które aktualnie pojawiają się w napisie.

    Jeśli dla pewnej długości len liczba różnych obecnych wzorców jest
    mniejsza niż 2^len, to znaczy, że istnieje jakiś binarny napis długości len,
    który nie występuje. Szukamy najmniejszego takiego len.

    Po zmianie jednego znaku nie trzeba przeliczać wszystkiego od nowa.
    Wystarczy usunąć i dodać ponownie tylko te fragmenty, które przechodzą
    przez zmienioną pozycję, czyli zaczynają się w odpowiednim przedziale.

    Zastosowane techniki:
    - kodowanie binarnych podciągów jako wierzchołków pełnego drzewa binarnego,
    - zliczanie różnych występujących wzorców,
    - aktualizacja lokalna po pojedynczej zmianie,
    - ograniczenie długości analizowanych fragmentów do stałej wartości.
*/

#include  <bits/stdc++.h>

using namespace std;

const int maxK = 17;
constexpr int maxM = 10e4 + 7;
constexpr int maxR = (1 << (maxK + 1)) + 7;

int n, m, k;
string s = "0";

// Pozycje kolejnych zmian w napisie.
int zamiany[maxM] = {0};

// drzewo[x] = ile razy występuje wzorzec zakodowany przez wierzchołek x.
int drzewo[maxR] = {0};

// ip[len] = liczba różnych wzorców długości len, które występują w napisie.
int ip[maxK + 1];

void wczytaj() {
    string w;

    cin >> n >> m >> w;

    for (int i = 1; i <= m; i++)
        cin >> zamiany[i];

    // Sprawdzamy tylko długości do 17.
    k = min(maxK, n);

    // Przechodzimy na indeksowanie od 1.
    s += w;

    // Dopisujemy kilka zer na końcu, żeby bezpiecznie czytać krótkie końcówki.
    for (int i = 1; i <= maxK + 7; i++)
        s += "0";
}

// Dodaje albo usuwa wszystkie prefiksy długości 1..k
// zaczynające się w pozycji p.
void dodaj(int p, int op)
{
    int x = 0;  // numer aktualnego wierzchołka w drzewie binarnym
    int l = 0;  // długość aktualnego wzorca

    for (int i = p; i <= p + k - 1 && i <= n; i++)
    {
        l++;

        // Przejście po pełnym drzewie binarnym:
        // '0' -> lewe dziecko, '1' -> prawe dziecko.
        if (s[i] == '0')
            x += x + 1;
        else
            x += x + 2;

        if (op > 0)
        {
            // Jeśli wzorzec pojawia się pierwszy raz,
            // zwiększamy liczbę różnych wzorców tej długości.
            if (!drzewo[x])
                ip[l]++;
            drzewo[x]++;
        }
        else if (op < 0)
        {
            drzewo[x]--;

            // Jeśli wzorzec właśnie zniknął całkowicie,
            // zmniejszamy liczbę różnych wzorców tej długości.
            if (!drzewo[x])
                ip[l]--;
        }
    }
}

// Buduje początkowe zliczenia dla całego napisu.
void zaaktualizuj()
{
    for (int i = 1; i <= n; i++)
        dodaj(i, +1);
}

// Aktualizacja po zmianie znaku na pozycji p.
void zamien_popraw(int p)
{
    int l, r;

    // Tylko fragmenty zaczynające się w tym zakresie
    // mogą zawierać pozycję p.
    l = max(1, p - k + 1);
    r = min(p + k - 2, n);

    // Usuwamy stare wersje tych fragmentów.
    for (int i = l; i <= r; i++)
        dodaj(i, -1);

    // Zmieniamy znak.
    if (s[p] == '1')
        s[p] = '0';
    else
        s[p] = '1';

    // Dodajemy nowe wersje fragmentów.
    for (int i = l; i <= r; i++)
        dodaj(i, 1);
}

// Szuka najmniejszej długości, dla której nie występują wszystkie wzorce.
int znajdz()
{
    for (int i = 1; i <= k; i++)
    {
        if (ip[i] < (1 << i))
            return i;
    }
    
    // Dla pełnej poprawności można by tu zwrócić k+1,
    // ale dla założeń zadania wystarczy istniejące zachowanie.
    return k + 1;
}

void policz()
{
    cout << znajdz() << "\n";

    for (int i = 1; i <= m; i++)
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

    return 0;
}
