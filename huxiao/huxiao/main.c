//
//  main.c
//  huxiao
//
//  Created by 胡啸 on 2017/7/7.
//  Copyright © 2017年 胡啸. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int insert();
void max();
void average();
void sort();
void print();
void delete();
void insert1();
void select1();

struct student        //结构体的定义
{
    char num[200];
    char name[100];
    char sex[60];
    float score;
}stu[100];



void menu()           //菜单
{
    printf("        ====================================\n");
    printf("|                  学生成绩管理系统                     |\n");
    printf("|               1    输入学生成绩                   |\n");
    printf("|               2    输出学生成绩                   |\n");
    printf("|               3    得出学生最大成绩                |\n");
    printf("|               4    得出学生平均成绩                |\n");
    printf("|               5    学生成绩排序                   |\n");
    printf("|               6    删除学生数据                   |\n");
    printf("|               7    插入学生数据                   |\n");
    printf("|               8    选择学生数据                   |\n");
    printf("|               0    退出管理系统                   |\n");
    printf("        ====================================\n");
}


void input(len)           //输入函数
{
    printf("请依次输入学生的 学号 姓名 性别 成绩\n");
    for(int i=0;i<len;i++)
        scanf("%s %s %s %f",stu[i].num,stu[i].name,stu[i].sex,&stu[i].score);
}


void output(len)          //输出函数
{
    printf("学号\t姓名\t性别\t成绩\n");
    for(int i=0;i<len;i++)
        printf("%s %s %s %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
}


void max(len)             //最大值
{
    int max=0;
    for(int i=0;i<len;i++)
    {
        if(stu[i].score>max)
            max=stu[i].score;
    }
    printf("最高成绩为:%d\n",max);
}


void ave(len)           //求平均值
{
    float ave;
    float sum=0;
    for(int i=0;i<10;i++)
        sum+=stu[i].score;
    ave=sum/len;
    printf("平均成绩为:%f\n",ave);
}



void sort(len)         //排序函数
{
    struct student temp;
    for(int i=0;i<len-1;i++)
        for(int j=0;j<=len-i-1;j++)
        {
            if(stu[j].score<=stu[j+1].score)
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    output(len);
}


void delete(int len)      //删除函数
{
    int i = 0;
    //int j = 0,k;
    char wanted[10];
    
    printf("输入你想删除的学生学号:");
    scanf("%s",wanted);
    
    while(strcmp(stu[i].name,wanted)!=0&&i<len)
        i++;
    if(i==len)
    { printf("不存在此人!\n"); /*返回失败信息*/
    }
    for(int j=i;j<len-1;j++) /*删除操作*/
    {
        strcpy(stu[j].num,stu[j+1].num);
        strcpy(stu[j].name,stu[j+1].name);
        strcpy(stu[j].sex,stu[j+1].sex);
        stu[j].score=stu[j+1].score;
    }
    len--;
    printf("\t\tcongratulations Successed!\n"); /*返回成功信息*/
    output(len);
}


void insert1(int len)
{
    int j,i = 0;
    
    int weizhi;
    
    printf("请依次输入你想插入的学生的 学号 姓名 性别 成绩\n");
        scanf("%s %s %s %f",stu[i].num,stu[i].name,stu[i].sex,&stu[i].score);
    
    printf("输入你想插入的位置:");
        scanf("%d",&weizhi);
    
    if((weizhi-1<0) || (weizhi-1>len))
        printf("位置输入错误:");
    else
    {
        for( j=len;j>=weizhi-1;j--)
        {
            strcpy(stu[j+1].num,stu[j].num);
            strcpy(stu[j+1].name,stu[j].name);
            strcpy(stu[j+1].sex,stu[j].sex);
            stu[j+1].score=stu[j].score;
        }
        len=len+1;
        strcpy(stu[weizhi-1].num,stu[i].num);
        strcpy(stu[weizhi-1].name,stu[i].name);
        strcpy(stu[weizhi-1].sex,stu[i].sex);
        stu[weizhi-1].score=stu[i].score;
        printf("现在的数组为:");
        output(len);
        printf("\n");
    }
}



/*
    for(i=0;;i++)
    {
        if(stu[i].num==wanted)
        {
            j=i;
            for(k=j;k<len;k++)
                {
                    stu[k]=stu[k+1];
                }
            len--;
            printf("删除成功!\n");
            printf("现在的学生信息为:");
            output(len);
            break;
        }
        
        if(i==len-1)
        {
            printf("不存在此人!");
            break;
        }
        else
            continue;
        
    }
 */



void select1(int len)
{
    int i = 0;
    char wanted[10];
    
    printf("输入你想查找的学生学号:");
    scanf("%s",wanted);
    
    while(strcmp(stu[i].name,wanted)!=0&&i<len)
        i++;
    if(i==len)
    {
        printf("不存在此人!\n"); /*返回失败信息*/
    }
    else
    {
        printf("Congratulations!查找成功\n");
        printf("%s %s %s %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
    }
}


int main()
{
    int choose;
    int len;
    
    printf("首先请输入学生人数:");
    scanf("%d",&len);
    
    while(1)
    {
        menu();
        printf("请选择0--6:  ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:  input(len);  break;
            case 2:  output(len); break;
            case 3:  max(len);    break;
            case 4:  ave(len);    break;
            case 5:  sort(len);   break;
            case 6:  delete(len); break;
            case 7:  insert1(len); break;
            case 8:  select1(len); break;
            case 0:  exit(0);  break;
            default: printf("错误的输入，请重新输入：");
        }
    }
    
    return 0;
}
