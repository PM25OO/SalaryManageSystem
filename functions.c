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

    printf("输入 电话费: ");
    scanf("%lf", &t.phoneFee);
    getchar();

    printf("输入 水电费: ");
    scanf("%lf", &t.utilityFee);
    getchar();

    printf("输入 房租: ");
    scanf("%lf", &t.rent);
    getchar();

    printf("输入 卫生费: ");
    scanf("%lf", &t.hygieneFee);
    getchar();

    calculateSalary(&t);
    teachers[teacherCount++] = t;
    printf("教师信息已添加。\n");
    getchar();
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
            char input[100];

            printf("修改姓名 (%s): ", teachers[i].name);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(teachers[i].name, input, sizeof(teachers[i].name));
            }
            printf("修改性别 (%s): ", teachers[i].gender);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(teachers[i].gender, input, sizeof(teachers[i].gender));
            }
            printf("修改部门 (%s): ", teachers[i].department);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(teachers[i].department, input, sizeof(teachers[i].department));
            }
            printf("修改地址 (%s): ", teachers[i].address);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(teachers[i].address, input, sizeof(teachers[i].address));
            }
            printf("修改电话 (%s): ", teachers[i].phone);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(teachers[i].phone, input, sizeof(teachers[i].phone));
            }
            printf("修改基本工资 (%.2lf): ", teachers[i].baseSalary);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                teachers[i].baseSalary = atof(input);
            }
            printf("修改津贴 (%.2lf): ", teachers[i].allowance);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                teachers[i].allowance = atof(input);
            }
            printf("修改补贴 (%.2lf): ", teachers[i].subsidy);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                teachers[i].subsidy = atof(input);
            }
            calculateSalary(&teachers[i]);
            printf("教师信息已更新。\n");
            getchar();
            return;
        }
    }
    printf("未找到教师ID。\n");
    getchar();
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
            getchar();
            return;
        }
    }
    printf("未找到教师ID。\n");
    getchar();
}

// 浏览教师信息
void viewTeachers()
{
    if (teacherCount == 0)
    {
        printf("暂无教师信息。\n");
        getchar();
        return;
    }

    // 打印表头，使用指定宽度对齐
    const char *headers[] = {"ID", "姓名", "性别", "部门", "地址", "电话", "实发工资", "实际收入"};
    int columnWidths[] = {10, 20, 10, 40, 15, 15, 20, 20};
    int columnCount = sizeof(headers) / sizeof(headers[0]);

    // 打印表头
    printf("\n教师列表:\n");
    for (int i = 0; i < columnCount; i++)
    {
        print_left_aligned(headers[i], columnWidths[i]);
    }
    printf("\n");

    // 打印分隔线
    for (int i = 0; i < columnCount; i++)
    {
        for (int j = 0; j < columnWidths[i]; j++)
        {
            putchar('-');
        }
    }
    printf("\n");

    // 打印每个教师的信息，保证每列宽度一致
    for (int i = 0; i < teacherCount; i++)
    {
        print_left_aligned(teachers[i].teacherID, 10);
        print_left_aligned(teachers[i].name, 20);
        print_left_aligned(teachers[i].gender, 10);
        print_left_aligned(teachers[i].department, 40);
        print_left_aligned(teachers[i].address, 15);
        print_left_aligned(teachers[i].phone, 15);
        printf("%-20.2f %-20.2f\n",
               teachers[i].baseSalary + teachers[i].allowance + teachers[i].subsidy,
               teachers[i].totalSalary);
    }
    while (1) {
        char id[20];
        int found = 0; // 标志变量
        printf("\n输入要查看详情的教师ID: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = 0; // 移除换行符
        // 判断是否是回车退出
        if (strlen(id) == 0) {
            printf("已退出查询。\n");
            break;
        }
        // 查找教师信息
        for (int i = 0; i < teacherCount; i++) {
            if (strcmp(teachers[i].teacherID, id) == 0) {
                found = 1; // 找到教师
                printf("员工 %s 本月合计扣款 %.2lf 元，其中电话费 %.2f 元，水电费 %.2f 元，卫生费 %.2f 元，房租 %.2f 元。\n",
                       teachers[i].name, teachers[i].totalDeductions, teachers[i].phoneFee, teachers[i].utilityFee,
                       teachers[i].hygieneFee, teachers[i].rent);
                break;
            }
        }
        if (!found) {
            printf("未找到教师ID。\n");
        }
    }

    getchar();
}

// 计算工资
void calculateSalary(Teacher *t)
{
    double gross = t->baseSalary + t->allowance + t->subsidy;
    t->incomeTax = 0.1 * gross;
    t->providentFund = 0.05 * gross;
    t->totalDeductions = t->incomeTax + t->hygieneFee + t->providentFund + t->phoneFee + t->utilityFee + t->rent;
    t->totalSalary = gross - t->totalDeductions;
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
    fprintf(fp, "ID,姓名,性别,部门,地址,电话,基本工资,津贴,补贴,总工资,净工资,电话费,水电费,卫生费,房租\n");
    for (int i = 0; i < teacherCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n",
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
                teachers[i].netSalary,
                teachers[i].phoneFee,
                teachers[i].utilityFee,
                teachers[i].hygieneFee,
                teachers[i].rent);
    }
    fclose(fp);
    printf("数据已保存到 teachers.csv。\n");
    getchar();
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
            strncpy(t.teacherID, token, sizeof(t.teacherID) - 1);
        t.teacherID[sizeof(t.teacherID) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token != NULL)
            strncpy(t.name, token, sizeof(t.name) - 1);
        t.name[sizeof(t.name) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token != NULL)
            strncpy(t.gender, token, sizeof(t.gender) - 1);
        t.gender[sizeof(t.gender) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token != NULL)
            strncpy(t.department, token, sizeof(t.department) - 1);
        t.department[sizeof(t.department) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token != NULL)
            strncpy(t.address, token, sizeof(t.address) - 1);
        t.address[sizeof(t.address) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token != NULL)
            strncpy(t.phone, token, sizeof(t.phone) - 1);
        t.phone[sizeof(t.phone) - 1] = '\0';

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

        token = strtok(NULL, ",");
        if (token != NULL)
            t.netSalary = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.phoneFee = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.utilityFee = atof(token);

        token = strtok(NULL, ",");
        if (token != NULL)
            t.hygieneFee = atof(token);

        token = strtok(NULL, ",\n");
        if (token != NULL)
            t.rent = atof(token);
        calculateSalary(&t);

        teachers[teacherCount++] = t;
    }
    fclose(fp);
    printf("数据已从 teachers.csv 加载。\n");
}

void YuanShen()
{
    printf("原神，启动！\n");
}

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printAsciiArt()
{
    printf(" _    _   _____   _       _____   _____  ___  ___  _____ \n");
    printf("| |  | | |  ___| | |     /  __ \\ |  _  | |  \\/  | |  ___|\n");
    printf("| |  | | | |__   | |     | /  \\/ | | | | | .  . | | |__  \n");
    printf("| |/\\| | |  __|  | |     | |     | | | | | |\\/| | |  __| \n");
    printf("\\  /\\  / | |____ | |____ | \\__/\\ | |_| | | |  | | | |____ \n");
    printf(" \\/  \\/  \\_____/ \\_____/  \\____/  \\___/  \\_|  |_/ \\_____/ \n");
}

// 判断字符是否是中文（适用于UTF-8编码）
int is_chinese_char(unsigned char c)
{
    return (c >= 0x80); // UTF-8 中文字符的首字节通常 >= 0x80
}

// 计算字符串的实际显示宽度
int calc_display_width(const char *str)
{
    int width = 0;
    while (*str)
    {
        if (is_chinese_char((unsigned char)*str))
        {
            width += 2; // 中文字符显示宽度为2
            str += 3;   // UTF-8 中文字符占3字节
        }
        else
        {
            width += 1; // 英文字符显示宽度为1
            str++;
        }
    }
    return width;
}

// 输出左对齐的字符串
void print_left_aligned(const char *str, int target_width)
{
    int display_width = calc_display_width(str);
    printf("%s", str); // 输出字符串本身
    for (int i = 0; i < target_width - display_width; i++)
    {
        putchar(' '); // 补充空格
    }
}