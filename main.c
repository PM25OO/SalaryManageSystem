#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teacher.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <locale.h>
#endif

int teacherCount = 0;
Teacher teachers[MAX_TEACHERS];

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);         // 设置控制台输出编码为UTF-8
    HWND hwnd = GetForegroundWindow(); // 获取当前窗口句柄
    ShowWindow(hwnd, SW_MAXIMIZE);     // 最大化窗口
#endif
    int choice;
    readFromFile(); // 启动时从文件加载数据

    do
    {
        ClearScreen();
        printAsciiArt();
        printf("\n教师工资管理系统\n\n\n");
        printf("1. 输入教师信息\n\n");
        printf("2. 修改教师信息\n\n");
        printf("3. 删除教师信息\n\n");
        printf("4. 浏览教师信息\n\n");
        printf("5. 保存数据\n\n");
        printf("0. 退出系统\n\n\n");
        printf("请选择操作：");
        if (scanf("%d", &choice) != 1)
        {
            printf("输入无效！\n");
            while (getchar() != '\n')
                ;        // 清空输入缓冲区
            choice = -1; // 设置为一个无效选项
        }
        getchar(); // 清空缓冲区

        switch (choice)
        {
        case 1:
            inputTeacher();
            break;
        case 2:
            modifyTeacher();
            break;
        case 3:
            deleteTeacher();
            break;
        case 4:
            viewTeachers();
            break;
        case 5:
            saveToFile();
            break;
        case 0:
        {
            char confirm;
            printf("是否保存修改？(y/n)");
            if (scanf(" %c", &confirm) != 1)
            {
                printf("输入无效，将不保存修改。\n");
            }
            else
            {
                if (confirm == 'y' || confirm == 'Y')
                {
                    saveToFile();
                    printf("数据已保存，退出系统。\n");
                }
                else
                {
                    printf("不保存修改，退出系统。\n");
                }
            }
            getchar(); // 清空缓冲区
            break;
        }
        case 114514:
            YuanShen();
        default:
            printf("无效选项！\n");
            getchar();
            break;
        }
    } while (choice != 0);
    return 0;
}
