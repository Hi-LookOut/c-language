#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <string.h>
#include <stdio.h>



//打印函数
void printMsg(char* flag, char* msg){
	printf("%s-----%s\n",flag,msg);
}



void msg(char* content){
	printf("指针调用函数msg为%s\n", content);
}

int msg2(int content){
	printf("指针调用函数msg,我们的口号是%d\n", content);
	return 0;
}

int msg3(void(*fun)(char*), char* str, int content){
	printf("高级用法");
	printf("%s\n", str);
	printf("下面是我调用的");
	fun("我被msg3调用了");
	return 0;
}
//void main(){
//	int i = 10;
//	int *p = &i;
//	int **j=NULL;
//
//	printf("i的值为：%d\n", i);
//	printf("i的地址为：%#x\n", &i);
//	printf("p存储的内容为：%#x\n", p);
//	printf("p的地址为：%#x\n", &p);
//	*p = 200;
//	printf("\n");
//	//二级指针的运用
//	if (j == NULL)
//	{
//		printf("j为空\n");
//		j = &p;
//		printf("j拿到p的地址：%#x\n", j);
//		printf("j拿到p的内容的：%#x\n", *j);
//	}
//	printf("\n");
//	//指针的运算
//	int arr[] = {123,345,789};
//	printf("arr的地址：%#x\n", arr);//地址
//	printf("arr的第一项值：%d\n", *arr);//123
//	printf("arr的第二项值：%d\n", *(arr+1));//345
//	printf("\n");
//	//指针函数调用,char*=string
//	void (*f)(char*) = msg;
//	f("我是指针大哥，听我调用");
//
//	int(*fu)(int) = msg2;
//	fu(123);
//
//	msg3(msg, "你好", 110);
//	printf("\n");
//	system("pause");//	getchar();
//
//}

//常量指针
void main(){

	//常量指针
	int i = 100;
	int j = 200;
	const int* p = &i;
	//不能修改其存储地址对应的内容，
	//(*p) = 10;  //报错
	//可以修改自己存储的地址
	printf("%d\n", *p);
	p = &j;
	printf("%d\n",*p);

	//指针常量
	int* const h = &i;
	//可以修改其存储地址对应的内容，
	(*h) = 10;
	//不可以修改自己存储的地址
        //h = &j;//报错
	printf("%d\n",*h);

	system("pause");
}

//动态分配
//堆分配
void heapFun(){
	int len = 0;
	int* p = NULL;
	printf("输入你要开辟的内存大小:");
	scanf("%d", &len);
	if (len <= 0)
	{
		printf("你在闹着玩的吧");
		return;
	}
	else
	{
		p = (int*)malloc(len * sizeof(int));//40M
		//p = (int*)calloc(len, sizeof(int));
		//使用内存,想数组.
		int i = 0;
		for (; i < len; i++)
		{
			int s = rand() % 100;
			p[i] = s;
			printf("%#x---%d\n", &p[i], p[i]);
		}
	}

	int addlen = 0;
	printf("你需要增加的内存大小:");
	scanf("%d", &addlen);
	//重新分配,且连续.(但是增加内存已被占用,这重新找一块堆中满足len+addlen大小的内存块,并将所有值赋值到新内存块,并释放以前的内存块.)
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

	//分配内存好习惯,不仅要释放内存,还应该将其赋值为NULL
	if (p != NULL)
	{
		//手动释放
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
		printf("对不起,没有你需要的大小的内存块.");
	}
	printf("\n");
}




//栈分配
void stackFun(){
	int a[1024 * 1024]; //报错内存溢出
	a[0] = 110;
}

//内存分配main
//void main(){
//
//	//stackFun();
//    heapFun();
//	getchar();
//}



//使用字符数组存储字符串

//void main(){
//	//'\0'为结束符
//	//char str[] = {'c','h','i','n','a','\0'};
//	
//	//char str[6] = { 'c', 'h', 'i', 'n', 'a'};
//
//
//	//必须大于等于6
//	//char str[6] = "china";
//
//	//有点方便,缺点不可扩充和修改.其为const
//	char name[20] = "china";
//	char *str = " that is good";
//
//	printf("%s\n",str);
//	//文档：http://www.kuqin.com/clib/string/strcat.html
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
//		printf("i的下标是:%d\n",p-name);
//	}
//	else
//	{
//		printf("没找到\n");
//	}
//	system("pause");
//}



//结构体

struct girl
{
	char *name;
};

//匿名结构体
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
	//struct xm; 不能这么用
}my, my2;

struct arr
{
	int index;
	double flag;
};
//void main(){
//	//使用预声明
//	my.name = "何大侠";
//	printf("%s\n", my.name);
//	my2.name = "何大侠2222";
//	printf("%s\n", my2.name);
//	//定义
//	struct Man mi = {18,200.0,"小明"};
//	printf("%#x----%d\n",&mi,sizeof(mi));
//	printf("%d\n", mi.age);
//	//按顺序存储在连续的内存中。
//	printf("地址：%#x\n", &mi);
//	printf("地址：%#x\n", &mi.weight);
//	//结构体指针
//	struct Man *m = &my;
//	printf("结构体指针取值：%s\n", (*m).name);
//	printf("结构体指针取值：%s\n", m->name);

//	//匿名结构体
//	xm.name = "明哥";
//	printf("匿名：%s\n", xm.name);
//     
//	//Man里的wife
//	my = { 18, 200.0, "小明", { "性感美女" } };
//	printf("%s\n", my.wife.name);
//
//	p->wife.name = "小红";
//	printf("%s\n", p->wife.name);
//
//
//	//结构体数组
//	struct arr obj[] = { { 11, 11.0 }, { 12, 32.0 }, {22,434.0} }; 
//	int i = 0;
//	printf("变量名：%#x",obj);
//    //方法一：
//	struct arr *a = obj;
//	//加3表示obj存储的长度。
//	for (; a < (obj +3); a++)
//	{  
//		printf("指针地址：%#x---结构数组地址：%#x----%#x\n", &a, &a->index, &a->flag);
//		printf("结构数组---%d---%lf\n", a->index, a->flag);
//	}
//
//	//方法二：
//	//obj的长度我们可以这么取得：
//	/*int len = sizeof(obj) / sizeof(struct arr);
//	for (; i < len; i++){
//		printf("结构数组---%d---%lf\n", obj[i].index, obj[i].flag);
//	}*/
//
//	//不能这么用
//	//my.xm.name = "aaa";
//	system("pause");
//}



//动态分配和结构体
//void main(){
//		//动态分配
//		struct Man *p = (struct Man*)malloc(sizeof(struct Man)*10);
//		p->age = 24;
//		p->name = "大明";
//		p->weight = 130.0;
//
//		p++;
//
//		(*p).age = 18;
//		(*p).weight = 118.0;
//		(*p).name = "小明";
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

//结构体字符串
struct str{
	char* name;
	char title[20];
}ad, *p;

//void main(){
//   
//	ad.name = "我的广告";
//	//除声明时，否则字符数组不能这么赋值。
//	//ad.title = "see you tomorrow";
//	strcpy(ad.title,"see you love");
//
//	p = &ad;
//	printf("name:%s---title:%s\n",p->name,p->title);
//	system("pause");
//}



//结构体的指针函数
void open(int num){

	printf("你成功购买了id为%d的商品！！！\n", num);
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



//别名typedef
//typedef int i;
//typedef struct Man people;
//typedef struct Man* who;
// typedef int a[10];//int[10]
// typedef void (*func)();//定义指针函数的别名fun
// typedef int* func1;//定义int类型的指针别名func1
// typedef int** PFun(int, char*);//定义int类型的二级指针

void fun1(){
	printf("fun1......\n");
}

//void main(){
//
//	i j = 10;
//      printf("%d\n",j);

//      people p = {12,123.0,"大狗"};
//	who h= &p;
//	printf("%#x----%d----%lf----%s\n", h, h->age, h->weight, h->name);

// 	a b = {1,2,3,4,5,6,7,8,9,10};
// 	int k = 0;
// 	for (; k < (sizeof(b) / sizeof(int)); k++)
// 	{ 
// 	    printf("%d\n", k);
// 	};

// 	func f = fun1;
// 	f();

// 	func1 omg = &j;
//      printf("%d\n", *omg);

//	system("pause");
//}



//联合体

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



//枚举

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



//读取文件
//void main(){
//    
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
//	FILE *dir = fopen(path,"r");
//	if (dir==NULL)
//	{
//		printf("打开文件失败");
//		return;
//	}
//	char buff[50];
//	//fgets读取文件字符串
//	while (fgets(buff,50,dir))
//	{
//		printf("%s\n",buff);
//	}
//	fclose(dir);
//	system("pause");
//}



//写入文件
//void main(){
//
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\temp.txt";
//	FILE *dir = fopen(path, "w");
//	if (dir == NULL)
//	{
//		printf("打开文件失败");
//		return;
//	}
//
//	//\n换行
//	char *text = "你不是空的吗？？\n为啥又内容····";
//	//会覆盖原来内容。
//	fputs(text,dir);
//	fclose(dir);
//	printf("写入成功\n");
//	system("pause");
//}

//复制二进制文件

//void main(){
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture.png";
//	char *copy_path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\copy_picture.png";
//	FILE *picture = fopen(path,"rb");
//	FILE *copy_picture = fopen(copy_path,"wb");
//
//
//	if (picture == NULL&&copy_picture==NULL)
//	{
//		printf("打开文件失败");
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
//	printf("复制图片成功\n");
//	system("pause");
//}



//获取文件大小
//void main(){
//
//	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
//	FILE *dir = fopen(path,"r");
//
//	//fseek从新定位文件指针,0为偏移量，这里是从开始到末尾。
//	fseek(dir,0,SEEK_END);
//
//	//ftell,获得num2-num1的大小，即文件大小（fseek（，num1，num2）)
//	long size = ftell(dir);
//	printf("文件大小为%d\n",size);
//	system("pause");
//
//}


//验证文件打开是否成功
bool isOpen(FILE *path){
	if (path != NULL)
	{
		return true;
	}
	return false;
}






//byte文件的加密

void crypt(char normal_path[], char *crypt_path){
	FILE *normal_p = fopen(normal_path, "r");
	FILE *crypt_p = fopen(crypt_path, "w");


	if (normal_p == NULL&&crypt_p == NULL)
	{
		printf("打开文件失败");
		return;
	}

	int ch = 0;
	//EOF结尾标识符
	while ((ch = fgetc(normal_p)) != EOF)
	{
		//加密或解密^8
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
c语言执行流程
预编译---完成文本的替换
编译---形成.obj文件
连接---将目标代码与c函数库连接合并。
最后执行。
*/



//void main(){
//
//    #include "my.txt";
//	system("pause");
//}



