#include <bits/stdc++.h>

#define MAX_N 100007

using namespace std;

int n, m;
int kolor = 0;

vector <int> graf[MAX_N];
vector <int> odwr[MAX_N];
vector <int> Tgraf[MAX_N];
vector <int> Sgraf[MAX_N];
vector <int> TSgraf[MAX_N];
vector <int> kolejnosc;
int moc[MAX_N] = {0};
int topo[MAX_N] = {0};
int sto[MAX_N] = {0};
int wy[MAX_N] = {0};
int sp[MAX_N] = {0};
bool odw[MAX_N] = {false};


void wczytaj()
{
    int a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        odwr[b].push_back(a);
    }
}

void DFS(int v)
{
    odw[v] = true;
    for (int i = 0; i < graf[v].size(); i++)
    {
        if (!odw[graf[v][i]])
            DFS(graf[v][i]);
    }
    kolejnosc.push_back(v);
}

void SCC(int v, int kol)
{
    sp[v] = kol;
    for (int i = 0; i < odwr[v].size(); i++)
    {
        if (sp[odwr[v][i]] == 0)
            SCC(odwr[v][i], kol);
        else if (sp[odwr[v][i]] != kolor)
        {
            Sgraf[sp[odwr[v][i]]].push_back(kolor);
            TSgraf[kolor].push_back(sp[odwr[v][i]]);
        }
    }

}

void przygotuj()
{
    for (int i = 1; i <= n; i++)
    {
        if (!odw[i])
            DFS(i);
    }

    for (int i = kolejnosc.size()-1; i >= 0; i--)
    {
        if (sp[kolejnosc[i]] == 0)
            SCC(kolejnosc[i], ++kolor);
    }

    for (int i = 1; i <= kolor; i++)
    {
        for (int j = 0; j < Sgraf[i].size(); j++)
        {
            sto[Sgraf[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        moc[sp[i]]++;
    }

}

void toposort(){
    queue <int> q;
    int w, k = 0;
    for(int i = 1; i <=kolor; i++){
        if(sto[i] == 0){
            q.push(i);
        }
    }

    while(q.size() > 0){
        w = q.front();
        q.pop();
        k++;
        topo[k]=w;
        for(int i = 0; i < Sgraf[w].size(); i++){
            sto[Sgraf[w][i]]--;
            if(sto[Sgraf[w][i]] == 0){
                q.push(Sgraf[w][i]);
            }
        }
    }
}

void transponuj()
{
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < graf[i].size(); j++) {
            Tgraf[graf[i][j]].push_back(i);
        }
}

void policz(void)
{

    for(int i = kolor; i >= 1; i--)
    {
        for(int j = 0; j < TSgraf[topo[i]].size(); j++)
        {
            wy[TSgraf[topo[i]][j]] += (wy[topo[i]] + moc[topo[i]]);
        }
    }

    for (int i = 1; i <= kolor; i++)
    {
        wy[i] += moc[i];
    }

}

void wypisz(void)
{
    for (int i = 1; i <= n; i++)
        cout << wy[sp[i]]-1 << "\n";
}

void wypisz_graf()
{
    for (int i = 1; i <= kolor; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < TSgraf[i].size(); j++)
        {
            cout << TSgraf[i][j] << " ";
        }
        cout << "\n";
    }

}

void wypiszz()
{
    /*for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << sp[i] << "\n";
    }*/
    for (int i = 1; i <= kolor; i++)
    {
        cout << topo[i] << "\n";
    }
    /*for (int i = 1; i <= kolor; i++)
    {
        cout << moc[i] << "\n";
    }*/
    /*for (int i = 1; i <= kolor; i++)
    {
        cout << wy[i] << "\n";
    }*/

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    wczytaj();
    przygotuj();
    toposort();
    policz();
    wypisz();
    //wypisz_graf();

    /*transponuj();
    policz();
    wypisz();*/

    exit(0);
}
