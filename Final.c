#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>//系统控制，Windows改为<windows.h>

typedef struct userData
{//定义userData结构体，储存用户数据
    char id[11];//账号
    char passCode[20];//密码
    char userName[15];//用户名
    char sex;//性别
    long phoneNumber;//电话号码
}dataBase;

//用户
void registeration();
int logIn();
void dumbAss();
void creatFile();
//打印ascii art
void printLogo0();
void printLogo1();
void printLogo2();
void printLogo3();
void printLogo4();
void printOPT();
void printO1();
void printO2();
void printIntro2();
void printWel();
void printId();
void printPw();
void printSa();
void printPho();
void printSex();
void printName();
void printSa2();
void printFg();
void printHa();
void printRem();

void printEx();
void printAl();
void printBa();
void printBdd();
void printXrr();
void printLight();
void printX();

//菜单
int option1();
void option2();

//主程序
int main()
{
    creatFile();//创建用户文件
    
    system("clear");
    
    int tem=0;
    tem = option1();//登陆并检测是否成功
    
    if(tem==5){
        option2();//成功则运行打印程序
    }
    else if(tem==7)
    {
        option1();
    }
    else
    {
        printf("Back Off Bitch!");//不成功则退出
    }
    return 0;
}

//初始菜单
int option1()
{
    printLogo0();//打印Logo
    system("clear");//清屏
    printOPT();//打印OPTION文字
    printf("\n\n\n");
    
    printO1();//打印选项
    printf("What do you want?\n\n");
    
    int option;//输入选项
    scanf("%d", &option);
    system("clear");

//选项1，注册
    if(option == 1)
    {
        registeration();
        return 5;
    }
//选项2，登陆，并检验是否登陆成功
    else if(option == 2)
    {
        if (logIn()==1) return 5;
        else    return 0;
    }
//选项3，忘记密码，找回密码
    else if(option == 3)
    {
        dumbAss();
        return 5;
    }
//选项4，推出程序
    else if(option == 4)
        {
            return 0;
        }
//输入其他，拜拜👋
    else
    {
        printf("Fuck U bitch and your mom 2!");
        return 999;
    }
    return 0;
}

//登陆成功菜单
void option2()
{
    printIntro2();//打印欢迎界面
    printf("\n\n");
    printO2();//打印ART菜单
    printf("Which one do you want?\n\n");
    
    int option;//输入选项，并打印
    scanf("%d", &option);
    system("clear");
    
    if(option == 1)
    {
        printLogo0();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 2)
    {
        printEx();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 3)
    {
        printBdd();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 4)
    {
        printXrr();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 5)
    {
        printLight();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 6)
    {
        printBa();
        printf("\n\n");
        getchar();
        system("clear");
    }
    else if(option == 520)
        {
            printX();
            printf("\n\n");
            getchar();
            system("clear");
        }
    else if(option == 0)
    {
        return;
    }
    option2();
}

/*创建储存用户账号密码的文件*/
void creatFile()
{
    FILE *fp;
    if ((fp = fopen("userData.txt","rb"))==NULL)/*如果此文件不存在，则创建*/
    {
        if ((fp = fopen("userData.txt","wb+"))==NULL)/*检测文件创建错误*/
        {
            printf("Error creating file.\n\n");
            exit(0);
        }
    }
}


/*注册账号*/ 
void registeration()
{//按结构体的大小，一次写入1个用户
    dataBase a,b;//结构体 userData 重命名（简便）
    FILE *fp;
    char temp[20];
    int count = 0;
    printWel(); //欢迎注册
    printf("\n\n");
    fp = fopen("userData.txt","r");
    
    fread(&b, sizeof(struct userData), 1, fp);//读入一个结构体字符块 到b
    printId();
    printf("PLZ enter the coolest ID you can ever think of: \n\n");//输入注册ID
    scanf("%s",a.id);

    while (1)
    {//检查全部已有用户，防止ID重复。
        if (strcmp(a.id, b.id))
        {//如果两串不相等
            if (!feof(fp))
            {//如果未到文件尾，继续检测
                fread(&b, sizeof(struct userData), 1, fp);
            }
            else
                break;
        }
        else
        {//提醒ID重复，请重新选择
            printf("This cool ID is already taken.\n"
                   "PLZ select another cool one!\n\n"
            );
            fclose(fp);
            return;
        }
    }

//输入用户名
    printf("BTW, may us know your name\nSo that we can call you properly!\n\n");
    printName();
    scanf("%s",a.userName);
    system("clear");
    
//输入性别，包含男性，女性，变性，以及 不确定性别者
    printSex();
    printf("\n\n");
    scanf("%c",&a.sex);
    system("clear");
    
    do{//查性别错误
        if(a.sex != 'f' && a.sex != 'm' && a.sex != 't' && a.sex != 'n'
          && a.sex != 'F' && a.sex != 'M' && a.sex != 'T' && a.sex != 'N')
        {
            printf("You bitch don't know what are you?\n\n");
            scanf("%c",&a.sex);
        }
    }while(a.sex != 'f' && a.sex != 'm' && a.sex != 't');

//输入手机号，用于找回密码
    printf("May I have your number incase I wanna ask you out for a cup of coffee?\n\n");
    printPho();
    printf("\n\n");
    scanf("%ld",&a.phoneNumber);
    system("clear");

//选择密码
    printf("PLZ choose a rather very idoit password that anyone can guess!\n\n");
    printPw();//打印“密码”字符画
    printf("\n\n");
    scanf("%s",a.passCode);
    system("clear");
    printf("\n\n");
    printf("Are you sure?\n(Bday is forbidden here!)\n\n");
    printPw();
    printf("\n\n");
    scanf("%s",temp);//确认密码
    system("clear");
    
    do{//检测密码是否一致
        if(!strcmp(a.passCode,temp)){//一致则恭喜，并打印LOGO
            fp = fopen("userData.txt","a");
            fwrite(&a, sizeof(struct userData), 1, fp);
            printf("You are now one of our INDUSTRY!\nGo celebrate it!\n\n");
            printLogo1();
            printLogo2();
            printLogo3();
            printLogo4();
            fclose(fp);
            return;
        }else{//不一致则重新输入
            printf("You bitch can't enter the same password?\n\n");
            printSa();
            scanf("%s",a.passCode);
            printf("PLZ make up your mind and try again!\n\n");
            scanf("%s",temp);
        }
    }while(1);
    
    
}

//登录系统
int logIn()
{
    dataBase a,b;
    
    FILE *fp;
    printIntro2();//打印欢迎界面
    fp = fopen("userData.txt","r");
    
    fread(&b, sizeof(struct userData), 1, fp);//读入一个结构体字符块 写入b
    printf("PLZ enter you alIndustryID\n\n");//输入🆔，查找是否存在
    printId();
    scanf("%s",a.id);
    system("clear");
    
    while (1)
    {//在文件中查找
        if (strcmp(a.id, b.id)==0)//🆔存在
        {
                break;
            }
            
        else
        {
            if (!feof(fp))
            {//如果文件没有读完，继续
                fread(&b, sizeof(struct userData), 1, fp);
            }
            else
            {
                printSa2();
                fclose(fp);
                return 0;
            }
        }
    }
    printPw();//输入密码
    scanf("%s",a.passCode);
    system("clear");

    do{//验证账号密码是否一致
        if (strcmp(a.passCode, b.passCode)==0)//密码正确
        {
            fclose(fp);
            printf("Welcome back to AlxXxlA INDUSTRY, Bae!\n\n");
            return 1;
            break;

        }
        else//密码错误
        {
            printf("Wrong password\nGo FUCK yourself!\n\n");
            return 0;
            break;
        }
    }while(strcmp(a.passCode, b.passCode)==0);
    
}

/*找回密码*/
void dumbAss()
{
    dataBase a,b;
    FILE *fp;
    char temp[20];
    int count = 0;
    printFg();
    printHa();
    fp = fopen("userData.txt","r");
    
    fread(&b, sizeof(struct userData), 1, fp);//读入一个结构体字符块写入b
    printf("What's the 🆔 you wanna find?\n\n");//输入ID
    printId();
    scanf("%s",a.id);
    system("clear");
    
    while (1)//查找是否存在🆔
        {
            if (strcmp(a.id, b.id)==0)//ID存在
            {
                break;
            }
            else
            {
                if (!feof(fp))//如果文件没有读完，继续
                {
                    fread(&b, sizeof(struct userData), 1, fp);
                }
                else
                {//ID不存在，提示未注册
                    printf("You bitch haven't signup yet...\n\n");
                    fclose(fp);
                    return;
                }
            }
        }

    printf("What's your name?\n\n");//验证用户名
    printName();
    scanf("%s",a.userName);
    system("clear");

    do{
        if(strcmp(a.userName,b.userName))
        {//用户名错误，重新输入
            printf("Beep! Wrong name, call the cop! Or try again: \n\n");
            printName();
            scanf("%s",a.userName);
            system("clear");
        }
    }while(strcmp(a.userName,b.userName));

    printf("What's your number?\n\n");//验证手机号码
    printPho();
    scanf("%ld",&a.phoneNumber);
    system("clear");

    do{
        if(a.phoneNumber != b.phoneNumber)
        {//手机号码错误，重新输入
            printf("Beep! Wrong number, call the cop! Or try again:\n\n");
            printPho();
            scanf("%ld",&a.phoneNumber);
            system("clear");
        }
    }while(a.phoneNumber != b.phoneNumber);
//全部验证正确，提供密码，并提示牢记密码
    printf("Your password is: %s\n",b.passCode);
    printRem();
    option1();
}

//打印文字函数
void printLogo0()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("Logo.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printLogo1()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("Logo1.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printLogo2()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("Logo2.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printLogo3()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("Logo3.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printLogo4()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("logo4.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printOPT()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("OPT.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printO1()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("O1.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printO2()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("O2.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printIntro2()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("Intro2.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}


void printWel()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("reg-1.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printId()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("reg-2.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printPw()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("reg-3.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printSa()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("reg-4.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printPho()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("reg-5.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printSex()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("sex.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printName()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("name.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printSa2()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("sa2.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printFg()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("fg.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printHa()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("haha.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printRem()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("rem.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}

/*打印ASCII ART*/
void printEx()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("EX.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}

void printBa()
{
    FILE * fp;
    fp = fopen("badapple.txt", "r");
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    printf("%d\n", file_size);
    char * tmp;
    fseek(fp, 0, SEEK_SET);
    tmp = (char *)malloc(file_size * sizeof(char));
    fread(tmp, file_size, sizeof(char), fp);
    char * delim = "nekomark";
    char * p = NULL;
    
    p = strtok(tmp, delim);
    while (p != NULL)
    {
        system("clear");
        printf("%s", p);
        usleep(50000);
        p = strtok(NULL, delim);
    }
    return;
}
void printXrr()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("xrr.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printBdd()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("bdd.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printLight()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("light.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}
void printX()
{
    FILE*fp;
    char ch;
    if (NULL==(fp=fopen("x.txt","r")))
        {
            printf("error\n");
            return;
        }
    ch = fgetc(fp);
    while(!feof(fp))
        {
            putchar(ch);
            ch = fgetc(fp);
        }
    fclose(fp);
    getchar();
    return;
}