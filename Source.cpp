#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція для введення рядка
void CreateBinFile(char* fname)
{
    ofstream fout(fname, ios::binary);
    char ch;
    //cout << "fout" <<fout  << "\n"; 
    string s;
    do {
        cin.get();
        cin.sync();
        cout << "enter line:"; getline(cin, s);
        for (unsigned i = 0; i < s.length(); i++)
            fout.write((char*)&s[i], sizeof(s[i]));
        cout << "continue? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');     cout << endl;
    cout << "s.length=" << s.length() << endl;
    cout << "svvv=" << s << endl;
   // for (unsigned i = 0; i < s.length(); i++)
   //     if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
     //       cout << s[i];
    cout << endl;
    fout.close();
}
// --------------------------------------------
// Функція для виведення рядка
void PrintBinFile(char* fname)
{
    ifstream fin(fname, ios::binary);
    char c;;
    //cout << "fin" <<fin  << "\n"; 
    while (fin.read((char*)&c, sizeof(c)))
    {
        cout << c << endl;
    }
    fin.close();
}
// --------------------------------------------
// Функція для перепису латинських літер
void Perepus(char* fname, char* gname)
{
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);
    char c;
    while (f.read((char*)&c, sizeof(c)))
    {
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
            g.write((char*)&c, sizeof(c));
    }
}
// Основна функція
int main()
{
    char fname[100];
    char gname[100];

    cout << "enter name file1:   "; cin >> fname;
    cout << " fname =" << fname << endl;

    CreateBinFile(fname);
   // PrintBinFile(fname);
    cout << "enter name file2:   "; cin >> gname;
    cout << " gname =" << gname << endl;
    Perepus(fname, gname);
   // PrintBinFile(gname);
    return 0;
}
