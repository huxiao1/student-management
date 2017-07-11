#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//语文，数学，英语，总分

struct student        //结构体的定义
{
    char num[200];
    char name[100];
    char sex[60];
    float score1;
    float score2;
    float score3;
    float sum;
}stu[100];





void menu()           //菜单
{
    printf("            ====================================\n");
    printf("    |                  学生成绩管理系统                  |\n");
    printf("    |               1    输出学生成绩                   |\n");
    printf("    |               2    得出学生最大成绩                |\n");
    printf("    |               3    得出学生平均成绩                |\n");
    printf("    |               4    学生成绩排序                   |\n");
    printf("    |               5    删除学生数据                   |\n");
    printf("    |               6    插入学生数据                   |\n");
    printf("    |               7    选择学生数据                   |\n");
    printf("    |               0    退出管理系统                   |\n");
    printf("            ====================================\n");
}


void input(int len)           //输入函数
{
    int i=0;
    do
    {
        printf("请输入第%d个学生的 学号 姓名 性别 语文成绩 数学成绩 英语成绩\n",i+1);
        scanf("%s %s %s %f %f %f",stu[i].num,stu[i].name,stu[i].sex,&stu[i].score1,&stu[i].score2,&stu[i].score3);
        i++;
    }
    while(i<=len-1);
}


void output(int len)          //输出函数
{
    int i=0;
    int c;
    printf("学号\t姓名\t性别\t语文成绩\t数学成绩\t英语成绩\t总成绩\n");
    for(i=0;i<len;i++)
    {
        c=stu[i].score1+stu[i].score2+stu[i].score3;
        printf("%s %s %s %f %f %f 总成绩:%d\n\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score1,stu[i].score2,stu[i].score3,c);
    }
}


void max(int len)             //最大值
{
    int i,j,k,l=0;
    float max1=0;
    float max2=0;
    float max3=0;
    float max4=0;
    for(i=0;i<len;i++)
    {
        if(stu[i].score1>=max1)
            max1=stu[i].score1;
    }
    printf("语文最高成绩为:%f\n",max1);
    for(j=0;j<len;j++)
    {
        if(stu[j].score2>=max2)
            max2=stu[j].score1;
    }
    printf("数学最高成绩为:%f\n",max2);
    for(k=0;k<len;k++)
    {
        if(stu[k].score1>=max3)
            max3=stu[k].score3;
    }
    printf("英语最高成绩为:%f\n",max3);
    for(l=0;l<len;l++)
    {
        if((stu[l].score1+stu[l].score2+stu[l].score3)>=max4)
            max4=stu[l].score1+stu[l].score2+stu[l].score3;
    }
    printf("总分最高成绩为:%f\n",max4);
}


void ave(int len)           //求平均值
{
    int i,j,k=0;
    float ave1 = 0.0,ave2 = 0.0,ave3 = 0.0;
    float sum1=0;
    float sum2=0;
    float sum3=0;
    for(i=0;i<10;i++)
    {
        sum1+=stu[i].score1;
        ave1=sum1/len;
    }
    printf("语文平均成绩为:%f\n",ave1);
    for(j=0;j<10;j++)
    {
        sum2+=stu[j].score2;
        ave2=sum2/len;
    }
    printf("数学平均成绩为:%f\n",ave2);
    for(k=0;k<10;k++)
    {
        sum3+=stu[k].score3;
        ave3=sum3/len;
    }
    printf("英语平均成绩为:%f\n",ave3);
}


void sort(int len)         //排序函数
{
    int i,j;
    struct student temp;
    for(i=0;i<len-1;i++)
        for(j=0;j<=len-i-1;j++)
        {
            if(stu[j].sum<stu[j+1].sum)
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    printf("根据总分排序为:");
    output(len);
}


void delete1(int *len)      //删除函数
{
    int i = 0;
    int j;
    char wanted[10];
    
    printf("输入你想删除的学生学号:");
    scanf("%s",wanted);
    
    while(strcmp(stu[i].num,wanted)!=0&&i<(*len))
        i++;
    if(i==*len)
    {
        printf("不存在此人!\n");
        return;                             /*返回失败信息*/
    }
    else{
        for(j=i;j<*len-1;j++)                   /*删除操作*/
        {
            strcpy(stu[j].num,stu[j+1].num);
            strcpy(stu[j].name,stu[j+1].name);
            strcpy(stu[j].sex,stu[j+1].sex);
            stu[j].score1=stu[j+1].score1;
            stu[j].score2=stu[j+1].score2;
            stu[j].score3=stu[j+1].score3;
        }
        (*len)--;
        printf("\t\tcongratulations Successed!\n"); /*返回成功信息*/
        printf("现在的数据库中学生信息如下:");
        output(*len);
        printf("\n");
    }
}


void cls(){
    //如果编译系统为windows，用此句作为清屏
    //system("cls");
    //如果编译系统非windows，尽量用此句清屏
    for(int i = 0 ; i < 50 ; i++)
        printf("\n");
}


void insert1(int *len)
{
    struct student stu2;
    int j;
    
    int weizhi;
    
    printf("请依次输入你想插入的学生的 学号 姓名 性别 语文成绩 数学成绩 英语成绩\n");
    scanf("%s %s %s %f %f %f",stu2.num,stu2.name,stu2.sex,&stu2.score1,&stu2.score2,&stu2.score3);
    
    printf("输入你想插入的位置:");
    scanf("%d",&weizhi);
    
    if((weizhi-1<0) || (weizhi-1>(*len)))
        printf("位置输入错误:\n");
    else
    {
        for( j=*len;j>=weizhi;j--)
        {
            strcpy(stu[j].num,stu[j-1].num);
            strcpy(stu[j].name,stu[j-1].name);
            strcpy(stu[j].sex,stu[j-1].sex);
            stu[j].score1=stu[j+1].score1;
            stu[j].score2=stu[j+1].score2;
            stu[j].score3=stu[j+1].score3;
        }
        *len=*len+1;
        strcpy(stu[weizhi-1].num,stu2.num);
        strcpy(stu[weizhi-1].name,stu2.name);
        strcpy(stu[weizhi-1].sex,stu2.sex);
        stu[weizhi-1].score1=stu2.score1;
        stu[weizhi-1].score2=stu2.score2;
        stu[weizhi-1].score3=stu2.score3;
        printf("现在的数组为:");
        output(*len);
        printf("\n");
    }
}



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
        printf("%s %s %s %f %f %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score1,stu[i].score2,stu[i].score3);
    }
}


void IO_ReadInfo(int *len)

{
    
    FILE *fp;
    if ((fp=fopen("/Users/huxiao/Desktop/github/student-management/Database.txt","rt"))==NULL)
        
    {
        
        printf("不能打开文件!\n");
        
        exit(-1);
        
    }
    fread(stu,*len,sizeof(struct student),fp)!=1;
    output(*len);
    
    fclose(fp);
    
}


void IO_WriteInfo(int *len)

{
    FILE *fp;
    if ((fp=fopen("/Users/huxiao/Desktop/github/student-management/Database.txt","wt"))==NULL)
        
    {
        
        printf("不能打开文件!\n");
        
        exit(-1);
        
    }
    fwrite(stu, sizeof(struct student), *len, fp);
    fclose(fp);
    
}


void IO_WriteInfo1(int *len)

{
    FILE *fp;
    if ((fp=fopen("/Users/huxiao/Desktop/github/student-management/Database.txt","at"))==NULL)
        
    {
        
        printf("不能打开文件!\n");
        
        exit(-1);
        
    }
    fwrite(stu, sizeof(struct student), *len, fp);
    fclose(fp);
    
}

void IO_WriteInfo3(int *len)

{
    FILE *fp;
    if ((fp=fopen("/Users/huxiao/Desktop/github/student-management/Database2.txt","wt"))==NULL)
        
    {
        
        printf("不能打开文件!\n");
        
        exit(-1);
        
    }
    fwrite(stu, sizeof(struct student), *len, fp);
    fclose(fp);
    
}




void update(int len)
{
    IO_ReadInfo(&len);
    IO_WriteInfo1(&len);
    int i=0,j=0;
    char num1;
    char num2;
    char num3;
    char num4;
    float num5;
    float num6;
    float num7;
    int a;
    printf("请输入要进行修改的学生学号:");
    scanf("%s",&num1);
    for(i=0;i<len;i++)
    {
        if(strcmp(stu[i].num,&num1)==0)
        {
            break;
        }
        
    }
    if(i==len)
    {
        printf("不存在此人!!!!!!!!\n");
        return;
    }
    printf("提示:'1'代表学号,'2'代表姓名,'3'代表性别,'4'代表语文成绩,'5'代表数学成绩,'6'代表英语成绩\n");
    printf("请输入要修改的信息项目:");
    scanf("%d",&a);
    switch (a) {
        case 1:
            printf("请输入修改后的值:");
            scanf("%s",&num2);
            for(j=0;j<len;j++)
            {
                if(strcmp(stu[j].num,&num2)==0)
                {
                    printf("此学号已经存在");
                    return;
                }
            }
            if(j==len)
            {
                strcpy(stu[i].num,&num2);
            }
            printf("                恭喜,修改成功\n");
            break;
        case 2:
            printf("请输入修改后的值:");
            scanf("%s",&num3);
            for(i=0;i<len;i++)
            {
                if(strcmp(stu[i].num,&num1)==0)
                {
                    strcpy(stu[i].name,&num3);
                }
            }
            printf("                恭喜,修改成功\n");
            break;
        case 3:
            printf("请输入修改后的值:");
            scanf("%s",&num4);
            for(i=0;i<len;i++)
            {
                if(strcmp(stu[i].num,&num1)==0)
                    strcpy(stu[i].sex,&num4);
            }
            printf("                恭喜,修改成功\n");
            break;
        case 4:
            printf("请输入修改后的值:");
            scanf("%f",&num5);
            for(i=0;i<len;i++)
            {
                if(strcmp(stu[i].num,&num1)==0)
                    stu[i].score1=num5;
            }
            printf("                恭喜,修改成功\n");
            break;
        case 5:
            printf("请输入修改后的值:");
            scanf("%f",&num6);
            for(i=0;i<len;i++)
            {
                if(strcmp(stu[i].num,&num1)==0)
                    stu[i].score2=num6;
            }
            printf("                恭喜,修改成功\n");
            break;
        case 6:
            printf("请输入修改后的值:");
            scanf("%f",&num7);
            for(i=0;i<len;i++)
            {
                if(strcmp(stu[i].num,&num1)==0)
                    stu[i].score3=num7;
            }
            printf("                恭喜,修改成功\n");
            break;
            
        default:
            printf("您的选择有误!!!!\n");
            break;
    }
    IO_WriteInfo3(&len);
}




//r:读 w:在文件头写 a:在文件末尾写
//r+:可读可写 w+:从新写 a+:可读可写,在文件末尾写

int main()
{
    int choose = 0;
    int choose1;
    int len=3;
    printf("如果您是要录入成绩或修改数据请输入1,其他操作请输入2:");
    scanf("%d",&choose1);
    switch (choose1) {
        case 1:
        {
            printf("      ----------1代表输入学生成绩,2代表修改学生信息-------------\n");
            printf("你的选择是:");
            scanf("%d",&choose);
            switch (choose) {
                case 1:
                    printf("首先请输入学生人数:");
                    scanf("%d",&len);
                    input(len);
                    IO_WriteInfo(&len);
                    break;
                    
                case 2:
                    update(len);
                    output(len);
                    break;
                    
                default:
                    break;
            }
            break;
        }
         
            
        case 2:
            while(1)
            {
                menu();
                printf("请选择0--7:  ");
                scanf("%d",&choose);
                switch(choose)
                {
                        
                    case 1:
                    {
                        IO_ReadInfo(&len);
                        break;
                    }
                        
                    case 2:
                    {
                        max(len);
                        break;
                    }
                        
                    case 3:
                    {
                        ave(len);
                        break;
                    }
                        
                    case 4:
                    {
                        sort(len);
                        IO_WriteInfo1(&len);
                        break;
                    }
                        
                    case 5:
                    {
                        delete1(&len);
                        IO_WriteInfo1(&len);
                        break;
                    }
                        
                    case 6:
                    {
                        insert1(&len);
                        IO_WriteInfo1(&len);
                        break;
                    }
                        
                    case 7:
                    {
                        select1(len);
                        break;
                    }
                        
                    case 0:
                    {
                        exit(0);
                        break;
                    }
                    default:
                    {
                        printf("错误的输入，请重新输入：");
                    }
                        break;
                }
            }
            
        default:
            break;
    }
    
    
    
    
    return 0;
}
