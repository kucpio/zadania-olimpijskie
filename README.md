# Zadania z Olimpiady Informatycznej i Potyczek Algorytmicznych

Repozytorium zawiera rozwiązania wybranych zadań z:
- Olimpiady Informatycznej (OI)
- Potyczek Algorytmicznych

To rozwiązania konkursowe: kod jest pisany pod wydajność, a nie czytelność, dlatego w większości przypadków nie zawiera komentarzy.

Pelne tresci zadan mozna znalezc w serwisie Szkopul:
https://szkopul.edu.pl

---

## Srodowisko

Jezyk: C++17

Przykladowa kompilacja i uruchomienie:

```bash
g++ -std=c++17 -O2 solution.cpp -o sol
./sol < input.txt

1) Rozklad Fibonacciego

Problem:
Dla kazdej liczby k wykonujemy kroki prowadzace do zera. W jednym kroku mozna przejsc do wartosci |k - F|, gdzie F jest dowolna liczba Fibonacciego. Celem jest minimalna liczba krokow.

Rozwiazanie (idea):

Najpierw generowane sa liczby Fibonacciego do zakresu typu long long.

Nastepnie wykonujemy petle: dla aktualnego k wybieramy takie F, aby roznica |k - F| byla minimalna.

Aktualizujemy k na te minimalna roznice i zwiekszamy licznik krokow.

Zastosowane techniki:

preprocessing liczb Fibonacciego

algorytm zachlanny (greedy)

arytmetyka long long

2) Szeregowanie czynnosci

Problem:
Dane sa pary (a, b). Nalezy posortowac elementy wedlug wartosci ilorazu a/b. Remisy rozstrzygane sa po indeksie (kolejnosci wejsciowej).

Rozwiazanie (idea):

Zamiast porownywac a/b wprost (dzielenie i bledy precyzji), porownujemy ulamki przez mnozenie krzyzowe:
porownujemy a1b2 z a2b1.

Sortowanie wykonuje std::sort z wlasnym komparatorem.

Zastosowane techniki:

sortowanie O(n log n)

porownywanie ulamkow bez dzielenia (mnozenie krzyzowe)

wlasny comparator

Zastosowania:

geometria obliczeniowa (porownywanie nachylen)

zadania z unikaniem bledow zmiennoprzecinkowych

3) Tetris Attack

Problem:
Dany jest ciag dlugosci 2n, gdzie kazda liczba wystepuje dokladnie dwa razy. Nalezy zasymulowac operacje dopasowywania/usuwania par zgodnie z warunkami zadania i wypisac wynikowe informacje (np. stany w trakcie).

Rozwiazanie (idea):

Symulacja oparta na tablicy jako stosie oraz tablicy znacznikow "czy element juz jest aktywny".

Algorytm operuje na wskaznikach i tablicach, bez ciezkich struktur STL.

Logika dopasowan przypomina zadania typu "parowanie nawiasow" lub "redukcja przez stos".

Zastosowane techniki:

symulacja stosu

tablice pomocnicze

podejscie liniowe (w praktyce)

4) Trojkaty jednobarwne

Problem:
Policzyc liczbe trojkatow w grafie nieskierowanym.

Rozwiazanie (idea):

Zamiast sprawdzac wszystkie trojki wierzcholkow (O(n^3)), korzystamy z kombinatoryki.

Liczymy liczbe wszystkich trojek wierzcholkow: n*(n-1)*(n-2)/6.

Nastepnie odejmujemy te trojki, ktore na pewno nie tworza trojkata, korzystajac ze stopni wierzcholkow.

Zastosowane techniki:

kombinatoryka

stopnie wierzcholkow

liczenie przez dopelnienie

Zlozonosc:

O(n + m)

5) Wiedzmak

Problem:
Najkrotsza sciezka w grafie, gdzie kazda krawedz ma koszt oraz wymaga posiadania pewnego zestawu umiejetnosci/przedmiotow. Umiejetnosci mozna zdobywac w miastach.

Rozwiazanie (idea):

Dijkstra na grafie stanow.

Stan to (miasto, maska_umiejetnosci), gdzie maska to bitmask.

Przejscie krawedzia jest mozliwe tylko jesli aktualna maska zawiera wszystkie wymagane bity.

Po wejsciu do miasta maska aktualizuje sie przez OR z umiejetnosciami miasta.

Zastosowane techniki:

Dijkstra + priority_queue

bitmaski

graf stanow (state-space graph)

Zlozonosc:

w przyblizeniu O((n2^p + m2^p) log(n*2^p)), gdzie p <= 13

6) Zima

Problem:
Drzewo z wagami krawedzi, gdzie parzystosc wagi zmienia sposob liczenia wyniku. Nalezy policzyc wynik globalny i "odjac" najlepsza mozliwa sciezke korygujaca.

Rozwiazanie (idea):

Najpierw liczone sa bazowe sumy wkladow wszystkich krawedzi (oddzielnie dla parzystych/nieparzystych).

DFS + DP na drzewie: dla kazdego wierzcholka trzymamy dwie najlepsze wartosci sciezek schodzacych w dol.

Z dwoch najlepszych sciezek skladamy najlepsza sciezke przechodzaca przez dany wierzcholek (motyw najlepszej sciezki w drzewie).

Zastosowane techniki:

DFS

DP na drzewie

wybieranie 2 najlepszych kandydatow z dzieci

Zlozonosc:

O(n)

7) Zajakniecia

Problem:
Dwa ciagi liczb. Celem jest maksymalizacja liczby dopasowanych "powtorzen" (par wystapien tej samej wartosci) w obu ciagach z zachowaniem kolejnosci.

Rozwiazanie (idea):

Dla kazdej pozycji wyznaczamy poprzednie wystapienie tej samej wartosci (preprocessing).

Nastepnie DP, podobne do LCS, ale z dodatkowymi warunkami, ktore pilnuja poprawnego skladania "drugich wystapien" i porzadku.

Wynik jest mnozony przez 2, bo kazde dopasowanie odpowiada parze elementow.

Zastosowane techniki:

DP na sekwencjach

poprzednie wystapienia

wariant LCS z ograniczeniami

8) Zdjecia krasnali

Problem:
Dany graf nieskierowany. Trzeba sprobowac skierowac wszystkie krawedzie zgodnie z warunkami konstrukcji. Jesli sie nie da, wypisac "NIE". Jesli sie da, wypisac "TAK" oraz numeracje wierzcholkow wynikajaca z porzadku topologicznego.

Rozwiazanie (idea):

Budujemy graf skierowany metoda konstrukcyjna z uzyciem kolejki (BFS) i lokalnych warunkow.

Po zbudowaniu grafu liczymy stopnie wejsciowe i wykonujemy sortowanie topologiczne algorytmem Kahna.

Numeracja to pozycja w kolejnosci topologicznej.

Zastosowane techniki:

konstrukcja + BFS/queue

topological sort (Kahn)

graf jako listy sasiedztwa

Zlozonosc:

O(n + m)

9) Drogi rowerowe

Problem:
Graf skierowany. Dla kazdego wierzcholka trzeba policzyc wynik zwiazany z osiagalnoscia. Rozwiazanie operuje na SCC i wyniki przypisuje wierzcholkom.

Rozwiazanie (idea):

SCC (Kosaraju): DFS po grafie, potem DFS po grafie odroconym w odwrotnej kolejnosci zakonczen.

Budowa grafu kondensacji SCC (DAG).

Sortowanie topologiczne DAG.

DP po DAG (propagacja wynikow miedzy skladowymi).

Wynik wierzcholka zalezy od jego skladowej SCC.

Zastosowane techniki:

SCC (Kosaraju)

kondensacja do DAG

topological sort

DP po DAG

Zlozonosc:

O(n + m)

10) Marudny Bajtazar

Problem:
Dany binarny napis dlugosci n i m operacji flip (zamiana 0<->1 na pozycji). Po kazdej operacji (oraz na poczatku) trzeba znalezc najmniejsza dlugosc i, dla ktorej nie wszystkie binarne podciagi spojne dlugosci i wystepuja w napisie.

Rozwiazanie (idea):

Ustawiamy k = min(17, n).

Utrzymujemy liczniki wystapien wszystkich wzorcow dlugosci 1..k.

Wzorce kodujemy w stylu "trie w tablicy" (pelne drzewo binarne), a dla kazdej dlugosci len trzymamy liczbe roznych wzorcow, ktore wystepuja.

Flip w pozycji p wplywa tylko na podciagi, ktore przecinaja p: usuwamy ich wklad, flipujemy bit, dodajemy wklad ponownie.

Odpowiedz to najmniejsze len, dla ktorego liczba roznych wzorcow < 2^len.

Zastosowane techniki:

bitowe kodowanie podciagow

trie w tablicy / liczniki wzorcow

aktualizacje lokalne po flipie

11) Minusy

Problem:
Dane n oraz n-1 znakow +/-. Nalezy skonstruowac wynik z myslnikow i nawiasow, wstawiajac nawiasy w momentach przejsc miedzy znakami.

Rozwiazanie (idea):

Jedno przejscie po znakach.

Flaga mowi, czy jestesmy w nawiasie.

Przy + otwieramy nawias (jesli nie jest otwarty), przy - zamykamy (jesli jest otwarty), a w kazdym kroku wypisujemy "-".

Zastosowane techniki:

prosta symulacja

automat dwustanowy

Zlozonosc:

O(n)

12) Bony

Problem:
Symulacja zaznaczania (sprzedazy) liczb bedacych wielokrotnosciami kolejnych wartosci w oraz rejestrowanie momentow trafienia na specjalne ("wygrywajace") pozycje.

Rozwiazanie (idea):

sprzedane[x] blokuje ponowne zaznaczenie tej samej liczby.

ostatni[w] pamieta od ktorej wielokrotnosci kontynuowac dla danego w (amortyzacja).

Iterujemy po wielokrotnosciach w, sprzedajemy kolejne nie-sprzedane pozycje, i zapisujemy momenty trafien na wygrywajace.

Zastosowane techniki:

przechodzenie po wielokrotnosciach

visited array

pamietanie postepu (amortyzacja)
