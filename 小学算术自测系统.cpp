#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define E 1e-2
int check1,check2; // ���������յ�������Ŀ��������ȫ�ֱ��� 
float flag1,flag2; // �����������ʱ������ȷ��ʽʱ����ֵȫ�ֱ��� 
int jishu=0; // ��¼�ļ���ָ�����û�����ѧ�ŵ�λ�� 
void switch_1(char i); // �˵�ѡ����� 
void display3(); // ���������ʾ
void display2(); // ѡ����� 
int jian(char *zhang,char *stu, char *mi,int j); // ����û��ʺš���������� 
void zhuce(); // ע����� 
void denglu(); // ��¼���� 
void jiazai(); // ���ؽ���
void input(); // ������������ 
void yonghu(); // �û����� 
void qianyan(); // ǰ�Խ��� 
void pingjia(); // ���۽��� 
void shuoming(); // ˵������ 
void Func(int x); // ���ڽ��д���ʱ�������ֽ�˵�ĺ��� 
void paixu(); // �Ӽ��ɼ������� 
void back(); // Ѱ��ָ�����û�����ѧ�ŵ����� 
int cha(char *zhang,char *mi,int j); // ���ļ��в��Ҹ��ʺ��������Ƿ���ƥ�� 
float check(int x,float y); // �ж�����ĸ�ʽ�Ƿ���ȷ 
float Division(int n);
void Multiplication(); // �˷����� 
int  Division_main(); // �������� 
void add(); // �ӷ����� 
void Sub(); // �������� 
char xuanze(char x, char y, char result[]); // �ж�ѡ�����������ʽ�Ƿ���ȷ 
char xuanze2(char a, char b,char c, char d,char e, char f, char g,char result[]); // �ж��������е�ѡ�������Ƿ���ȷ 
float score1[100]; // �ӷ�����
float score2[100]; // �������� 
int f1=0; // �ӷ��±���� 
int f2=0; // �����±���� 
char zhengque; // ����ѡ�����������յ���ȷ����ʱ���ַ� 
int main()
{
 	display3();
 	printf("\n\n\n\t\t\tע�� <1> \t\t    ��¼ <2>");
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
	printf("                \t        C���Գ��������Ŀ����      \n");
	printf("                \t-------------------------------------\n");
	printf("                \t*    ���ƣ�Сѧ�������Բ�ϵͳ       *\n"); 
	printf("                \t*    ���ߣ� C-Free4.0 C����         *\n");
	printf("                \t*    ���ߣ� �ڶ���                  *\n");
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
			printf("�ܱ�Ǹ��ע��ʧ�ܣ�");
		}
		printf("\n\n************* ^-^ ^-^ С���ѣ��û�����ѧ�ź����������λӴ��^-^ ^-^ ******************");
		printf("\n\n\n\t\t\t\t���û�����") ;
		scanf("%s",zhang);
		printf("\n\n\n\t\t\t\tѧ    �ţ�");
		scanf("%s",stu);
		printf("\n\n\n\t\t\t\t�� �� �룺");
		scanf("%s",mi);
		m=strlen(zhang);
		t=strlen(stu);
		n=strlen(mi);
		if(m>3||t>3||n>3)
		{
	 		printf("\n\n\n\t\t\t�û���ʽ�������ע��ʧ�� !");
	 		printf("\n\n\t\t\t        ������ע��Ӵ��");
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
				printf("\n\n\n\t\t\t\t��ϲ�㣬ע��ɹ���");
				printf("\n\n\n\t\t���ص�½���� <1>\t\t����ϵͳ���´ε�½<2>"); 
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
						printf("\n\n\n\n****************************Ҫ������������Ŷ�����������************************��");
						printf("\n\n\n\t\t\t*�ټ���С���ѣ�^-^ ^-^ ^-^ ^-^*"); 
						Sleep(3000);
						exit(1);
						break;
				}
			} 
			if(g==0)
			{
				printf("\n\n\n\t\t�ܱ�Ǹ�����û�����ѧ���Ѿ����ڣ�,������ע�ᣡ\n");
				printf("\n\t\t���µ�¼ <1>\t\t\t�ٴ�ע�� <2>\n\t\t\t\t     ");
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
 		printf("\n\n\n\n\n\t\t\t�ܱ�Ǹ����¼ʧ�ܣ�"); 
	}
	int m,n;
	char a[4],b[4];
	do
	{
		printf("\n\n******************** ^-^ ^-^ С���ѣ���ӭ��������ϵͳ��^-^ ^-^ **********************");
		printf("\n\n\n\n\t\t\t\t�������û���: \t");
		scanf("%s",a);
		printf("\n\n\t\t\t\t������ �� �룺\t");
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
			printf("\n\n\n\t\t   �û���ʽ�������������룺\t");
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
	 	printf("\n\n\t\t*******************û�и��û�****************");
	 	printf("\n\n\n\t\t���µ�¼ <1>\t\t\t\t���û�ע�� <2>\n\t\t\t\t\t");
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
			printf("\n\n\n\t\t\t\t  �����������");
			printf("\n\n\n\t\t���µ�¼<1>\t\t\t�һ�����<2>\n\t\t\t\t     ");
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
 		printf("\n\n\n\t\t\t��Ǹ��ע��ʧ�ܣ�"); 
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
	 		printf("\n\n\n\t\t\t��Ǹ��ע��ʧ�ܣ�"); 
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
	 		printf("\n\n\n\t\t\t��Ǹ�������֤ʧ�ܣ�"); 
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
 		printf("\n\n\n\t\t\t��Ǹ��ע��ʧ�ܣ�"); 
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
	 		printf("\n\n\n\t\t\t��Ǹ��ע��ʧ�ܣ�"); 
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
	printf("\n\n  =��������С�������");
	for(i=0;i<29;i++)
	{
		printf("��");
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
	printf("\n[�������]\n\n");
	printf("                                    ǰ��\n\n"); 
	printf("   ��ӭʹ��[Сѧ�������Բ�ϵͳ]����������ȫ�˵���ʽʵ�������¹���:Сѧ���ļӷ����������˷��ͳ���\n\n");
	printf("����ѧ����Ϣ����˽�ԣ������ڳ����ϼ����˹���Ա��¼ģ���Ա�֤ѧ����Ϣ�İ�ȫ��.\n\n");
    printf("��������Ȼ�ܳɹ����벢���У�����ʵ��Ӧ���п��ܻ�����ָ������⣬���λ��ʦ��˾ѧ����ָ������ӭ�������������!\n\n");
	printf("��ܰ��ʾ:С����������֮ǰ����ѡ��˵�5���˽�һ�����Թ���.\n\n");
	printf("���Խ��������ѡ��˵�6ʱ�Ա��β��Խ��д�֡�\n\n");
    printf("�밴���������....."); 
}
 
void display2()
{
	printf("******************************************************--------------------\n");
	printf("С���ѣ���ӭ������ѧϰ����^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^^-^ ^-^ ^-^");
	printf("\n\t\t\t\t\t\t\t1.�ӷ�\n"); 
	printf("\t\t\t\t\t2.����\n");
	printf("\t\t\t3.�˷�\n");
	printf("\t4.����\t\t\t\t\t\t\t5.˵��\n"); 
	printf("\t\t\t\t\t\t6.����\n");
	printf("\t\t\t\t0.�˳�\n");
	printf("��ѡ����Ҫѧϰ�����ݰɣ�^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^ ^-^\n");
	printf("**************************************************************��ѡ��") ;
}
void pingjia()
{
	printf("\t������֮���ǲ������ϵͳ����һ�������� ^-^ Y<1>N<2>:\t");
	char m[100];
	scanf(" %s",m);
	zhengque=xuanze('1','2',m);
	if(zhengque=='1')
	{
		int n;
		printf("\n\t�����������ϵͳ����������Ӵ��(0��10��)\t");
		scanf("%d",&n);
		printf("\n\t\t\t* * * ^-^ ^-^ лл��Ĳ���^-^ * * *\n"); 
	}
}
void shuoming()
{
	printf(" ���ϵͳ�ܹ����ĸ����ܣ��ֱ��Сѧ���ļӷ����������˷��ͳ��������Բ�\n\n");
	printf("���мӷ��ͼ������ǲ�ȡ��֣����ȼ��ķ�ʽ\n\n");
	printf("���˷��ͳ������ǲ�ȡ���صķ�ʽ\n\n");
	printf("ע�������ܷ�Ϊ100��ÿС��ķ���Ϊ�ֳܷ����������ȼ���ΪA.B.C.D DΪ������\n\n");
	printf("ע���ؿ����Ѷ��Ǹ�������������Ĳ�ͬ��Χȷ����\n\n");
	printf("ע�����Թ����л��ʱ��С����Ҫע�����ѵĽ����ٶ���\n\n");
	printf("������:�ڶ���\n\n��������:2019��07��10��");
	
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
	printf("��ӭ������һ�أ�\n");
	printf("����������<��������20������>��\t");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	for(i=1;i<=check2;i++){
		printf("��%d��:",i);
		m=Division(1);
		flag1 = scanf("%f",&x);
		flag2 = check(flag1,x);
		if(fabs(flag2-m)<=E){
		 	printf("�ۣ�������� !\n"); 
		}
		else{
		 	do{
		 		printf("�𰸴��󣬱���ģ����ٴ�����\n"); 
		 		flag1 = scanf("%f",&x);
		 		flag2 = check(flag1,x);
			 }while(fabs(flag2-m)>E);
			printf("�ۣ�������� ��\n");
			printf("\n");
		}
	}
	printf("��������һ����Y<1> or N<2>\n");
	scanf(" %s",c);
	zhengque=xuanze('1','2',c);
	if(zhengque=='1'){
		printf("�ɰ���С���ѣ���ӭ�����ڶ���\n");
		printf("����������<��������10������>:\t"); 
		check1 = scanf("%d",&n);
		check2 = check(check1,n);
		for(i=1;i<=check2;i++){
			printf("��%d��:",i);
			m=Division(2);
			flag1 = scanf("%f",&x);
			flag2 = check(flag1,x);
			if(fabs(flag2-m)<=E){
		 		printf("�ۣ�������� ��\n"); 
		 		printf("\n");
			}
			else{
		 		do{
		 			printf("�𰸴��󣬱���ģ����ٴ�����\n"); 
		 			flag1 = scanf("%f",&x);
		 			flag2 = check(flag1,x);
				}while(fabs(flag2-m)>E);
				printf("�ۣ�������� ��\n");
				printf("\n");
			}
		}
	}
	if(zhengque=='2'){
		return 0;
	}
	printf("��������һ����Y<1> or N<2>\n");
	scanf(" %s",c);
	zhengque=xuanze('1','2',c);
	if(zhengque=='1'){
		printf("�ɰ���С���ѣ���ӭ����������\n");
		printf("����������<��������10������>:\t"); 
		check1 = scanf("%d",&n);
		check2 = check(check1,n);
		for(i=1;i<=check2;i++){
		printf("��%d��:",i);
		 m=Division(3);
		 flag1 = scanf("%f",&x);
		 flag2 = check(flag1,x);
		 if(fabs(flag2-m)<=E){
		 	printf("�ۣ�������� ��\n"); 
		 }
		 else{
		 	do{
		 		printf("�𰸴��󣬱���ģ����ٴ�����\n"); 
		 		flag1 = scanf("%f",&x);
		 		flag2 = check(flag1,x);
			}while(fabs(flag2-m)>E);
			printf("�ۣ�������� ��\n");
			printf("\n");
		} 
		printf("��ϲ��ͨ���˵�����\n"); 
		printf("��ϲ���سɹ�\n");
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
	printf("��ѡ������<������20������>:");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	start = time(NULL);
	srand(time(NULL));
	for(i=0;i<check2;i++){
		addition1 = rand()%100+1;
		addition2 = rand()%100+1;
		printf("��%d��: %d + %d = \n",i+1,addition1,addition2);
		printf("��������ļ�����:") ;
		flag1 = scanf("%d",&result);
		flag2 = check(flag1,result);
		if(flag2 == addition1 + addition2){
			printf("\n�ش���ȷ�������\n");
			count ++;
		}else{
			printf("\n�ش���󣬱���ġ� ��ȷ���ǣ�%d\n",addition1+addition2);
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
	printf("���ο�����ʱ��%d��       ���β��Է���Ϊ��%.0f   �ȼ�Ϊ��%c\n",end-start,sum,grade);
}
void Sub(){
	int n,i,count=0,start,end;
	int subtraction1,subtraction2,result;
	char grade;
	float sum;
	printf("��ѡ������<������20������>:");
	check1 = scanf("%d",&n);
	check2 = check(check1,n);
	start = time(NULL);
	srand(time(NULL));
	for(i=0;i<check2;i++){
		subtraction1 = rand()%100+1;
		subtraction2 = rand()%100+1;
		if(subtraction1>subtraction2){
			printf("��%d��: %d - %d = \n",i+1,subtraction1,subtraction2);	
		}else{
			printf("��%d��: %d - %d = \n",i+1,subtraction2,subtraction1);
		}
		printf("��������ļ�����:") ;
		flag1 = scanf("%d",&result);
		flag2 = check(flag1,result);
		if(flag2 == abs(subtraction1 - subtraction2)){
			printf("\n�ش���ȷ\n");
			count ++;
		}else{
			printf("\n�ش���󣬱���ġ� ��ȷ���ǣ�%d\n",abs(subtraction1-subtraction2));
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
	printf("���ο�����ʱ��%d��       ���β��Է���Ϊ��%.0f    �ȼ�Ϊ��%c\n",end-start,sum,grade);	
}
void Func(int x){
	if(x == 0){
		printf("��ӭ�����һ�أ�\n");
		printf("���趨��Ŀ����<������10������>��"); 
	}else if(x == 1){
		printf("��ӭ����ڶ��أ�\n");
		printf("���趨��Ŀ����<������10������>��");
	}else if(x == 2){
		printf("��ӭ��������أ�\n");
		printf("���趨��Ŀ����<������10������>��");
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
				printf("��%d��:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1 = scanf("%d",&result);
				flag2 = check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("��ϲ�㣬�ش���ȷ��\n"); 
				}else{
					do{
						printf("�ش���������»ش�\n"); 
						flag1 = scanf("%d",&result);
						flag2 = check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("��ϲ�㣬�ش���ȷ��\n");
				}
			}
			printf("��ϲ��ͨ����һ�أ�\n\n");
			printf("�Ƿ������ս��Y<1>/N<2>:");
			scanf(" %s",count);	
			zhengque=xuanze('1','2',count);
		}
		if(m == 1){
			for(i=1;i<=check2;i++){
				multi1 = rand() % 11;
				multi2 = rand() % 90+10;
				printf("��%d��:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1 = scanf("%d",&result);
				flag2 = check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("��ϲ�㣬�ش���ȷ��\n\n"); 
				}else{
					do{
						printf("�ش���������»ش�\n"); 
						flag1 = scanf("%d",&result);
						flag2 = check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("��ϲ�㣬�ش���ȷ��\n\n");
				}
			}
			printf("��ϲ��ͨ���ڶ��أ�\n");
			printf("�Ƿ������ս��Y<1>/N<2>:");
			scanf(" %s",count);
			zhengque=xuanze('1','2',count);
		}
		if(m == 2){
			for(i=1;i<=check2;i++){
				multi1 = rand() % 90+10;
				multi2 = rand() % 90+10;
				printf("��%d��:",i);
				printf("%d * %d = ",multi1,multi2);
				flag1=scanf("%d",&result);
				flag2=check(flag1,result);
				if(flag2 == multi1 * multi2){
					printf("��ϲ�㣬�ش���ȷ��\n\n"); 
				}else{
					do{
						printf("�ش���������»ش�\n"); 
						flag1=scanf("%d",&result);
						flag2=check(flag1,result);
					}while(flag2 != multi1 * multi2);
					printf("��ϲ�㣬�ش���ȷ��\n\n");
				}
			}
			printf("��ϲ��ͨ�������أ�\n");
			printf("��ϲ���سɹ���\n\n");
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
	printf("С���ѣ���ļӷ��ɼ���¯����^-^\n��ĳɼ��ӵ͵��߷ֱ��ǣ�\n");
	for(int j=0;j<f1;j++){
		printf("%.0f\t",score1[j]);
	}
	printf("\n"); 
	printf("��ӷ�����߳ɼ��ǣ�%.0f\n��ӷ�����ͳɼ��ǣ�%.0f\n\n",score1[f1-1],score1[0]);
}
	if(f2!=0){
	printf("С���ѣ���ļ����ɼ���¯����^-^\n��ĳɼ��ӵ͵��߷ֱ��ǣ�\n");
	for(int j=0;j<f2;j++){
		printf("%.0f\t",score2[j]);
	}
	printf("\n"); 
	printf("���������߳ɼ��ǣ�%.0f\n���������ͳɼ��ǣ�%.0f",score2[f2-1],score2[0]);
}
}
void back(){
	char a[4],b[4];
	char s[1000];
	int i,j=0,t,count = 0,m,n,hao; 
	do
	{
		printf("\n\n\n\t***********^-^ ^-^С���ѻ�ӭ�����һ�������� ^-^ ^-^***********");
		printf("\n\n\n\n\t\t\t\t�������û���:\t");
		scanf("%s",a);
		printf("\n\n\t\t\t\t������ѧ�ţ�\t");
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
			printf("\n\n\n\t\t�û���ʽ�������������룺");
			Sleep(2000);
			system("cls");
		}
	}while(m>3||n>3);
	t=cha(a,b,2);
	if(t==1){
		FILE *fp;
		if((fp=fopen("mima.txt","r"))==NULL){
			printf("�����һظ����룡");
			exit(0);
		}
		printf("\n\n\t\t\t\t  �����֤�ɹ���"); 
		printf("\n\n\t\t\t\t���û�������Ϊ��");
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
		printf("\n\n\t\t\t\t�����֤ʧ��");
		printf("\n\n\t\t��������<1>\t\t\t����ע��<2>\n\n\t\t\t\t     ");
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
				printf("\n\t  ѡ�������ʽ�������������룺  ");
				scanf("%s",result);
				if(strlen(result)==1){
					count = 0;
				}
			}else{
				printf("\n\t  ѡ�������ʽ�������������룺  ");
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
				printf("ѡ�������ʽ�������������룺"); 
				count++;
				scanf("%s",result);
				if(strlen(result)==1){
					count=0;
				}
			}else{ 
				printf("ѡ�������ʽ�������������룺");
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
		case '1':  //�ӷ����
			add(); 
			f1++;
			display2();
			break;
		case '2':  //������� 
			Sub();
			display2();
			f2++;
			break;
		case '3':  //�˷���� 
			Multiplication();
			display2();
			break;
		case '4':  //������� 
			Division_main();
			display2();
			break;
		case '5':  //˵����� 
			shuoming();
			display2();
			break;
		case '6':  //������� 
			pingjia();
			display2();
			break;
		case '0':
			system("cls");
			display3();
			paixu(); 
			printf("\n�Ƿ�Ҫ��������:��<1>\t�˳�<2>\n");
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
			printf("�����ʽ��������ȷ���룺"); 
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
