//
//  main.c
//  huxiao
//
//  Created by 胡啸 on 2017/7/7.
//  Copyright © 2017年 胡啸. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int insert();
void max();
void average();
void sort();
void print();
void delete();

struct student        //结构体的定义
{
    char num[20];
    char name[10];
    char sex[6];
    float score;
}stu[10];



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
    int i,k;
    int j = 0;
    char wanted;
    
    printf("输入你想删除的学生学号:");
    scanf("%s",&wanted);
    
    for(i=0;;i++)
    {
        if(stu[i].num==wanted)
        {j=i;break;}
        
        if(i==len-1)
        {
            printf("error");
            exit(-1);
        }
        else
            continue;
        
    }
    for(k=j;k<len;k++)
    {
        stu[k]=stu[k+1];
    }
    len--;
    printf("删除成功!\n");
    printf("现在的学生信息为:");
    output(len);
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
            case 0:  exit(0);  break;
            default: printf("错误的输入，请重新输入：");
        }
    }
    
    return 0;
}
