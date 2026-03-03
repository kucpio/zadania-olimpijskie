🏆 Zadania z Olimpiady Informatycznej i Potyczek Algorytmicznych

Repozytorium zawiera autorskie rozwiązania wybranych zadań z:

🇵🇱 Olimpiady Informatycznej (OI)

🧠 Potyczek Algorytmicznych

Są to rozwiązania konkursowe — kod jest:

zoptymalizowany pod limity czasowe,

pisany w stylu zawodów,

bez komentarzy (typowa praktyka konkursowa).

📌 Pełne treści zadań dostępne są w serwisie:
👉 https://szkopul.edu.pl

🛠 Środowisko

Język: C++17

Styl: programowanie proceduralne + klasyczne struktury danych

Kompilacja:

g++ -std=c++17 -O2 solution.cpp -o sol
./sol < input.txt
📚 Opis zadań i zastosowanych algorytmów
1️⃣ Rozkład Fibonacciego
🧩 Problem

Dla podanej liczby należy sprowadzić ją do zera w minimalnej liczbie kroków.
W jednym kroku można zastąpić liczbę wartością:

𝑘
=
∣
𝑘
−
𝐹
𝑖
∣
k=∣k−F
i
	​

∣

gdzie 
𝐹
𝑖
F
i
	​

 to dowolna liczba Fibonacciego.

💡 Rozwiązanie

Precomputing liczb Fibonacciego (do zakresu long long).

W każdej iteracji wybierana jest liczba Fibonacciego najbliższa aktualnej wartości.

Algorytm ma charakter zachłanny (greedy).

🎯 Ciekawy aspekt

Problem pokazuje zastosowanie:

strategii zachłannej w przestrzeni liczb,

iteracyjnej redukcji stanu,

pracy na liczbach dużego zakresu.

2️⃣ Szeregowanie czynności
🧩 Problem

Dane są czynności opisane parametrami (a, b).
Należy posortować je rosnąco według wartości a/b.

💡 Rozwiązanie

Zamiast używać dzielenia (ryzyko błędów numerycznych), stosujemy:

𝑎
1
⋅
𝑏
2
𝑣
𝑠
𝑎
2
⋅
𝑏
1
a
1
	​

⋅b
2
	​

vsa
2
	​

⋅b
1
	​


czyli porównanie przez mnożenie krzyżowe.

🎯 Ciekawy aspekt

Technika stosowana w:

geometrii obliczeniowej,

porównywaniu nachyleń prostych,

zadaniach z precyzją zmiennoprzecinkową.

Złożoność: O(n log n).

3️⃣ Tetris Attack
🧩 Problem

Przetwarzanie ciągu długości 2n, w którym każda liczba występuje dokładnie dwa razy.
Należy symulować operacje usuwania dopasowanych par.

💡 Rozwiązanie

Symulacja stosu przy pomocy tablicy.

Tablica jest[] do śledzenia obecności elementu.

Ręczne zarządzanie wskaźnikami zamiast struktur STL.

🎯 Ciekawy aspekt

To przykład:

symulacji struktur danych,

przetwarzania sekwencji z cofaniem operacji,

algorytmu liniowego O(n).

4️⃣ Trójkąty jednobarwne
🧩 Problem

Policzyć liczbę trójkątów w grafie nieskierowanym.

💡 Rozwiązanie

Zamiast sprawdzać wszystkie trójki (O(n³)):

Liczymy wszystkie możliwe trójki:

(
𝑛
3
)
(
3
n
	​

)

Odejmujemy trójki, które nie mogą być trójkątem,
używając stopni wierzchołków.

🎯 Ciekawy aspekt

Zastosowanie kombinatoryki w grafach.

Liczenie przez dopełnienie.

Złożoność O(n + m).

5️⃣ Wiedźmak
🧩 Problem

Najkrótsza ścieżka w grafie, gdzie każda krawędź wymaga określonego zestawu umiejętności, które zdobywamy w miastach.

💡 Rozwiązanie

Rozszerzona Dijkstra:

Stan = (miasto, maska_umiejętności).

Bitmaski (p ≤ 13)

dist[v][mask]

Kolejka priorytetowa

🎯 Ciekawy aspekt

To klasyczny przykład:

Dijkstry na grafie stanów,

połączenia grafów i DP,

zastosowania bitmask.

6️⃣ Zima
🧩 Problem

Drzewo z wagami (parzyste / nieparzyste).
Należy zoptymalizować globalny wynik odejmując najlepszą możliwą ścieżkę.

💡 Rozwiązanie

DFS

DP na drzewie

Zbieranie dwóch najlepszych wyników z poddrzew

🎯 Ciekawy aspekt

Wariant:

szukania najlepszej ścieżki w drzewie,

analogia do średnicy drzewa,

O(n).

7️⃣ Zająknięcia
🧩 Problem

Dwa ciągi.
Maksymalizacja liczby dopasowanych powtórzeń tego samego elementu w obu ciągach.

💡 Rozwiązanie

DP podobne do LCS.

Zapamiętywanie poprzednich wystąpień.

Dodatkowe warunki poprawności kolejności.

🎯 Ciekawy aspekt

Wariant:

LCS z ograniczeniami,

DP na sekwencjach z historią wystąpień.

8️⃣ Zdjęcia krasnali
🧩 Problem

Skierować krawędzie grafu nieskierowanego zgodnie z warunkami, a następnie wyznaczyć numerację wierzchołków.

💡 Rozwiązanie

Konstrukcja grafu skierowanego (BFS)

Topological sort (Kahn)

Sprawdzenie poprawności konstrukcji

🎯 Ciekawy aspekt

Połączenie:

konstrukcji grafu

i sortowania topologicznego

9️⃣ Drogi rowerowe
🧩 Problem

Dla każdego wierzchołka grafu skierowanego obliczyć liczbę osiągalnych wierzchołków.

💡 Rozwiązanie

SCC (Kosaraju)

Budowa grafu kondensacji

Topological sort

DP po DAG

🎯 Ciekawy aspekt

Klasyczna sekwencja:
SCC → DAG → DP.

Złożoność: O(n + m).

🔟 Marudny Bajtazar
🧩 Problem

Po każdej zmianie bitu w napisie znaleźć najmniejszą długość k, dla której nie wszystkie podciągi długości k występują.

💡 Rozwiązanie

Ograniczenie k ≤ 17

Kodowanie podciągów jako liczby binarne

Trie zapisane w tablicy

Aktualizacje lokalne po flipie

🎯 Ciekawy aspekt

Operacje bitowe

Sliding window

Dynamiczne utrzymywanie zbioru wzorców

1️⃣1️⃣ Minusy
🧩 Problem

Konstrukcja wyrażenia z nawiasami na podstawie ciągu +/-.

💡 Rozwiązanie

Jedno przejście

Automat dwustanowy

1️⃣2️⃣ Bony
🧩 Problem

Symulacja oznaczania wielokrotności liczb i wykrywania specjalnych pozycji.

💡 Rozwiązanie

Przechodzenie po wielokrotnościach

Amortyzacja dzięki zapamiętywaniu ostatniej pozycji

Tablica visited

🎓 Podsumowanie

Zadania obejmują szeroki zakres technik algorytmicznych:

🔹 Grafy (Dijkstra, SCC, topological sort)

🔹 DP (na drzewie, na DAG, na sekwencjach)

🔹 Bitmaski

🔹 Kombinatoryka

🔹 Symulacje i konstrukcje

🔹 Algorytmy zachłanne

Repozytorium pokazuje praktyczne zastosowanie klasycznych algorytmów w kontekście zadań konkursowych wysokiego poziomu.
