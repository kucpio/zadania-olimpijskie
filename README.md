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

Opis zadan i rozwiazan
1. Rozklad Fibonacciego

Opis problemu

Dana jest liczba k. W jednym kroku mozna przejsc do wartosci |k - F|, gdzie F jest dowolna liczba Fibonacciego. Nalezy wyznaczyc minimalna liczbe krokow potrzebnych do sprowadzenia k do zera.

Idea rozwiazania

Najpierw generujemy liczby Fibonacciego w zakresie typu long long. W kazdym kroku wybieramy taka liczbe F, ktora minimalizuje wartosc |k - F|. Proces powtarzamy az do uzyskania zera.

Jest to strategia zachlanna (greedy).

Zastosowane techniki

preprocessing liczb Fibonacciego

algorytm zachlanny

operacje na long long

Zlozonosc

W praktyce bardzo mala, liczba Fibonaccich jest stala (ok. 90).

2. Szeregowanie czynnosci

Opis problemu

Dane sa pary liczb (a, b). Nalezy posortowac je wedlug wartosci ilorazu a/b. W przypadku remisu decyduje kolejnosc wejsciowa.

Idea rozwiazania

Zamiast liczyc a/b bezposrednio (ryzyko bledow precyzji), porownujemy ulamki przez mnozenie krzyzowe:

a1/b1 < a2/b2 wtedy i tylko wtedy, gdy a1 * b2 < a2 * b1.

Sortowanie realizowane jest przez std::sort z wlasnym komparatorem.

Zastosowane techniki

sortowanie O(n log n)

mnozenie krzyzowe zamiast dzielenia

wlasny comparator

Zlozonosc

O(n log n)

3. Tetris Attack

Opis problemu

Dany jest ciag dlugosci 2n, w ktorym kazda liczba wystepuje dokladnie dwa razy. Nalezy symulowac proces dopasowywania par i raportowac kolejne stany.

Idea rozwiazania

Algorytm wykorzystuje tablice jako stos oraz tablice znacznikow informujaca, czy dany element jest aktualnie aktywny. Operacje sa wykonywane liniowo, bez uzycia zlozonych struktur STL.

Logika przypomina redukcje nawiasow przy pomocy stosu.

Zastosowane techniki

symulacja

stos zaimplementowany jako tablica

przetwarzanie liniowe

Zlozonosc

W praktyce O(n)

4. Trojkaty jednobarwne

Opis problemu

Policzyc liczbe trojkatow w grafie nieskierowanym.

Idea rozwiazania

Zamiast sprawdzac wszystkie trojki wierzcholkow, liczymy liczbe wszystkich mozliwych trojek wierzcholkow, a nastepnie odejmujemy te, ktore nie moga tworzyc trojkata. Wykorzystujemy stopnie wierzcholkow i kombinatoryke.

Zastosowane techniki

kombinatoryka

liczenie przez dopelnienie

analiza stopni wierzcholkow

Zlozonosc

O(n + m)

5. Wiedzmak

Opis problemu

Najkrotsza sciezka w grafie, gdzie krawedzie wymagaja posiadania okreslonych umiejetnosci, a umiejetnosci mozna zdobywac w miastach.

Idea rozwiazania

Wykorzystujemy Dijkstre na grafie stanow. Stan to para (miasto, maska_umiejetnosci). Maska reprezentuje zbior zdobytych umiejetnosci w postaci bitmaski.

Przejscie krawedzia jest mozliwe tylko wtedy, gdy aktualna maska zawiera wszystkie wymagane bity.

Zastosowane techniki

Dijkstra

bitmaski

graf stanow

Zlozonosc

W przyblizeniu O((n * 2^p + m * 2^p) log(n * 2^p)), gdzie p <= 13.

6. Zima

Opis problemu

Drzewo z wagami krawedzi. Parzystosc wag wplywa na sposob liczenia wyniku. Nalezy znalezc najlepsza sciezke, ktora maksymalnie koryguje wynik globalny.

Idea rozwiazania

Najpierw liczymy sume bazowa. Nastepnie wykonujemy DFS i DP na drzewie, dla kazdego wierzcholka przechowujac dwie najlepsze wartosci sciezek schodzacych w dol. Z nich budujemy najlepsza sciezke przechodzaca przez dany wierzcholek.

Zastosowane techniki

DFS

DP na drzewie

motyw srednicy drzewa

Zlozonosc

O(n)

7. Zajakniecia

Opis problemu

Dwa ciagi liczb. Nalezy zmaksymalizowac liczbe dopasowanych powtorzen tej samej wartosci w obu ciagach.

Idea rozwiazania

Wyznaczamy poprzednie wystapienia kazdej wartosci, a nastepnie stosujemy dynamic programming podobne do LCS, z dodatkowymi warunkami dotyczacymi poprawnego laczenia par.

Zastosowane techniki

DP na sekwencjach

poprzednie wystapienia

wariant LCS

8. Zdjecia krasnali

Opis problemu

Dany graf nieskierowany. Nalezy sprobowac skierowac jego krawedzie zgodnie z warunkami konstrukcji, a nastepnie wyznaczyc numeracje wierzcholkow.

Idea rozwiazania

Najpierw konstruujemy graf skierowany przy pomocy BFS i warunkow lokalnych. Nastepnie wykonujemy sortowanie topologiczne (algorytm Kahna). Jesli konstrukcja nie jest mozliwa, wypisujemy NIE.

Zastosowane techniki

BFS

konstrukcja grafu

topological sort

Zlozonosc

O(n + m)

9. Drogi rowerowe

Opis problemu

Graf skierowany. Dla kazdego wierzcholka nalezy policzyc wynik zwiazany z osiagalnoscia.

Idea rozwiazania

Najpierw wyznaczamy silnie spojne skladowe (Kosaraju). Budujemy graf kondensacji (DAG), wykonujemy sortowanie topologiczne, a nastepnie DP po DAG.

Zastosowane techniki

SCC (Kosaraju)

kondensacja do DAG

topological sort

DP po DAG

Zlozonosc

O(n + m)

10. Marudny Bajtazar

Opis problemu

Dany jest binarny napis oraz operacje zmiany pojedynczych bitow. Po kazdej zmianie nalezy znalezc najmniejsza dlugosc podciagu, dla ktorej nie wszystkie mozliwe wzorce wystepuja w napisie.

Idea rozwiazania

Ograniczamy maksymalna dlugosc do 17. Utrzymujemy licznik wystapien wszystkich podciagow dlugosci 1..k. Wzorce kodujemy jako liczby binarne w strukturze przypominajacej trie zapisane w tablicy.

Po zmianie bitu aktualizujemy tylko lokalnie dotkniete podciagi.

Zastosowane techniki

bitmaski

trie w tablicy

aktualizacje lokalne

11. Minusy

Opis problemu

Na podstawie ciagu znakow + i - nalezy skonstruowac wynikowy ciag z nawiasami i myslnikami zgodnie z przejsciami miedzy znakami.

Idea rozwiazania

Jedno przejscie po danych oraz automat dwustanowy okreslajacy, czy aktualnie jestesmy w nawiasie.

Zlozonosc

O(n)

12. Bony

Opis problemu

Symulacja zaznaczania wielokrotnosci liczb oraz rejestrowania momentow trafienia na specjalne pozycje.

Idea rozwiazania

Dla kazdej liczby w przechodzimy po jej wielokrotnosciach, oznaczamy jeszcze nieuzyte pozycje oraz zapisujemy trafienia. Dodatkowo zapamietujemy ostatnia sprawdzana wielokrotnosc, co daje efekt amortyzacji.

Zastosowane techniki

przechodzenie po wielokrotnosciach

visited array

amortyzacja
