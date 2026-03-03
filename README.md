# Rozwiązania zadań z Olimpiady Informatycznej i Potyczek Algorytmicznych

Repozytorium zawiera autorskie rozwiązania wybranych zadań z:

- Olimpiady Informatycznej (OI)
- Potyczek Algorytmicznych

Rozwiązania mają charakter konkursowy – kod jest pisany pod wydajność oraz limity czasowe i pamięciowe, dlatego w większości przypadków nie zawiera komentarzy. Struktura i styl implementacji odpowiadają standardom programowania stosowanym podczas zawodów algorytmicznych.

Pełne treści zadań dostępne są w serwisie:
https://szkopul.edu.pl

---

## Środowisko

Język: C++17

Przykładowa kompilacja:

```bash
g++ -std=c++17 -O2 solution.cpp -o sol
./sol < input.txt
```

---

# Opis zadań i zastosowanych technik

---

## 1. Rozkład Fibonacciego

### Opis problemu

Dana jest liczba `k`. W jednym kroku można przejść do wartości `|k - F|`, gdzie `F` jest dowolną liczbą Fibonacciego. Należy wyznaczyć minimalną liczbę kroków potrzebnych do sprowadzenia liczby do zera.

### Idea rozwiązania

Najpierw generowane są liczby Fibonacciego w zakresie typu `long long`. W każdej iteracji wybierana jest taka liczba Fibonacciego, która minimalizuje wartość `|k - F|`. Proces powtarzany jest do momentu uzyskania zera.

Zastosowana strategia ma charakter zachłanny (greedy).

### Zastosowane techniki

- preprocessing liczb Fibonacciego  
- algorytm zachłanny  
- operacje na typie `long long`  

---

## 2. Szeregowanie czynności

### Opis problemu

Dane są pary liczb `(a, b)`. Należy posortować elementy według wartości ilorazu `a / b`. W przypadku remisu decyduje kolejność wejściowa.

### Idea rozwiązania

Zamiast wykonywać dzielenie (co mogłoby prowadzić do błędów precyzji), porównywane są ułamki poprzez mnożenie krzyżowe:

`a1 / b1 < a2 / b2` wtedy i tylko wtedy, gdy `a1 * b2 < a2 * b1`.

Sortowanie realizowane jest przy użyciu `std::sort` z własnym komparatorem.

### Zastosowane techniki

- sortowanie w czasie O(n log n)  
- porównywanie ułamków bez użycia dzielenia  
- własna funkcja porównująca  

---

## 3. Tetris Attack

### Opis problemu

Dany jest ciąg długości `2n`, w którym każda liczba występuje dokładnie dwa razy. Należy zasymulować proces dopasowywania i usuwania par zgodnie z określonymi zasadami.

### Idea rozwiązania

Rozwiązanie wykorzystuje tablicę jako stos oraz tablicę znaczników informującą, czy dany element znajduje się aktualnie w strukturze. Operacje realizowane są w sposób liniowy, bez użycia złożonych struktur STL.

Logika przetwarzania przypomina klasyczne zadania związane z redukcją wyrażeń przy pomocy stosu.

### Zastosowane techniki

- symulacja  
- implementacja stosu przy użyciu tablicy  
- przetwarzanie liniowe  

---

## 4. Trójkąty jednobarwne

### Opis problemu

Należy policzyć liczbę trójkątów w grafie nieskierowanym.

### Idea rozwiązania

Zamiast sprawdzać wszystkie trójki wierzchołków (co prowadziłoby do złożoności O(n³)), wykorzystywana jest kombinatoryka.

Najpierw obliczana jest liczba wszystkich możliwych trójek wierzchołków:
`n * (n - 1) * (n - 2) / 6`.

Następnie odejmowane są trójki, które nie mogą tworzyć trójkąta, z wykorzystaniem stopni wierzchołków.

### Zastosowane techniki

- kombinatoryka  
- liczenie przez dopełnienie  
- analiza stopni wierzchołków  

### Złożoność

O(n + m)

---

## 5. Wiedźmak

### Opis problemu

Należy wyznaczyć najkrótszą ścieżkę w grafie, gdzie każda krawędź ma koszt oraz wymaga posiadania określonego zestawu umiejętności. Umiejętności można zdobywać w wybranych wierzchołkach.

### Idea rozwiązania

Zastosowana została Dijkstra na rozszerzonym grafie stanów.

Stan reprezentowany jest jako para:
(wierzchołek, maska_umiejętności).

Maska umiejętności kodowana jest jako bitmask. Przejście krawędzią możliwe jest tylko wtedy, gdy aktualna maska zawiera wszystkie wymagane bity.

### Zastosowane techniki

- algorytm Dijkstry  
- bitmaski  
- graf stanów  
- `priority_queue`  

### Złożoność

W przybliżeniu  
O((n * 2^p + m * 2^p) log(n * 2^p)), gdzie p ≤ 13.

---

## 6. Zima

### Opis problemu

Dane jest drzewo z wagami krawędzi. Parzystość wag wpływa na sposób liczenia wyniku końcowego. Należy wyznaczyć optymalną ścieżkę maksymalizującą korektę globalnego wyniku.

### Idea rozwiązania

Najpierw obliczana jest suma bazowa wszystkich krawędzi. Następnie wykonywany jest DFS oraz dynamic programming na drzewie.

Dla każdego wierzchołka przechowywane są dwie najlepsze wartości ścieżek schodzących w dół. Na tej podstawie wyznaczana jest najlepsza ścieżka przechodząca przez dany wierzchołek.

### Zastosowane techniki

- DFS  
- DP na drzewie  
- motyw maksymalnej ścieżki w drzewie  

### Złożoność

O(n)

---

## 7. Zająknięcia

### Opis problemu

Dane są dwa ciągi liczb. Celem jest maksymalizacja liczby dopasowanych powtórzeń tej samej wartości w obu ciągach, z zachowaniem kolejności.

### Idea rozwiązania

Dla każdej pozycji wyznaczane jest poprzednie wystąpienie tej samej wartości. Następnie stosowane jest dynamic programming podobne do LCS, lecz rozszerzone o dodatkowe warunki zapewniające poprawne łączenie par.

### Zastosowane techniki

- dynamic programming na sekwencjach  
- przechowywanie poprzednich wystąpień  
- wariant problemu LCS  

---

## 8. Zdjęcia krasnali

### Opis problemu

Dany jest graf nieskierowany. Należy spróbować skierować jego krawędzie zgodnie z warunkami zadania. Jeśli konstrukcja jest niemożliwa – wypisać „NIE”. W przeciwnym razie należy wyznaczyć numerację wierzchołków.

### Idea rozwiązania

Najpierw konstruowany jest graf skierowany przy użyciu BFS oraz odpowiednich warunków lokalnych. Następnie wykonywane jest sortowanie topologiczne (algorytm Kahna).

### Zastosowane techniki

- BFS  
- konstrukcja grafu  
- topological sort  

### Złożoność

O(n + m)

---

## 9. Drogi rowerowe

### Opis problemu

Dany jest graf skierowany. Dla każdego wierzchołka należy obliczyć wartość związaną z osiągalnością.

### Idea rozwiązania

Najpierw wyznaczane są silnie spójne składowe (algorytm Kosaraju). Następnie budowany jest graf kondensacji (DAG). Wykonywane jest sortowanie topologiczne oraz dynamic programming po DAG.

### Zastosowane techniki

- SCC (Kosaraju)  
- graf kondensacji  
- sortowanie topologiczne  
- DP po DAG  

### Złożoność

O(n + m)

---

## 10. Marudny Bajtazar

### Opis problemu

Dany jest binarny napis oraz operacje zmiany pojedynczych bitów. Po każdej zmianie należy znaleźć najmniejszą długość podciągu, dla której nie wszystkie możliwe wzorce występują w napisie.

### Idea rozwiązania

Ograniczona zostaje maksymalna długość analizowanych podciągów do 17. Utrzymywany jest licznik wystąpień wszystkich podciągów długości od 1 do k.

Wzorce kodowane są jako liczby binarne w strukturze przypominającej trie zapisane w tablicy. Po zmianie bitu aktualizowane są jedynie lokalne fragmenty.

### Zastosowane techniki

- bitmaski  
- trie w tablicy  
- aktualizacje lokalne  

---

## 11. Minusy

### Opis problemu

Na podstawie ciągu znaków „+” i „-” należy skonstruować wynikowy zapis z nawiasami i myślnikami zgodnie z określonymi zasadami przejść między znakami.

### Idea rozwiązania

Wykonywane jest jedno przejście po danych oraz zastosowany zostaje prosty automat dwustanowy określający, czy aktualnie jesteśmy wewnątrz nawiasu.

### Złożoność

O(n)

---

## 12. Bony

### Opis problemu

Symulacja zaznaczania wielokrotności liczb oraz rejestrowania momentów trafienia na specjalne pozycje.

### Idea rozwiązania

Dla każdej liczby przechodzimy po jej wielokrotnościach, oznaczamy jeszcze nieużyte pozycje oraz zapisujemy trafienia. Zapamiętywana jest ostatnia sprawdzana wielokrotność, co pozwala na amortyzację operacji.

### Zastosowane techniki

- przechodzenie po wielokrotnościach  
- tablica odwiedzin  
- amortyzacja  

---

## Podsumowanie

Repozytorium obejmuje szerokie spektrum technik algorytmicznych:

- grafy (Dijkstra, SCC, topological sort)  
- dynamic programming (drzewo, DAG, sekwencje)  
- bitmaski i operacje bitowe  
- kombinatoryka  
- symulacje i konstrukcje  

Zawarte rozwiązania stanowią przekrojowy zbiór problemów charakterystycznych dla programowania konkursowego na poziomie Olimpiady Informatycznej i Potyczek Algorytmicznych.
