#include <windows.h>
#include <tlhelp32.h> //进程快照函数头文件
#include <stdio.h>

bool getProcess(const char *procressName) // 此函数进程名不区分大小写
{
    char pName[MAX_PATH];                                              // 和PROCESSENTRY32结构体中的szExeFile字符数组保持一致，便于比较
    strcpy(pName, procressName);                                       // 拷贝数组
    CharLowerBuff(pName, MAX_PATH);                                    // 将名称转换为小写
    PROCESSENTRY32 currentProcess;                                     // 存放快照进程信息的一个结构体
    currentProcess.dwSize = sizeof(currentProcess);                    // 在使用这个结构之前，先设置它的大小
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // 给系统内的所有进程拍一个快照

    if (hProcess == INVALID_HANDLE_VALUE)
    {
        printf("CreateToolhelp32Snapshot()调用失败!\n");
        return false;
    }

    bool bMore = Process32First(hProcess, &tProcess); // 获取第一个进程信息
    while (bMore)
    {
        CharLowerBuff(currentProcess.szExeFile, MAX_PATH); // 将进程名转换为小写
        if (strcmp(currentProcess.szExeFile, pName) == 0)  // 比较是否存在此进程
        {
            CloseHandle(hProcess); // 清除hProcess句柄
            return true;
        }
        bMore = Process32Next(hProcess, hProcess); // 遍历下一个
    }

    CloseHandle(hProcess); // 清除hProcess句柄
    return false;
}

int main()
{

    while (1)
    {
        if (!getProcess("calc.exe")) // 如果被保护的进程不存在（被杀死），则启动该进程
        {
            system("start calc.exe");
        }
        if (!getProcess("p2.exe")) // 如果保护进程process2不存在，则启动该进程
        {
            system("start p2.exe");
        }
        Sleep(10); // 允许你睡一会，但不能“睡着”，要看好被保护的进程
    }
    system("pause");
    return 0;
}