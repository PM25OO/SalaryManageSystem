#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teacher.h"
int teacherCount = 0;
Teacher teachers[MAX_TEACHERS];

int main()
{
    int choice;
    readFromFile(); // 启动时从文件加载数据
    do
    {
        printf("\n教师工资管理系统\n\n");
        printf("1. 输入教师信息\n");
        printf("2. 修改教师信息\n");
        printf("3. 删除教师信息\n");
        printf("4. 浏览教师信息\n");
        printf("5. 保存数据\n");
        printf("0. 退出系统\n");
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
            printf("退出系统。\n");
            break;
        default:
            printf("无效选项！\n");
            getchar();
            break;
        }
    } while (choice != 0);
    return 0;
}
