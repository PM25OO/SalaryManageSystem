// teacher.h
#ifndef TEACHER_H
#define TEACHER_H

#define MAX_TEACHERS 100

typedef struct {
    char teacherID[20];    
    char name[50];         
    char gender[10];       
    char department[50];   
    char address[100];     
    char phone[15];        
   
    double baseSalary;      
    double allowance;       
    double subsidy;         
   
    double phoneFee;        
    double utilityFee;      
    double rent;            
    double incomeTax;       
    double hygieneFee;      
    double providentFund;   
    
    double totalDeductions;
    double totalSalary;     
    double netSalary;       
} Teacher;

// 全局变量声明
extern int teacherCount;
extern Teacher teachers[MAX_TEACHERS];

// 函数声明
void inputTeacher();
void modifyTeacher();
void deleteTeacher();
void viewTeachers();
void calculateSalary(Teacher *t);
void saveToFile();
void readFromFile();
void YuanShen();

#endif // TEACHER_H