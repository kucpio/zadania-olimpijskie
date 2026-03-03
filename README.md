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

📚 Lista zadań i zastosowane algorytmy
1) Rozkład Fibonacciego

Problem (skrót):
Dla każdej liczby k wykonujemy operacje prowadzące do zera, gdzie w jednym kroku możemy przejść do |k - F| dla dowolnej liczby Fibonacciego F. Celem jest minimalna liczba kroków.

Rozwiązanie / pomysł:

Generowanie liczb Fibonacciego (preprocessing) do zakresu long long.

Strategia zachłanna (greedy): w każdym kroku wybieramy F, które minimalizuje |k - F|, i aktualizujemy k.

Zliczamy liczbę iteracji do osiągnięcia zera.

Techniki: preprocessing, greedy, arytmetyka na long long.

2) Szeregowanie czynności

Problem (skrót):
Dane są elementy opisane parametrami (a, b). Należy je posortować według wartości ilorazu a / b (z remisem rozstrzyganym po indeksie wejściowym).

Rozwiązanie / pomysł:
Zamiast porównywać wartości zmiennoprzecinkowe a / b bezpośrednio, stosujemy porównywanie ułamków przez mnożenie krzyżowe:

porównujemy a1/b1 i a2/b2 przez sprawdzenie a1 * b2 vs a2 * b1.

To eliminuje dzielenie i ogranicza problemy z precyzją.

Techniki: std::sort, własny komparator, mnożenie krzyżowe.

Złożoność: O(n log n).

3) Tetris Attack

Problem (skrót):
Dany jest ciąg długości 2n, w którym każda liczba występuje dokładnie dwa razy. Należy zasymulować proces dopasowywania/usuwania par zgodnie z regułami zadania i wypisać kolejne stany (np. rozmiar struktury w trakcie).

Rozwiązanie / pomysł:

Symulacja z użyciem tablicy jako stosu (dol[]).

Tablica jest[] trzyma informację, czy element znajduje się “aktywnie” w strukturze.

Przetwarzanie odbywa się wskaźnikami (bez ciężkich struktur), z lokalnymi cofnięciami i dopinaniem elementów.

Techniki: symulacja, stos, przetwarzanie liniowe na tablicach.

Złożoność: w praktyce liniowa względem n.

4) Trójkąty jednobarwne

Problem (skrót):
Policzyć liczbę trójkątów w grafie nieskierowanym.

Rozwiązanie / pomysł:
Zamiast sprawdzać wszystkie trójki wierzchołków (co byłoby O(n^3)), używamy kombinatoryki i liczenia “dopełnieniem”:

liczba wszystkich trójek to C(n, 3),

odejmujemy trójki, które na pewno nie są trójkątami, wykorzystując stopnie wierzchołków.

Techniki: kombinatoryka, stopnie wierzchołków, liczenie dopełnienia.

Złożoność: O(n + m).

5) Wiedźmak

Problem (skrót):
Najkrótsza ścieżka w grafie, gdzie każda krawędź ma koszt oraz wymaga posiadania pewnego zestawu umiejętności/przedmiotów. Umiejętności można “zbierać” w miastach.

Rozwiązanie / pomysł:
Klasyczna Dijkstra na grafie stanów:

stan to para (miasto, maska_umiejętności),

przejście krawędzią jest możliwe tylko, jeśli aktualna maska zawiera wymagane bity,

po wejściu do miasta aktualizujemy maskę przez OR z umiejętnościami tego miasta.

Techniki: Dijkstra, bitmaski, graf stanów, priority_queue.

Złożoność: w przybliżeniu O((n * 2^p + m * 2^p) log(n * 2^p)), gdzie p <= 13.

6) Zima

Problem (skrót):
Drzewo z wagami krawędzi; wagi traktowane są różnie zależnie od parzystości. Trzeba wyznaczyć wynik globalny oparty o sumę wag oraz najlepszą możliwą ścieżkę “korygującą” wynik.

Rozwiązanie / pomysł:

Najpierw liczymy bazową sumę wkładów wszystkich krawędzi (osobno parzyste i nieparzyste).

Następnie DFS + DP na drzewie: dla każdego wierzchołka trzymamy dwie najlepsze wartości ścieżek schodzących w dół.

Z tych dwóch wartości składamy najlepszą ścieżkę przechodzącą przez wierzchołek (wariant “najlepszej ścieżki w drzewie”).

Techniki: DFS, DP na drzewie, wybór 2 najlepszych dzieci.

Złożoność: O(n).

7) Zająknięcia

Problem (skrót):
Dwa ciągi liczb. Celem jest maksymalizacja liczby dopasowanych “powtórzeń” (par wystąpień tej samej wartości) w obu ciągach z zachowaniem kolejności.

Rozwiązanie / pomysł:

Preprocessing: dla każdej pozycji zapamiętujemy indeks poprzedniego wystąpienia tej samej wartości.

Następnie DP po parach pozycji z dodatkowymi warunkami poprawności (żeby dopasowywać drugie wystąpienia i nie łamać kolejności).

Wynik jest mnożony przez 2, bo każda dopasowana struktura odpowiada parze wystąpień.

Techniki: DP na sekwencjach, poprzednie wystąpienia, wariant LCS z ograniczeniami.

8) Zdjęcia krasnali

Problem (skrót):
Dany graf nieskierowany. Należy spróbować skierować wszystkie krawędzie zgodnie z regułami konstrukcji. Jeśli się nie da — wypisać NIE. Jeśli się da — wypisać TAK oraz numerację wierzchołków wynikającą z porządku topologicznego powstałego grafu skierowanego.

Rozwiązanie / pomysł:

Konstrukcja grafu skierowanego przy użyciu kolejki (BFS) i lokalnych warunków (zliczanie wybranych krawędzi).

Po zbudowaniu grafu skierowanego liczymy stopnie wejściowe i robimy topological sort (Kahn).

Numeracja wierzchołków to pozycja w kolejności topologicznej.

Techniki: konstrukcja, BFS/queue, topological sort.

Złożoność: O(n + m).

9) Drogi rowerowe

Problem (skrót):
Dla każdego wierzchołka w grafie skierowanym obliczamy wartość zależną od osiągalności (w praktyce: wynik jest liczony na poziomie SCC i następnie przypisywany wierzchołkom).

Rozwiązanie / pomysł:
Klasyczny pipeline:

SCC (Kosaraju): DFS po grafie, potem DFS po grafie odwróconym w kolejności kończenia.

Budowa grafu kondensacji (DAG silnie spójnych składowych).

Topological sort DAG.

DP po DAG (propagacja wyników po składowych).

Odpowiedź dla wierzchołka v zależy od jego składowej SCC.

Techniki: SCC, kondensacja, topological sort, DP po DAG.

Złożoność: O(n + m).

10) Marudny Bajtazar

Problem (skrót):
Dany jest binarny napis długości n oraz m operacji flip (zamiana 0 <-> 1 na pozycji). Po każdej operacji (oraz na początku) trzeba znaleźć najmniejszą długość i, dla której nie wszystkie binarne podciągi spójne długości i występują w napisie.

Rozwiązanie / pomysł:

Ograniczamy się do k = min(17, n) (dla większych długości liczba wzorców rośnie zbyt szybko, a do odpowiedzi i tak wystarczy małe k).

Dla wszystkich startów podciągów utrzymujemy liczniki wystąpień wzorców długości 1..k.

Wzorce kodujemy jako ścieżkę w pełnym drzewie binarnym (trie w tablicy), a ip[len] trzyma liczbę różnych wzorców długości len.

Flip wpływa tylko na podciągi w okolicy pozycji: usuwamy ich wkład, flipujemy bit, dodajemy wkład z powrotem.

Techniki: bitmaskowanie podciągów, trie w tablicy, aktualizacje lokalne.

Złożoność: inicjalizacja O(n * k), jedna zmiana amortyzacyjnie stała (dla k <= 17 bardzo szybka).

11) Minusy

Problem (skrót):
Dane n oraz n-1 znaków +/-. Należy skonstruować wynik (ciąg znaków - z nawiasami), wstawiając nawiasy zależnie od przejść między + i -.

Rozwiązanie / pomysł:

Jedno przejście po wejściu.

Flaga oznacza, czy aktualnie jesteśmy “w nawiasie”.

Przy + otwieramy nawias, przy - domykamy (gdy trzeba), a w każdym kroku wypisujemy -.

Techniki: prosta symulacja / automat dwustanowy.

Złożoność: O(n).

12) Bony

Problem (skrót):
Symulacja procesu zaznaczania (sprzedaży) liczb będących wielokrotnościami kolejnych wartości w oraz rejestrowanie momentów trafienia na specjalne (“wygrywające”) pozycje.

Rozwiązanie / pomysł:

sprzedane[x] blokuje ponowne “sprzedanie” tej samej pozycji.

ostatni[w] pamięta, od której wielokrotności kontynuować dla danego w (amortyzacja).

Gdy trafiamy na pozycję oznaczoną jako wygrywająca, zapisujemy wynik zależny od sumy dotychczasowych kroków.

Techniki: przejście po wielokrotnościach, visited array, pamiętanie postępu.
