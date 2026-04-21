/*
    Opis problemu:
    Dane są informacje opisujące kolejne przejścia między stanami.
    Na ich podstawie trzeba wypisać napis złożony z myślników oraz nawiasów,
    który zaznacza fragmenty "aktywne" odpowiednio przez otwarcie nawiasu '('
    i zamknięcie nawiasu ')'.

    Idea rozwiązania:
    Przechodzimy po kolejnych znakach wejścia. Zmienna l informuje,
    czy aktualnie jesteśmy wewnątrz otwartego fragmentu:
    - l = 0 oznacza, że nawias nie jest otwarty,
    - l = 1 oznacza, że jesteśmy wewnątrz nawiasu.

    Jeśli trafimy na znak '+', a fragment nie jest jeszcze otwarty,
    wypisujemy '(' i przechodzimy do stanu otwartego.
    Jeśli trafimy na znak '-', a fragment jest otwarty,
    wypisujemy ')' i zamykamy fragment.

    Niezależnie od tego po każdej pozycji wypisujemy znak '-',
    który buduje właściwy szkielet odpowiedzi.
    Na końcu, jeśli ostatni odczytany znak był '+', trzeba jeszcze domknąć
    ostatni otwarty fragment.

    Zastosowane techniki:
    - symulacja liniowa,
    - automat o dwóch stanach,
    - wypisywanie odpowiedzi online.
*/

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    char w;
    int l = 0;  // 0 - brak otwartego nawiasu, 1 - nawias otwarty

    cin >> n;

    // Wczytujemy kolejne znaki opisujące przejścia pomiędzy odcinkami.
    for (int i = 1; i < n; i++)
    {
        cin >> w;

        // Jeśli zaczynamy nowy aktywny fragment, otwieramy nawias.
        if (w == '+' && l == 0)
        {
            cout << "(";
            l = 1;
        }

        // Jeśli kończymy aktywny fragment, zamykamy nawias.
        if (w == '-' && l == 1)
        {
            cout << ")";
            l = 0;
        }

        // Każdy krok dokłada jedną kreskę do budowanego napisu.
        cout << "-";
    }

    // Jeśli ostatni fragment pozostał otwarty, domykamy go na końcu.
    if (w == '+')
        cout << ")";

    return 0;
}
