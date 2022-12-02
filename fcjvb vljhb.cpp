#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct zesp {
    int re, im;
};

void print(zesp**& tab, int w);
void del(zesp**& tab, int w);

void tworz(zesp**& tab, int w) {
    tab = new zesp * [w];
    for (int i = 0; i < w; i++) {
        tab[i] = new zesp[w];
    }
}

bool wczytaj(zesp**& tab, int w, string nazwa) {
    ifstream plik;
    plik.open(nazwa);

    if (!plik.good()) return false;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            plik >> tab[i][j].re >> tab[i][j].im;
        }
    }
    plik.close();
    return true;
}

void sumowanie(zesp**& tab1, zesp**& tab2, int w) {
    zesp** tmp;
    tworz(tmp, w);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            tmp[i][j].re = tab1[i][j].re + tab2[i][j].re;
            tmp[i][j].im = tab1[i][j].im + tab2[i][j].im;
        }
    }
    print(tmp, w);
    del(tmp, w);
}

void print(zesp**& tab, int w) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            cout << tab[i][j].re << "+" << tab[i][j].im << "i\t";
        }
        cout << endl;
    }
    cout << endl;
}

void del(zesp**& tab, int w) {
    for (int i = 0; i < w; i++) {
        delete[]tab[i];
    }
    delete[]tab;
}

int main()
{
    int m;
    cout << "enter m:";
    cin >> m;
    string nazwa;
    zesp** tab1, ** tab2;
    tworz(tab1, m);
    tworz(tab2, m);
    cout << "enter first file name:";
    cin >> nazwa;
    wczytaj(tab1, m, nazwa);
    cout << "enter secound file name:";
    cin >> nazwa;
    wczytaj(tab2, m, nazwa);

    print(tab1, m);
    print(tab2, m);

    sumowanie(tab1, tab2, m);

    del(tab1, m);
    del(tab2, m);

    return 0;
}
