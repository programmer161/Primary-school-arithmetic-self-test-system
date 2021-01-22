#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define E 1e-2
int check1,check2; // 定义所接收的输入题目的数量的全局变量 
float flag1,flag2; // 定义进行运算时输入正确格式时的数值全局变量 
int jishu=0; // 记录文件中指定的用户名与学号的位置 
void switch_1(char i); // 菜单选择序号 
void display3(); // 主界面的显示
void display2(); // 选择界面 
int jian(char *zhang,char *stu, char *mi,int j); // 检查用户帐号、身份与密码 
void zhuce(); // 注册界面 
void denglu(); // 登录界面 
void jiazai(); // 加载界面
void input(); // 类似于主函数 
void yonghu(); // 用户界面 
void qianyan(); // 前言界面 
void pingjia(); // 评价界面 
void shuoming(); // 说明界面 
void Func(int x); // 用于进行闯关时进行文字解说的函数 
void paixu(); // 加减成绩总排序 
void back(); // 寻找指定了用户名与学号的密码 
int cha(char *zhang,char *mi,int j); // 在文件中查找该帐号与密码是否相匹配 
float check(int x,float y); // 判断输入的格式是否正确 
float Division(int n);
void Multiplication(); // 乘法函数 
int  Division_main(); // 除法函数 
void add(); // 加法函数 
void Sub(); // 减法函数 
char xuanze(char x, char y, char result[]); // 判断选择界面的输入格式是否正确 
char xuanze2(char a, char b,char c, char d,char e, char f, char g,char result[]); // 判断主界面中的选择输入是否正确 
float score1[100]; // 加法分数
float score2[100]; // 减法分数 
int f1=0; // 加法下标计数 
int f2=0; // 减法下标计数 
char zhengque; // 定义选择输入所接收的正确输入时的字符 
int main()
{
 	display3();
 	printf("\n\n\n\t\t\t注册 <1> \t\t    登录 <2>");
	printf("\n\n\t\t\t\t\t  ");
	char i[100];
	scanf("%s",i);
	zhengque = xuanze('1','2',i);
	switch(zhengque)
	{
		case '1':
			system("cls");
			zhuce();
			jiazai();
			input();
			break;
		case '2':
			system("cls");
			denglu();
			jiazai();
			input();
			break;
	 } 
 }
void display3()
{
	printf("\n\n\n\n");
	printf("                \t        C语言程序设计项目案例      \n");
	printf("                \t-------------------------------------\n");
	printf("                \t*    名称：小学生算术自测系统       *\n"); 
	printf("                \t*    工具： C-Free4.0 C语言         *\n");
	printf("                \t*    作者： 第二组                  *\n");
	printf("                \t-------------------------------------\n"); 
 } 
 
 void zhuce()
 {
	char zhang[4],mi[4],stu[4];
	int m,n,t,k=0;
	do
	{
		FILE *ptr1, *ptr2;
		FILE *ptr3;
		if((ptr1=fopen("zhanghu.txt","a"))==NULL||(ptr2=fopen("mima.txt","a"))==NULL||(ptr3=fopen("zhaohui.txt","a"))==NULL)
		{
			printf("很抱歉，注册失败！");
		}
		printf("\n\n************* ^-^ ^-^ 小朋友，用户名、学号和密码最多三位哟！^-^ ^-^ ******************");
		printf("\n\n\n\t\t\t\t新用户名：") ;
		scanf("%s",zhang);
		printf("\n\n\n\t\t\t\t学    号：");
		scanf("%s",stu);
		printf("\n\n\n\t\t\t\t新 密 码：");
		scanf("%s",mi);
		m=strlen(zhang);
		t=strlen(stu);
		n=strlen(mi);
		if(m>3||t>3||n>3)
		{
	 		printf("\n\n\n\t\t\t用户格式输入错误，注册失败 !");
	 		printf("\n\n\t\t\t        请重新注册哟！");
	 		Sleep(2500); 
	 		system("cls");	
		}
		else
		{
			int g;
			int i;
			for(i=m;i<3;i++)
			{
				zhang[i]='*';
			}
			for(i=t;i<3;i++){
				stu[i]='*';
			}
			g=jian(zhang,stu,mi,0);
			if(g!=0)
			{
				fputs(stu,ptr3);
				fputs(mi,ptr2);
				fputs(zhang,ptr1);
				int i;
				for(i=n;i<3;i++)
				{
					fputc('*',ptr2);
				}
				fclose(ptr1);
				fclose(ptr2);
				fclose(ptr3);
				printf("\n\n\n\t\t\t\t恭喜你，注册成功！");
				printf("\n\n\n\t\t返回登陆界面 <1>\t\t返回系统，下次登陆<2>"); 
				char j[100];
				printf("\n\n\t\t\t\t\t");
				scanf(" %s",j);
				zhengque = xuanze('1','2',j);
				switch(zhengque)
				{
					case '1':
						system("cls");
						denglu();
						break;
					case '2':
			    		system("cls");
						printf("\n\n\n\n****************************要经常回来看我哦，我在这等你************************！");
						printf("\n\n\n\t\t\t*再见，小朋友！^-^ ^-^ ^-^ ^-^*"); 
						Sleep(3000);
						exit(1);
						break;
				}
			} 
			if(g==0)
			{
				printf("\n\n\n\t\t很抱歉，该用户或者学号已经存在！,请重新注册！\n");
				printf("\n\t\t重新登录 <1>\t\t\t再次注册 <2>\n\t\t\t\t     ");
				char t[100];
				scanf(" %s",t);
				zhengque = xuanze('1','2',t);
				switch(zhengque){
					case '1':
						system("cls");
						denglu();
						break;
					case '2':
						m=4,n=4;
						system("cls");
				}
			}
		}	
	}while(m>3||n>3);
 }
 
 void denglu()
 {
 	int hao;
 	FILE *pt1,*pt2;
 	if((pt1=fopen("zhanghu.txt","a"))==NULL||(pt2=fopen("mima.txt","a"))==NULL)
 	{
 		printf("\n\n\n\n\n\t\t\t很抱歉，登录失败！"); 
	}
	int m,n;
	char a[4],b[4];
	do
	{
		printf("\n\n******************** ^-^ ^-^ 小朋友，欢迎来到算术系统！^-^ ^-^ **********************");
		printf("\n\n\n\n\t\t\t\t请输入用户名: \t");
		scanf("%s",a);
		printf("\n\n\t\t\t\t请输入 密 码：\t");
		scanf("%s",b);
		m=strlen(a);
		n=strlen(b);
		for(hao=m;hao<3;hao++){
			a[hao]='*';
		}
		for(hao=n;hao<3;hao++){
			b[hao]='*';
		}
		if(m>3||n>3)
		{
			printf("\n\n\n\t\t   用户格式错误，请重新输入：\t");
			Sleep(2000);
			system("cls");
		}
	}while(m>3||n>3);
	fclose(pt1);
	fclose(pt2);
	int lala;
	lala=cha(a,b,0);
	if(lala==1)
	{
	 	printf("\n\n\t\t*******************没有该用户****************");
	 	printf("\n\n\n\t\t重新登录 <1>\t\t\t\t新用户注册 <2>\n\t\t\t\t\t");
	 	char de[100];
	 	scanf(" %s",de);
	 	zhengque=xuanze('1','2',de);
	 	switch(zhengque){
	 		case '1':
	 			system("cls");
	 			denglu();
	 			break;
	 		case '2':
	 			system("cls");
	 			zhuce();
	 			break;
		 }
	}
	else
	{
	 	int chuan;
		chuan=cha(a,b,1);
		if(chuan==0)
		{
			printf("\n\n\n\t\t\t\t  密码输入错误");
			printf("\n\n\n\t\t重新登录<1>\t\t\t找回密码<2>\n\t\t\t\t     ");
			char choice[100]; 
			scanf(" %s",choice);
			zhengque=xuanze('1','2',choice);
			switch(zhengque){
				case '1':
					system("cls");
					denglu();
					break;
				case '2':
					system("cls");
					back();
					Sleep(2000);
					system("cls");
					denglu();
					break;
			} 
		}
	 }
 }
 int cha(char *zhang,char *mi,int j)
 {
 	
 	FILE *la,*na;
 	if(j==0)
 	{
 		if((la=fopen("zhanghu.txt","r"))==NULL)
 		{
 		printf("\n\n\n\t\t\t抱歉，注册失败！"); 
	 	}
		char a[4];
		for(;;)
		{
	 		int i;
	 		for(i=0;i<3;i++)
	 		{
	 			if((a[i]=fgetc(la))==EOF)
	 			{
	 				goto end;
		 		}
	 		}
	 		jishu++;
	 		a[3]='\0';
	 		if(!strcmp(zhang,a))
	 		{
	 			fclose(la);
	 			return 0;
	 		}
		}
		end:
			return 1;
	}
	else if(j==1)
	{
	 	FILE *ha;
	 	if((ha=fopen("zhanghu.txt","r"))==NULL||(na=fopen("mima.txt","r"))==NULL)
	 	{
	 		printf("\n\n\n\t\t\t抱歉，注册失败！"); 
		 }
		 char c[4],b[4];
		 int m,n;
		 for(;;)
		 {
		 	 for(m=0;m<3;m++)
		 	{
		 		if((c[m]=fgetc(ha))==EOF)
	 	   		{
	 				goto hu;
		   		}
		 		b[m]=fgetc(na);
		 	}
		 	c[3]='\0';
		 	b[3]='\0';
		 	if(!strcmp(zhang,c)&&!strcmp(mi,b))
		 	{
		 		fclose(ha);
		 		fclose(na);
		 		return 1;
		 	}
		 }
		hu:
			fclose(ha);
			fclose(na);
			return 0;
	} 
	else{
	 	if((la=fopen("zhanghu.txt","r"))==NULL||(na=fopen("zhaohui.txt","r"))==NULL)
	 	{
	 		printf("\n\n\n\t\t\t抱歉，身份验证失败！"); 
		}
		char c[4],b[4];
		int m,n;
		for(;;)
		{
		 	for(m=0;m<3;m++)
		 	{
		 		if((c[m]=fgetc(la))==EOF)
	 	   		{
	 				goto xi;
		   		}
		 		b[m]=fgetc(na);
		 	}
		 	c[3]='\0';
		 	b[3]='\0';
		 	if(!strcmp(zhang,c)&&!strcmp(mi,b))
		 	{
		 		fclose(la);
		 		fclose(na);
		 		return 1;
		 	}
		}
		xi:
			fclose(la);
			fclose(na);
			return 0;
	}
}
int jian(char *zhang, char *stu, char *mi, int j)
{
 	
 	FILE *la,*na;
 	if(j==0)
 	{
 		if((la=fopen("zhanghu.txt","r"))== NULL || (na=fopen("zhaohui.txt","r"))==NULL)
 		{
 		printf("\n\n\n\t\t\t抱歉，注册失败！"); 
	 	}
		char a[4],b[4];
		for(;;)
		{
	 		int i;
	 		for(i=0;i<3;i++)
	 		{
	 			if((a[i]=fgetc(la))==EOF)
	 			{
	 				goto end;
		 		}
		 		b[i]=fgetc(na);
	 		}
	 		a[3]='\0';
	 		if(!strcmp(zhang,a)||!strcmp(stu,b))
	 		{
	 			fclose(na);
	 			fclose(la);
	 			return 0;
	 		}
		}
		end:
			return 1;
	}
	else
	{
	 	FILE *ha;
	 	if((ha=fopen("zhanghu.txt","r"))==NULL||(la=fopen("zhaohui.txt","r"))==NULL||(na=fopen("mima.txt","r"))==NULL)
	 	{
	 		printf("\n\n\n\t\t\t抱歉，注册失败！"); 
		}
		char a[4],c[4],b[4];
		int m,n;
		for(;;)
		{
		 	for(m=0;m<3;m++)
		 	{
		 		if((c[m]=fgetc(ha))==EOF)
	 	   		{
	 				goto hu;
		   		}
		   		a[m]=fgetc(la);
		 		b[m]=fgetc(na);
		 	}
		 	a[3]='\0';
		 	c[3]='\0';
		 	b[3]='\0';
		 	if(!strcmp(zhang,c)&&!strcmp(mi,b)&&!strcmp(stu,a))
		 	{
		 		fclose(la);
		 		fclose(ha);
		 		fclose(na);
		 		return 1;
		 	}
		 }
		hu:
			fclose(la);
			fclose(ha);
			fclose(na);
			return 0;
	} 
 }
 void jiazai()
 {
 	int i;
	printf("\n\n  =程序加载中〉〉〉〉");
	for(i=0;i<29;i++)
	{
		printf("■");
		Sleep(100);
	 } 
	 system("cls");
}
 
void input()
{
	qianyan();
	int c;
    char b;
    getchar();
    c = getchar();
    system("cls");
	while(1)
	{
		display2();
		char i[100];
		do
		{
			scanf(" %s",i);
			zhengque=xuanze2('1','2','3','4','5','6','0',i);
			switch_1(zhengque);	
		}while(zhengque != '0'); 
	}		
}

void qianyan()
{
	printf("\n[载入完成]\n\n");
	printf("                                    前言\n\n"); 
	printf("   欢迎使用[小学生算数自测系统]，本程序以全菜单形式实现了以下功能:小学生的加法，减法，乘法和除法\n\n");
	printf("出于学生信息的隐私性，我们在程序上加入了管理员登录模块以保证学生信息的安全性.\n\n");
    printf("本程序虽然能成功编译并运行，但在实际应用中可能还会出现各种问题，请各位老师与司学批评指正，欢迎大家提出宝贵意见!\n\n");
	printf("温馨提示:小朋友在做题之前请先选择菜单5，了解一下则试规则.\n\n");
	printf("测试结束后可以选择菜单6时对本次测试进行打分。\n\n");
    printf("请按任意键继续....."); 
}
 
void display2()
{
	printf("******************************************************--------------------\n");
	printf("小朋友，欢迎你们来学习算术^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^^-^ ^-^ ^-^");
	printf("\n\t\t\t\t\t\t\t1.加法\n"); 
	printf("\t\t\t\t\t2.减法\n");
	printf("\t\t\t3.乘法\n");
	printf("\t4.除法\t\t\t\t\t\t\t5.说明\n"); 
	printf("\t\t\t\t\t\t6.评价\n");
	printf("\t\t\t\t0.退出\n");
	printf("快选择你要学习的内容吧！^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^\n");
	printf("**************************************************************请选择：") ;
}
void pingjia()
{
	printf("\t测试完之后是不是想对系统进行一番评价呢 ^-^ Y<1>N<2>:\t");
	char m[100];
	scanf(" %s",m);
	zhengque=xuanze('1','2',m);
	if(zhengque=='1')
	{
		int n;
		printf("\n\t您对这个测试系统满意吗？请打分哟！(0—10分)\t");
		scanf("%d",&n);
		printf("\n\t\t\t* * * ^-^ ^-^ 谢谢你的参与^-^ * * *\n"); 
	}
}
void shuoming()
{
	printf(" 这个系统总共有四个功能，分别对小学生的加法，减法，乘法和除法进行自测\n\n");
	printf("其中加法和减法我们采取打分，评等级的方式\n\n");
	printf("而乘法和除法我们采取过关的方式\n\n");
	printf("注：分数总分为100，每小题的分数为总分除以题量，等级分为A.B.C.D D为不及格\n\n");
	printf("注：关卡的难度是根据随机数产生的不同范围确定的\n\n");
	printf("注：测试过程中会计时，小朋友要注意自已的解题速度噢\n\n");
	printf("制作者:第二组\n\n制作日期:2019年07月10日");
	
}

float Division(int n){
	int a,b;
	float m;
	srand(time(NULL));
	if(n==1){
	a=rand()%9+1;
	b=rand()%9+1;
	}
	if(n==2){
		a=rand()%89+10;
		b=rand()%9+1;
	}
	if(n==3){
		a=rand()%89+10;
		b=rand()%89+10;
	}
	if(a>b){
		printf("%d/%d=",a,b);
		if(a%b==0){
			return a/b;
		}
		else{
			return (float)a/b;
		}
	}
	else{
		printf("%d/%d=",b,a);
		if(b%a==0){
			return b/a;
		}
		else{
			return (float)b/a;
		}
	}
}
int Division_main(){
	int n,i;
	float m,x;
	char c[100];
	printf("欢迎来到第一关！\n");
	printf("请输入题量<建议题量20道左右>：\t");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	for(i=1;i<=check2;i++){
		printf("第%d题:",i);
		m=Division(1);
		flag1 = scanf("%f",&x);
		flag2 = check(flag1,x);
		if(fabs(flag2-m)<=E){
		 	printf("哇，你真聪明 !\n"); 
		}
		else{
		 	do{
		 		printf("答案错误，别灰心，请再次作答！\n"); 
		 		flag1 = scanf("%f",&x);
		 		flag2 = check(flag1,x);
			 }while(fabs(flag2-m)>E);
			printf("哇，你真聪明 ！\n");
			printf("\n");
		}
	}
	printf("你想再来一次吗？Y<1> or N<2>\n");
	scanf(" %s",c);
	zhengque=xuanze('1','2',c);
	if(zhengque=='1'){
		printf("可爱的小朋友，欢迎来到第二关\n");
		printf("请输入题量<建议题量10道左右>:\t"); 
		check1 = scanf("%d",&n);
		check2 = check(check1,n);
		for(i=1;i<=check2;i++){
			printf("第%d题:",i);
			m=Division(2);
			flag1 = scanf("%f",&x);
			flag2 = check(flag1,x);
			if(fabs(flag2-m)<=E){
		 		printf("哇，你真聪明 ！\n"); 
		 		printf("\n");
			}
			else{
		 		do{
		 			printf("答案错误，别灰心，请再次作答！\n"); 
		 			flag1 = scanf("%f",&x);
		 			flag2 = check(flag1,x);
				}while(fabs(flag2-m)>E);
				printf("哇，你真聪明 ！\n");
				printf("\n");
			}
		}
	}
	if(zhengque=='2'){
		return 0;
	}
	printf("你想再来一次吗？Y<1> or N<2>\n");
	scanf(" %s",c);
	zhengque=xuanze('1','2',c);
	if(zhengque=='1'){
		printf("可爱的小朋友，欢迎来到第三关\n");
		printf("请输入题量<建议题量10道左右>:\t"); 
		check1 = scanf("%d",&n);
		check2 = check(check1,n);
		for(i=1;i<=check2;i++){
		printf("第%d题:",i);
		 m=Division(3);
		 flag1 = scanf("%f",&x);
		 flag2 = check(flag1,x);
		 if(fabs(flag2-m)<=E){
		 	printf("哇，你真聪明 ！\n"); 
		 }
		 else{
		 	do{
		 		printf("答案错误，别灰心，请再次作答！\n"); 
		 		flag1 = scanf("%f",&x);
		 		flag2 = check(flag1,x);
			}while(fabs(flag2-m)>E);
			printf("哇，你真聪明 ！\n");
			printf("\n");
		} 
		printf("恭喜你通过了第三关\n"); 
		printf("恭喜闯关成功\n");
		}
	}
	if(zhengque=='2'){
		return 0; 
	}
}

void add(){
	int n,i,count=0,start,end;
	int addition1,addition2,result;
	char grade;
	float sum;
	printf("请选择题量<建议在20题左右>:");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	start = time(NULL);
	srand(time(NULL));
	for(i=0;i<check2;i++){
		addition1 = rand()%100+1;
		addition2 = rand()%100+1;
		printf("第%d题: %d + %d = \n",i+1,addition1,addition2);
		printf("请输入你的计算结果:") ;
		flag1 = scanf("%d",&result);
		flag2 = check(flag1,result);
		if(flag2 == addition1 + addition2){
			printf("\n回答正确，你真棒\n");
			count ++;
		}else{
			printf("\n回答错误，别灰心。 正确答案是：%d\n",addition1+addition2);
		}
	}
	sum = ((float)count/n)*100;
	if(sum >= 90){
		grade = 'A';
	}else if(sum >= 70 && sum < 90){
		grade = 'B';
	}
	else if (sum >= 60 && sum < 70){
		grade = 'C';
	}
	else{
		grade = 'D';
	}
	score1[f1]=sum;
	end = time(NULL);
	printf("本次考试用时：%d秒       本次测试分数为：%.0f   等级为：%c\n",end-start,sum,grade);
}
void Sub(){
	int n,i,count=0,start,end;
	int subtraction1,subtraction2,result;
	char grade;
	float sum;
	printf("请选择题量<建议在20题左右>:");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	start = time(NULL);
	srand(time(NULL));
	for(i=0;i<check2;i++){
		subtraction1 = rand()%100+1;
		subtraction2 = rand()%100+1;
		if(subtraction1>subtraction2){
			printf("第%d题: %d - %d = \n",i+1,subtraction1,subtraction2);	
		}else{
			printf("第%d题: %d - %d = \n",i+1,subtraction2,subtraction1);
		}
		printf("请输入你的计算结果:") ;
		flag1 = scanf("%d",&result);
		flag2 = check(flag1,result);
		if(flag2 == abs(subtraction1 - subtraction2)){
			printf("\n回答正确\n");
			count ++;
		}else{
			printf("\n回答错误，别灰心。 正确答案是：%d\n",abs(subtraction1-subtraction2));
		}
	}
	sum = ((float)count/n)*100;
	if(sum >= 90){
		grade = 'A';
	}else if(sum >= 70 && sum < 90){
		grade = 'B';
	}
	else if (sum >= 60 && sum < 70){
		grade = 'C';
	}
	else{
		grade = 'D';
	}
	score2[f2]=sum;
	end = time(NULL);
	printf("本次考试用时：%d秒       本次测试分数为：%.0f    等级为：%c\n",end-start,sum,grade);	
}
void Func(int x){
	if(x == 0){
		printf("欢迎进入第一关！\n");
		printf("请设定题目数量<建议在10题左右>："); 
	}else if(x == 1){
		printf("欢迎进入第二关！\n");
		printf("请设定题目数量<建议在10题左右>：");
	}else if(x == 2){
		printf("欢迎进入第三关！\n");
		printf("请设定题目数量<建议在10题左右>：");
	} 
}
void Multiplication(){
	int m = 0, n, i;
	char count[100];
	int multi1,multi2,result;
	srand(time(NULL));
	do{
		Func(m);
		check1 = scanf("%d",&n);
		check2 = check(check1,n);
		if(m == 0){
			for(i=1;i<=check2;i++){
				multi1 = rand() % 10;
				multi2 = rand() % 10;
				printf("第%d题:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1 = scanf("%d",&result);
				flag2 = check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("恭喜你，回答正确！\n"); 
				}else{
					do{
						printf("回答错误，请重新回答！\n"); 
						flag1 = scanf("%d",&result);
						flag2 = check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("恭喜你，回答正确！\n");
				}
			}
			printf("恭喜你通过第一关！\n\n");
			printf("是否继续挑战？Y<1>/N<2>:");
			scanf(" %s",count);	
			zhengque=xuanze('1','2',count);
		}
		if(m == 1){
			for(i=1;i<=check2;i++){
				multi1 = rand() % 11;
				multi2 = rand() % 90+10;
				printf("第%d题:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1 = scanf("%d",&result);
				flag2 = check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("恭喜你，回答正确！\n\n"); 
				}else{
					do{
						printf("回答错误，请重新回答！\n"); 
						flag1 = scanf("%d",&result);
						flag2 = check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("恭喜你，回答正确！\n\n");
				}
			}
			printf("恭喜你通过第二关！\n");
			printf("是否继续挑战？Y<1>/N<2>:");
			scanf(" %s",count);
			zhengque=xuanze('1','2',count);
		}
		if(m == 2){
			for(i=1;i<=check2;i++){
				multi1 = rand() % 90+10;
				multi2 = rand() % 90+10;
				printf("第%d题:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1=scanf("%d",&result);
				flag2=check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("恭喜你，回答正确！\n\n"); 
				}else{
					do{
						printf("回答错误，请重新回答！\n"); 
						flag1=scanf("%d",&result);
						flag2=check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("恭喜你，回答正确！\n\n");
				}
			}
			printf("恭喜你通过第三关！\n");
			printf("恭喜闯关成功！\n\n");
		}
		m++;
	}while(zhengque == '1' && m <3);		
}
void paixu(){
	int temp;
	for(int j=0;j<f1;j++){
		for(int k=0;k<f1-j-1;k++){
			if(score1[k]>score1[k+1]){
				temp = score1[k];
				score1[k] = score1[k+1];
				score1[k+1] = temp;
			}
		}
	}
	for(int j=0;j<f2;j++){
		for(int k=0;k<f2-j-1;k++){
			if(score2[k]>score2[k+1]){
				temp = score2[k];
				score2[k] = score2[k+1];
				score2[k+1] = temp;
			}
		}
	}
	if(f1!=0){
	printf("小朋友，你的加法成绩出炉啦！^-^\n你的成绩从低到高分别是：\n");
	for(int j=0;j<f1;j++){
		printf("%.0f\t",score1[j]);
	}
	printf("\n"); 
	printf("你加法的最高成绩是：%.0f\n你加法的最低成绩是：%.0f\n\n",score1[f1-1],score1[0]);
}
	if(f2!=0){
	printf("小朋友，你的减法成绩出炉啦！^-^\n你的成绩从低到高分别是：\n");
	for(int j=0;j<f2;j++){
		printf("%.0f\t",score2[j]);
	}
	printf("\n"); 
	printf("你减法的最高成绩是：%.0f\n你减法的最低成绩是：%.0f",score2[f2-1],score2[0]);
}
}
void back(){
	char a[4],b[4];
	char s[1000];
	int i,j=0,t,count = 0,m,n,hao; 
	do
	{
		printf("\n\n\n\t***********^-^ ^-^小朋友欢迎来到找回密码界面 ^-^ ^-^***********");
		printf("\n\n\n\n\t\t\t\t请输入用户名:\t");
		scanf("%s",a);
		printf("\n\n\t\t\t\t请输入学号：\t");
		scanf("%s",b);
		m=strlen(a);
		n=strlen(b);
		for(hao=m;hao<3;hao++){
			a[hao]='*';
		}
		for(hao=n;hao<3;hao++){
			b[hao]='*';
		}
		if(m>3||n>3)
		{
			printf("\n\n\n\t\t用户格式错误，请重新输入：");
			Sleep(2000);
			system("cls");
		}
	}while(m>3||n>3);
	t=cha(a,b,2);
	if(t==1){
		FILE *fp;
		if((fp=fopen("mima.txt","r"))==NULL){
			printf("不能找回该密码！");
			exit(0);
		}
		printf("\n\n\t\t\t\t  身份验证成功！"); 
		printf("\n\n\t\t\t\t该用户的密码为：");
		for(i=0;;i++){
			for(j=0;j<3;j++){
				s[j]=fgetc(fp);
			}
			if(i==jishu-1){
				count=3;
				for(j=0;j<3;j++){
					if(s[j]=='*'){
						count --;
					}
				}
				for(j=0;j<count;j++){
					printf("%c",s[j]);
				}
				break;
			}
		}
		jishu = 0;
	}else{
		printf("\n\n\t\t\t\t身份验证失败");
		printf("\n\n\t\t重新输入<1>\t\t\t重新注册<2>\n\n\t\t\t\t     ");
		char choice[100];
		scanf(" %s",choice);
		zhengque=xuanze('1','2',choice);
		switch(zhengque){
			case '1':
				system("cls");
				back();
				break;
			case '2':
				system("cls");
				zhuce();
				break;
		}
	}
}
char xuanze(char x,char y,char result[]){
	int count=0;
	if(strlen(result) > 1){
		count++;
	}
	if((result[0] != x && result[0] != y)||count !=0){
		
		do{
			count = 0;
			if(strlen(result) > 1){
				count++;
				printf("\n\t  选择输入格式错误，请重新输入：  ");
				scanf("%s",result);
				if(strlen(result)==1){
					count = 0;
				}
			}else{
				printf("\n\t  选择输入格式错误，请重新输入：  ");
				scanf("%s",result);
			}
		}while((result[0] != x && result[0] != y)||count !=0);	
	}
	else{
		return result[0];
	}
}
char xuanze2(char a,char b,char c, char d, char e,char f,char g,char result[]){
	int count;
	if(strlen(result) > 1){
		count++;
	}
	if((result[0] != a&&result[0] != b&&result[0] != c&&result[0] != d&&result[0] != e&&result[0] != f&&result[0] != g)||count!=0){
		do{
			count=0;
			if(strlen(result)>1){
				printf("选择输入格式错误，请重新输入："); 
				count++;
				scanf("%s",result);
				if(strlen(result)==1){
					count=0;
				}
			}else{ 
				printf("选择输入格式错误，请重新输入：");
				scanf("%s",result);
			}
		}while((result[0] != a&&result[0] != b&&result[0] != c&&result[0] != d&&result[0] != e&&result[0] != f&&result[0] != g)||count!=0);
	}
	else{
			return result[0];
		}
}
void switch_1(char i)
{				
	char j,k;
	switch(i){
		case '1':  //加法入口
			add(); 
			f1++;
			display2();
			break;
		case '2':  //减法入口 
			Sub();
			display2();
			f2++;
			break;
		case '3':  //乘法入口 
			Multiplication();
			display2();
			break;
		case '4':  //除法入口 
			Division_main();
			display2();
			break;
		case '5':  //说明入口 
			shuoming();
			display2();
			break;
		case '6':  //评价入口 
			pingjia();
			display2();
			break;
		case '0':
			system("cls");
			display3();
			paixu(); 
			printf("\n是否还要继续答题:是<1>\t退出<2>\n");
			scanf(" %c",&j);
			if(j=='1'){
				system("cls");
				display2();
				scanf(" %c",&k);
				switch_1(k);
			} 
			if(j=='2') {
				Sleep(1000);
				exit(0);
			}	
	}
}
float check(int x,float y){
	char s[1000];
	int i;
	float a;
	if(x == 0){
		do{
			printf("输入格式错误，请正确输入："); 
			for(i=0; ;i++){
				s[i]=getchar();
				if(s[i]=='\n'){
				break;
				}
			}
			x = scanf("%f",&a);	
		}while(x == 0);
		return a;
	}
	else{
		return y;
	}
} 
