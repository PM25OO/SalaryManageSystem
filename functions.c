#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "teacher.h"

// 输入教师信息
void inputTeacher()
{
    if (teacherCount >= MAX_TEACHERS)
    {
        printf("教师数量已达到最大限制。\n");
        return;
    }
    Teacher t;
    printf("\n输入 教师ID: ");
    fgets(t.teacherID, sizeof(t.teacherID), stdin);
    t.teacherID[strcspn(t.teacherID, "\n")] = 0;

    printf("输入 姓名: ");
    fgets(t.name, sizeof(t.name), stdin);
    t.name[strcspn(t.name, "\n")] = 0;

    printf("输入 性别: ");
    fgets(t.gender, sizeof(t.gender), stdin);
    t.gender[strcspn(t.gender, "\n")] = 0;

    printf("输入 部门: ");
    fgets(t.department, sizeof(t.department), stdin);
    t.department[strcspn(t.department, "\n")] = 0;

    printf("输入 地址: ");
    fgets(t.address, sizeof(t.address), stdin);
    t.address[strcspn(t.address, "\n")] = 0;

    printf("输入 电话: ");
    fgets(t.phone, sizeof(t.phone), stdin);
    t.phone[strcspn(t.phone, "\n")] = 0;

    printf("输入 基本工资: ");
    scanf("%lf", &t.baseSalary);
    getchar();

    printf("输入 津贴: ");
    scanf("%lf", &t.allowance);
    getchar();

    printf("输入 补贴: ");
    scanf("%lf", &t.subsidy);
    getchar();

    calculateSalary(&t);
    teachers[teacherCount++] = t;
    printf("教师信息已添加。\n");
}

// 修改教师信息
void modifyTeacher()
{
    char id[20];
    printf("\n输入要修改的教师ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < teacherCount; i++)
    {
        if (strcmp(teachers[i].teacherID, id) == 0)
        {
            printf("修改姓名 (%s): ", teachers[i].name);
            fgets(teachers[i].name, sizeof(teachers[i].name), stdin);
            teachers[i].name[strcspn(teachers[i].name, "\n")] = 0;

            printf("修改性别 (%s): ", teachers[i].gender);
            fgets(teachers[i].gender, sizeof(teachers[i].gender), stdin);
            teachers[i].gender[strcspn(teachers[i].gender, "\n")] = 0;

            printf("修改部门 (%s): ", teachers[i].department);
            fgets(teachers[i].department, sizeof(teachers[i].department), stdin);
            teachers[i].department[strcspn(teachers[i].department, "\n")] = 0;

            printf("修改地址 (%s): ", teachers[i].address);
            fgets(teachers[i].address, sizeof(teachers[i].address), stdin);
            teachers[i].address[strcspn(teachers[i].address, "\n")] = 0;

            printf("修改电话 (%s): ", teachers[i].phone);
            fgets(teachers[i].phone, sizeof(teachers[i].phone), stdin);
            teachers[i].phone[strcspn(teachers[i].phone, "\n")] = 0;

            printf("修改基本工资 (%.2lf): ", teachers[i].baseSalary);
            scanf("%lf", &teachers[i].baseSalary);
            getchar();

            printf("修改津贴 (%.2lf): ", teachers[i].allowance);
            scanf("%lf", &teachers[i].allowance);
            getchar();

            printf("修改补贴 (%.2lf): ", teachers[i].subsidy);
            scanf("%lf", &teachers[i].subsidy);
            getchar();

            calculateSalary(&teachers[i]);
            printf("教师信息已更新。\n");
            return;
        }
    }
    printf("未找到教师ID。\n");
}

// 删除教师信息
void deleteTeacher()
{
    char id[20];
    printf("\n输入要删除的教师ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < teacherCount; i++)
    {
        if (strcmp(teachers[i].teacherID, id) == 0)
        {
            for (int j = i; j < teacherCount - 1; j++)
            {
                teachers[j] = teachers[j + 1];
            }
            teacherCount--;
            printf("教师信息已删除。\n");
            return;
        }
    }
    printf("未找到教师ID。\n");
}

// 浏览教师信息
void viewTeachers()
{
    if (teacherCount == 0)
    {
        printf("暂无教师信息。\n");
        return;
    }
    printf("\n教师列表:\n");
    printf("ID\t姓名\t性别\t部门\t地址\t电话\t总工资\n");
    for (int i = 0; i < teacherCount; i++)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%.2lf\n",
               teachers[i].teacherID,
               teachers[i].name,
               teachers[i].gender,
               teachers[i].department,
               teachers[i].address,
               teachers[i].phone,
               teachers[i].totalSalary);
    }
    getchar();
}

// 计算工资
void calculateSalary(Teacher *t)
{
    t->phoneFee = 50.0;
    t->utilityFee = 100.0;
    t->rent = 200.0;
    t->incomeTax = 0.1 * (t->baseSalary + t->allowance + t->subsidy);
    t->hygieneFee = 30.0;
    t->providentFund = 0.05 * (t->baseSalary + t->allowance + t->subsidy);
    t->totalDeductions = t->incomeTax + t->hygieneFee + t->providentFund;
    t->totalSalary = t->baseSalary + t->allowance + t->subsidy - t->totalDeductions;
    t->netSalary = t->totalSalary;
}

// 保存数据到CSV文件
void saveToFile()
{
    FILE *fp = fopen("teachers.csv", "w");
    if (fp == NULL)
    {
        printf("无法打开文件保存数据。\n");
        return;
    }
    // 写入CSV头
    fprintf(fp, "ID,姓名,性别,部门,地址,电话,基本工资,津贴,补贴,总工资,净工资\n");
    for (int i = 0; i < teacherCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n",
                teachers[i].teacherID,
                teachers[i].name,
                teachers[i].gender,
                teachers[i].department,
                teachers[i].address,
                teachers[i].phone,
                teachers[i].baseSalary,
                teachers[i].allowance,
                teachers[i].subsidy,
                teachers[i].totalSalary,
                teachers[i].netSalary);
    }
    fclose(fp);
    printf("数据已保存到 teachers.csv。\n");
}

// 从CSV文件读取数据
void readFromFile()
{
    FILE *fp = fopen("teachers.csv", "r");
    if (fp == NULL)
    {
        printf("没有找到数据文件，开始新建。\n");
        return;
    }
    char line[512];
    // 读取CSV头
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        fclose(fp);
        printf("数据文件为空。\n");
        return;
    }
    // 逐行读取教师数据
    while (fgets(line, sizeof(line), fp))
    {
        if (teacherCount >= MAX_TEACHERS)
        {
            printf("教师数量已达到最大限制，后续数据将被忽略。\n");
            break;
        }
        Teacher t;
        char *token = strtok(line, ",");
        if (token != NULL)
            strcpy(t.teacherID, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(t.name, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(t.gender, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(t.department, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(t.address, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            strcpy(t.phone, token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.baseSalary = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.allowance = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.subsidy = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.totalSalary = atof(token);

        token = strtok(NULL, ",\n");
        if (token != NULL)
            t.netSalary = atof(token);

        teachers[teacherCount++] = t;
    }
    fclose(fp);
    printf("数据已从 teachers.csv 加载。\n");
}