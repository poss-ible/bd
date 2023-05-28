#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main(int argv, char *argc[])
{
    while (argv--)
    {
        string str = "wmic startup list full | findstr /i" + *argc[argv];
        system(str.data());
    }
    return 0;
}