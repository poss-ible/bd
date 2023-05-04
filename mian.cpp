#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    s = "curl -O https://raw.iqiq.io/poss-ible/bd/main/" + s;
    system(s.data());
    return 0;
}