#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <string.h>
#include <stdio.h>



//��ӡ����
void printMsg(char* flag, char* msg){
	printf("flag%s\n", msg);
}



void msg(char* content){
	printf("ָ����ú���msgΪ%s\n", content);
}

int msg2(int content){
	printf("ָ����ú���msg,���ǵĿں���%d\n", content);
	return 0;
}

int msg3(void(*fun)(char*), char* str, int content){
	printf("�߼��÷�");
	printf("%s\n", str);
	printf("�������ҵ��õ�");
	fun("�ұ�msg3������");
	return 0;
}
//void main(){
//	int i = 10;
//	int *p = &i;
//	int **j=NULL;
//
//	printf("i��ֵΪ��%d\n", i);
//	printf("i�ĵ�ַΪ��%#x\n", &i);
//	printf("p�洢������Ϊ��%#x\n", p);
//	printf("p�ĵ�ַΪ��%#x\n", &p);
//	*p = 200;
//	printf("\n");
//	//����ָ�������
//	if (j == NULL)
//	{
//		printf("jΪ��\n");
//		j = &p;
//		printf("j�õ�p�ĵ�ַ��%#x\n", j);
//		printf("j�õ�p�����ݵģ�%#x\n", *j);
//	}
//	printf("\n");
//	//ָ�������
//	int arr[] = {123,345,789};
//	printf("arr�ĵ�ַ��%#x\n", arr);//��ַ
//	printf("arr�ĵ�һ��ֵ��%d\n", *arr);//123
//	printf("arr�ĵڶ���ֵ��%d\n", *(arr+1));//345
//	printf("\n");
//	//ָ�뺯������,char*=string
//	void (*f)(char*) = msg;
//	f("����ָ���磬���ҵ���");
//
//	int(*fu)(int) = msg2;
//	fu(123);
//
//	msg3(msg, "���", 110);
//	printf("\n");
//	system("pause");//	getchar();
//
//}



//��̬����
//�ѷ���
void heapFun(){
	int len = 0;
	int* p = NULL;
	printf("������Ҫ���ٵ��ڴ��С:");
	scanf("%d", &len);
	if (len <= 0)
	{
		printf("����������İ�");
		return;
	}
	else
	{
		p = (int*)malloc(len * sizeof(int));//40M
		//p = (int*)calloc(len, sizeof(int));
		//ʹ���ڴ�,������.
		int i = 0;
		for (; i < len; i++)
		{
			int s = rand() % 100;
			p[i] = s;
			printf("%#x---%d\n", &p[i], p[i]);
		}
	}

	int addlen = 0;
	printf("����Ҫ���ӵ��ڴ��С:");
	scanf("%d", &addlen);
	//���·���,������.(���������ڴ��ѱ�ռ��,��������һ���������len+addlen��С���ڴ��,��������ֵ��ֵ�����ڴ��,���ͷ���ǰ���ڴ��.)
	int * p2 = (int*)realloc(p, sizeof(int)*(len + addlen));

	int i = len;
	for (; i < (len + addlen); i++)
	{
		int s = rand() % 100;
		p2[i] = s;
	}

	i = 0;
	for (; i < (len + addlen); i++)
	{
		printf("%#x---%d\n", &p2[i], p2[i]);
	}

	//�����ڴ��ϰ��,����Ҫ�ͷ��ڴ�,��Ӧ�ý��丳ֵΪNULL
	if (p != NULL)
	{
		//�ֶ��ͷ�
		free(p);
		p = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	else
	{
		printf("�Բ���,û������Ҫ�Ĵ�С���ڴ��.");
	}
	printf("\n");
}




//ջ����
void stackFun(){
	int a[1024 * 1024]; //�����ڴ����
	a[0] = 110;
}

//�ڴ����main
//void main(){
//
//	//stackFun();
//    heapFun();
//	getchar();
//}



//ʹ���ַ�����洢�ַ���

//void main(){
//	//'\0'Ϊ������
//	//char str[] = {'c','h','i','n','a','\0'};
//	
//	//char str[6] = { 'c', 'h', 'i', 'n', 'a'};
//
//
//	//������ڵ���6
//	//char str[6] = "china";
//
//	//�е㷽��,ȱ�㲻��������޸�.��Ϊconst
//	char name[20] = "china";
//	char *str = " that is good";
//
//	printf("%s\n",str);
//	//�ĵ���http://www.kuqin.com/clib/string/strcat.html
//	
//	//strcat
//	strcat(name,str);
//	printf("%s\n", name);
//
//	//strcpy
//	strcpy(name,str);
//	printf("%s\n",name);
//
//	//strchr
//	char *p=strchr(name,'i');
//	if (p)
//	{
//		printf("i���±���:%d\n",p-name);
//	}
//	else
//	{
//		printf("û�ҵ�\n");
//	}
//	system("pause");
//}



//�ṹ��

struct girl
{
	char *name;
};

//�����ṹ��
struct
{
	char *name;
}xm;
struct Man
{
	int age;
	double weight;
	char* name;
	struct girl wife;
	//struct xm; ������ô��
}my, my2;

struct arr
{
	int index;
	double flag;
};
//void main(){
//	//ʹ��Ԥ����
//	my.name = "�δ���";
//	printf("%s\n", my.name);
//	my2.name = "�δ���2222";
//	printf("%s\n", my2.name);
//	//����
//	struct Man mi = {18,200.0,"С��"};
//	printf("%#x----%d\n",&mi,sizeof(mi));
//	printf("%d\n", mi.age);
//	//��˳��洢���������ڴ��С�
//	printf("��ַ��%#x\n", &mi);
//	printf("��ַ��%#x\n", &mi.weight);
//	//�ṹ��ָ��
//	struct Man *m = &my;
//	printf("�ṹ��ָ��ȡֵ��%s\n", (*m).name);
//	printf("�ṹ��ָ��ȡֵ��%s\n", m->name);

//	//�����ṹ��
//	xm.name = "����";
//	printf("������%s\n", xm.name);
//     
//	//Man���wife
//	my = { 18, 200.0, "С��", { "�Ը���Ů" } };
//	printf("%s\n", my.wife.name);
//
//	p->wife.name = "С��";
//	printf("%s\n", p->wife.name);
//
//
//	//�ṹ������
//	struct arr obj[] = { { 11, 11.0 }, { 12, 32.0 }, {22,434.0} }; 
//	int i = 0;
//	printf("��������%#x",obj);
//    //����һ��
//	struct arr *a = obj;
//	//��3��ʾobj�洢�ĳ��ȡ�
//	for (; a < (obj +3); a++)
//	{  
//		printf("ָ���ַ��%#x---�ṹ�����ַ��%#x----%#x\n", &a, &a->index, &a->flag);
//		printf("�ṹ����---%d---%lf\n", a->index, a->flag);
//	}
//
//	//��������
//	//obj�ĳ������ǿ�����ôȡ�ã�
//	/*int len = sizeof(obj) / sizeof(struct arr);
//	for (; i < len; i++){
//		printf("�ṹ����---%d---%lf\n", obj[i].index, obj[i].flag);
//	}*/
//
//	//������ô��
//	//my.xm.name = "aaa";
//	system("pause");
//}



//��̬����ͽṹ��
//void main(){
//		//��̬����
//		struct Man *p = (struct Man*)malloc(sizeof(struct Man)*10);
//		p->age = 24;
//		p->name = "����";
//		p->weight = 130.0;
//
//		p++;
//
//		(*p).age = 18;
//		(*p).weight = 118.0;
//		(*p).name = "С��";
//
//		
//		p--;
//
//		struct Man *h = p;
//		for (; h < p+2; h++)
//		{
//			printf("%#x----%d----%lf----%s\n", h, h->age, h->weight, h->name);
//		}
//		if (p!=NULL)
//		{
//			free(p);
//			p = NULL;
//			h = NULL;
//		}
//		system("pause");
//}

//�ṹ���ַ���
struct str{
	char* name;
	char title[20];
}ad, *p;

//void main(){
//   
//	ad.name = "�ҵĹ��";
//	//������ʱ�������ַ����鲻����ô��ֵ��
//	//ad.title = "see you tomorrow";
//	strcpy(ad.title,"see you love");
//
//	p = &ad;
//	printf("name:%s---title:%s\n",p->name,p->title);
//	system("pause");
//}



//�ṹ���ָ�뺯��
void open(int num){

	printf("��ɹ�������idΪ%d����Ʒ������\n", num);
}

struct store
{
	int id;
	void(*shop)(int num);
} hand;


//void main(){
//
//	hand.id = 110;
//	hand.shop = open;
//	hand.shop(hand.id);
//	system("pause");
//}

//����typedef
//typedef int i;
//
//typedef struct Man people;
//
//typedef struct Man* who;
//
//void main(){
//
//	int i = 10;
//    people p = {12,123.0,"��"};
//	who h= &p;
//	printf("%#x----%d----%lf----%s\n", h, h->age, h->weight, h->name);
//	system("pause");
//}



//������

union MyUnion
{
	int x;
	int x2;
	int x3;
}un;


//void main(){
//	un.x = 1111;
//
//	un.x2 = 2222;
//
//	un.x3 = 3333;
//	printf("%d,\n%d,\n%d\n",un.x, un.x2,un.x3);
//	
//	system("pause");
//}



//ö��

enum day{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

//void main(){
//	enum day d = Sunday;
//	printf("%d\n",d);
//
//	system("pause");
//}



//��ȡ�ļ�
//void main(){
//    
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
//	FILE *dir = fopen(path,"r");
//	if (dir==NULL)
//	{
//		printf("���ļ�ʧ��");
//		return;
//	}
//	char buff[50];
//	//fgets��ȡ�ļ��ַ���
//	while (fgets(buff,50,dir))
//	{
//		printf("%s\n",buff);
//	}
//	fclose(dir);
//	system("pause");
//}



//д���ļ�
//void main(){
//
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\temp.txt";
//	FILE *dir = fopen(path, "w");
//	if (dir == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return;
//	}
//
//	//\n����
//	char *text = "�㲻�ǿյ��𣿣�\nΪɶ�����ݡ�������";
//	//�Ḳ��ԭ�����ݡ�
//	fputs(text,dir);
//	fclose(dir);
//	printf("д��ɹ�\n");
//	system("pause");
//}

//���ƶ������ļ�

//void main(){
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture.png";
//	char *copy_path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\copy_picture.png";
//	FILE *picture = fopen(path,"rb");
//	FILE *copy_picture = fopen(copy_path,"wb");
//
//
//	if (picture == NULL&&copy_picture==NULL)
//	{
//		printf("���ļ�ʧ��");
//		return;
//	}
//
//	int buff[50];
//	int len;
//	while ((len=fread(buff,sizeof(int),50,picture))!=0)
//	{
//		fwrite(buff,sizeof(int),len,copy_picture);
//	}
//
//	fclose(picture);
//	fclose(copy_picture);
//	printf("����ͼƬ�ɹ�\n");
//	system("pause");
//}



//��ȡ�ļ���С
//void main(){
//
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
//	FILE *dir = fopen(path,"r");
//
//	//fseek���¶�λ�ļ�ָ��,0Ϊƫ�����������Ǵӿ�ʼ��ĩβ��
//	fseek(dir,0,SEEK_END);
//
//	//ftell,���num2-num1�Ĵ�С�����ļ���С��fseek����num1��num2��)
//	long size = ftell(dir);
//	printf("�ļ���СΪ%d\n",size);
//	system("pause");
//
//}


//��֤�ļ����Ƿ�ɹ�
bool isOpen(FILE *path){
	if (path != NULL)
	{
		return true;
	}
	return false;
}






//byte�ļ��ļ���

void crypt(char normal_path[], char *crypt_path){
	FILE *normal_p = fopen(normal_path, "r");
	FILE *crypt_p = fopen(crypt_path, "w");


	if (normal_p == NULL&&crypt_p == NULL)
	{
		printf("���ļ�ʧ��");
		return;
	}

	int ch = 0;
	//EOF��β��ʶ��
	while ((ch = fgetc(normal_p)) != EOF)
	{
		//���ܻ����^8
		fputc(ch ^ 8, crypt_p);
	}

	fclose(normal_p);
	fclose(crypt_p);
}


//void main(){
//	char *normal_path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
//	char *crypt_path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\crypt.txt";
//	char *decrypt_path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\decrypt.txt";
//	crypt(normal_path,crypt_path);
//	crypt(crypt_path,decrypt_path);
//	system("pause");
//}

/*
c����ִ������
Ԥ����---����ı����滻
����---�γ�.obj�ļ�
����---��Ŀ�������c���������Ӻϲ���
���ִ�С�
*/



//void main(){
//
//    #include "my.txt";
//	system("pause");
//}

