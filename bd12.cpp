#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "cccc";
    while (1)
    {
        cin >> s;
        string b = "title " + s;
        cout << b << '\n';
        system(b.data());
    }
    return 0;
}