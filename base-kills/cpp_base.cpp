#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


//自定义命名空间------先当与Java的包
namespace NSP_A{
	int a = 10;

	struct MyStruct
	{
		int xx = 250;
	};
}

namespace NSP_B{
	
	using namespace NSP_A;

	namespace NSP_C{
		int c = 300;
		int d = 400;
	};
	int b = 100;

	struct stu
	{
		int yy = 3600;
	};

	struct MyStruct
	{
		int xx = 2500;
	};
}

//使用自定义命名空间
//void main(){
//
//	using namespace NSP_B;
//	//::域运算符
//
//	//NSP_A
//	cout << "自定义空间NSP_A---a的值:" << NSP_A::a << endl;
//	struct NSP_A::MyStruct ms;
//	cout << "自定义空间NSP_A---xx的值:" << ms.xx<< endl;
//
//	//NSP_B
//	cout << "自定义空间NSP_B---b的值:" << b << endl;
//	cout << "自定义空间NSP_B用空间NSP_A---a的值:" << a << endl;
//	cout << "自定义空间NSP_B用空间NSP_C---c的值:" << NSP_B::NSP_C::c << endl;
//	cout << "自定义空间NSP_B用空间NSP_C---d的值:" << NSP_C::d << endl;
//	struct stu st;
//	cout << "自定义空间NSP_B用空间NSP_C---yy的值:" << st.yy << endl;
//
//
//	//两空间重复
//	using NSP_A::MyStruct;
//	MyStruct ms1;
//    //因为前面main使用的是NSP_B的空间，所以不用using NSP_B::MyStruct;
//	MyStruct ms2;
//	//或者
//	NSP_A::MyStruct ms3;
//	NSP_B::MyStruct ms4;
//
//	cout << "自定义空间重名结构体:" << ms1.xx<< endl;
//	cout << "自定义空间重名结构体:" << ms2.xx << endl;
//	cout << "自定义空间重名结构体:" << ms3.xx << endl;
//	cout << "自定义空间重名结构体:" << ms4.xx << endl;
//	system("pause");
//}


//宏定义
#define PI 3.14;

struct ms{
private:
	int i;
	void pp(){
		cout << "i=" << i << ",j=" << j << endl;
		cout << "c++的结构体与c的结构体有所不同哦" << endl;
	};
public:
	int j;
	void p(int k){
		i = k;
		pp();
	};
}m;


//c++的结构体与c的结构体有所不同
//void main(){
//	cout << "欢迎回到C++" << endl;
//
//	m.j = 100;
//	m.p(250);
//	system("pause");
//}


void replay(int * a1,int &b1){
	*a1 = 100;
	b1 = 200;
}

struct space
{
	int a;
};

//引用动态分配空间
void guideSpace(space* &p){
	p = (space*)malloc(sizeof(space));
	p->a = 100;
}
void openSpace(space** p){
	*p = (space*)malloc(sizeof(space));
	(*p)->a = 10;
}

//指针与引用
//void main(){
//	int a = 10;
//	int b = 20;
//	replay(&a,b);
//	//a，b被改变了
//	cout << "指针操作的a=" << a << ",引用操作的b=" << b << endl;
//
//	space* sp=NULL;
//	//二级指针动态分配
//	openSpace(&sp);
//	cout << (*sp).a << endl;
//	//引用的动态分配
//	guideSpace(sp);
//	cout << (*sp).a << endl;
//	system("pause");
//}



void isNull(int &b){
  
	cout << "不是NULL" << endl;
}

//常引用

//引用与指针的区别：
//1.不能为NULL；
//void main(){
//
//	int d = 10;
//	const int i = 100;
//	const int &k = i;
//    int* p = (int *)&k;
//	*p = 20;
//	//由于k存放在栈中所以可以修改
//	cout << k << endl;
//	//由于i存放符号表中
//	cout << i<< endl;
//
//	cout << sizeof(i) << endl;
//
//	//int &c = NULL;报错，引用不能为NULL
//
//	system("pause");
//}



void  fpx(int num,...){
	int result = 0;
	va_list vl;     //va_list指针，用于va_start取可变参数，为char*
	_crt_va_start(vl, num);       //取得可变参数列表中的第一个值
	printf("num:%d, vl:%d\n", num, *vl);
	while (*vl>0)
	{
		result = _crt_va_arg(vl, int);//这里把vl往后跳过4个字节（sizeof(int)大小）指向下一个参数，返回的是当前参数（而非下
		//一个参数）
		if (*vl<=0)
		{
			break;
		}
		printf("in for  result:%d,  *vl:%d\n", result, *vl);//这里打印下，可以看出，vl总是指向result后面的那个参数,v1>
	}

	_crt_va_end(vl);//结束标志  
}



//可变参数
//void main(){
//
//	fpx(10, 1, 2, 3, 4, 5);
//
//	system("pause");
//}



//C++ 普通用法 
//header.h---类的申明，header.cpp类的实现；

//#include "header.h";

//void main(){
//	header h;
//	h.setData(666);
//	h.setTitle("牛逼啊");
//	cout << h.getData() << endl;
//	cout << h.getTitle() << endl;
//	system("pause");
//}


class Teacher{
private:
	char* name;
	int age;
public:
	//无参构造函数
	Teacher(){
		cout << "无参构造函数" << endl;
	}
	//有参构造函数
	Teacher(char* name,int age){

		
		//this->name = name;
		//strcpy(this->name, name);
		this->name = name;
		this->age = age;
		cout << "有参构造函数" << endl;
	}

	//析构函数
	~Teacher(){
		cout << "析构函数"  << endl;
		//free(this->name);
	}

};

//为了触发析构函数
void del(){
	Teacher t3("Hi",22);
}


//构造函数，析构函数，拷贝构造函数。
//1.和Java一样如果重写了有参构造函数，如果不重写无参构造函数，则没有无参构造函数

//void main(){
//
//	//调用无参构造函数
//	Teacher t1;
//	//调用有参构造函数
//	Teacher t2("美女",18);
//	//另一种用法
//	Teacher t4=Teacher("goodBoy", 22);
//	//调用析构函数
//	del();
//	system("pause");
//}


class student{
private:
	char* name;
	int age;
public:

	//构造函数
	student(char* name,int age){
		cout << "调用-----构造函数" << endl;
		this->age = age;
		this->name = name;
	}
	//浅拷贝构造函数---指针
	student(student *p){
		cout << "调用-----指针浅拷贝" << endl;
		this->age = p->age;
		this->name = p->name;
	}

	//系统默认浅拷贝构造函数
	student(const student &p){
		cout << "调用-----系统默认浅拷贝构造函数" << endl;
		this->age = p.age;
		this->name = p.name;
	}

	void myPrint(){
		cout << "Name:" <<this->name<< endl;
		cout << "Age:" << this->age << endl;
	}
};

void copy(student t){
}

student back(){
	student s("back", 1000);
	return s;
}
//拷贝函数---浅拷贝（值拷贝）

//void main(){
//
//	//拷贝构造函数；
//	student s1("我是指针浅拷贝", 25);
//
//	//值拷贝
//	student s2 = &s1;//拷贝参数是指针，用&s1
//
//	//系统默认拷贝构造函数
//	student s3 = s2;
//    //作为参数是会被调用系统默认拷贝构造函数
//	copy(s3);
//	//作为返回值也会调用系统默认拷贝构造函数
//	back();
//
//	system("pause");
//}


class animal{
private:
	int* weight;
	

public:
	animal(int* weight){
		this->weight = weight;
	}
  
	animal(const animal &obj){
	   //动态分配
		this->weight = (int *)malloc(sizeof(int));
	
	}

	void myPrint(){
		cout << "-------------------------" << endl;
		cout << "age指针自己的地址：" << &(this->weight) << endl;
		cout << "age指针指向的地址：" << this->weight << endl;
		cout << "age指针指向的地址的值：" << *(this->weight) << endl;
	}
};

// 由指针引起的浅拷贝的不安全性，破坏类的封装性
//void main(){
//
//	//不安全的案例
//	int i = 250;
//	int*p = &i;
//	cout << "p指针自己的地址：" << &p << endl;
//	cout << "p指针指向的地址：" << p << endl;
//	animal pig(p);
//	pig.myPrint();
//	i = 3600;
//	pig.myPrint();
//
//	system("pause");
//}


class car{
private:
	char* name;

public:
	car(char* name){
		this->name = (char *)malloc(sizeof(char)*strlen(name) + 1);
		strcpy(this->name, name);
	}

	car(const car &obj){
		//动态分配，并赋值
		this->name = (char *)malloc(sizeof(char)*strlen(obj.name)+1);
		strcpy(this->name,obj.name);
	}

	~car(){
		cout << "--------析构函数----------" << endl;
		free(this->name);
	}

	void myPrint(){
		cout << "-------------------------" << endl;
		cout << "car.name指针自己的地址：" << &(this->name) << endl;
		cout << "car.name指针指向的地址：" << this->name << endl;
		cout << "car.name指针指向的地址的值：" << *(this->name) << endl;
	}
};

void  gc_car(){
	car c1("法拉利");
	c1.myPrint();
	car c2 = c1;
	c2.myPrint();
}

//深度拷贝

//使用深拷贝步骤：
//1.重写系统默认拷贝方法car(const car &obj)构造函数,
//2.与给成员指针赋值的地方，用动态分配+strcpy赋值。
//void main(){
//
//	gc_car();
//	system("pause");
//}


class money{

private:
	int num;

public:
	money(int d){
		cout << "money----构造函数"<< endl;
		this->num = d;
	}

	~money(){
		cout << "money----析构函数" << endl;
	}
	int getMoney(){
		return this->num;
	}
};


class wallet{
private:
	char* master;
	money m;
public:
	wallet(char* name, int d) :m(d){
		cout << "wallet----构造函数" << endl;
		this->master = name;
	}

	~wallet(){
		cout << "wallet----析构函数" << endl;
	}
	void myPrint(){
		cout << "主人：" << master << "有" << m.getMoney() << "万元" << endl;
	}

};



void order(){
	wallet w("baby",10000);
	w.myPrint();
}

//类中的属性对象的初始化
//构造函数调用顺序
//1.先调用属性对象的构造函数
//2.再调用类自己的构造函数
//析构函数顺序
//3.类自己先调用自己析构函数
//4.最后属性对象析构

//void main(){
//
//	order();
//	system("pause");
//}


class baby{
private:
	char* name;
  
public:
	baby(char* name){
		cout << "构造函数被调用" << endl;
		this->name = name;
	}

	~baby(){
		cout << "析构函数被调用" << endl;
	}

	void setName(char* name){
		this->name = name;
	}
	void myPrint(){
		cout << this->name << endl;
	}
};


//C++ 通过new(delete)动态内存分配
/*
  new(delete)与malloc(free)的区别
  malloc(free)不会调用构造和析构函数。
*/
//void main(){
//	
//	baby* b = new baby("小明");
//	b->myPrint();
//	delete(b);
//
//	//与c的malloc、free
//	baby* b2 = (baby*)malloc(sizeof(baby));
//	b2->setName("小红");
//	b2->myPrint();
//	free(b2);
//
//
//	//其他用法
//	int* arr = new int[10];
//	arr[0] = 100;
//	//记得加【】
//	delete[] arr;
//
//	system("pause");
//}


class classmate{
public:
	static int num;
	int gold = 0;
	classmate(int gold){
		this->gold = gold;
	}

	void add(){
		gold++;
		num++;
		cout << "gold:" << this->gold << endl;
		myPrint();
	}
	static void myPrint(){
		cout << "num:" << num << endl;
	}
};

//
int classmate::num = 10;

//static静态变量
/*
   因为static成员函数没有this指针，所以静态成员函数不可以访问非静态成员。
   非静态成员函数可以访问静态成员。
   静态数据成员与类的大小无关，因为静态成员只是作用在类的范围而已
*/
//void main(){
//	classmate::num = 100;
//
//	//静态方法
//	classmate::myPrint();
//
//	//非静态方法访问静态变量，和方法
//	classmate cm(110);
//	cm.add();
//	system("pause");
//}

class pine{
private:
	int p = 10;
public:
	void setThis(){
		//pine* pi;
		//this =pi;//错误 不能修改，其为 pine* const this
		//其指向地址内容可以修改
		this->p = 1000;
		myPrint();
	}


	//const 修饰this---->const pine* const this
	//其内容与其指向的地址的内容都不能修改，只读
	void setThis2()const{
		//pine* pi;
		//this = pi;//错误
		//this->p = 100000;//错误
		cout << "p:" << p << endl;
	}
	void myPrint(){
		cout << "p:" << p << endl;
	}
};

//this
//void main(){
//	pine p1;
//	p1.setThis();
//	p1.setThis2();
//
//	const pine p2;
//	//p2.setThis();//错误，const变量只能调用const方法
//	p2.setThis2();
//	system("pause");
//}


class Box
{
double width=1.0;

private:
	int height=2;
public:
	double length=3;
	friend void printAll(Box box);
	void setWidth(double wid);

};

void printAll(Box box){
	cout << "width:" << box.width << endl;
	cout << "height:" << box.height << endl;
	cout << "length:" << box.length << endl;
}
//友元函数
//可以访问所有成员变量和方法。但是其自己不是成员函数。
//void main(){
//	Box box;
//	printAll(box);
//	system("pause");
//}


class A{
	friend class B;
private:
	int a = 10;
public:

	void myPrint(){
		cout << "A:" << a << endl;
	}
};

class B{
private:
	int b = 20;
public:
	 A f;
	void myPrint(){
		cout << "B:" << b << endl;
	}
};
//友元类
//访问所有成员
//void main(){
//
//	B b1;
//	b1.f.myPrint();
//	b1.myPrint();
//	system("pause");
//}


class point{

public:

	point(int x,int y){
		this->x = x;
		this->y = y;
	}

	int x;
	int y;
	void myPrint(){
		cout << "x:" << x << ",y:" << y << endl;
	}
	point operator-(point &p){
		point p3(this->x - p.x, this->y - p.y);
		return p3;
	}

};


point operator+(point &p1,point &p2){
	point p3(p1.x+p2.x,p1.y+p2.y);
	return p3;
}

ostream & operator<<(ostream &out, point &obj)
{
     out << obj.x << " " << obj.y;
     return out;
}

//运算符重载operator
//void main(){
//	point p1(10,20);
//    point p2(20,10);
//	//加重载
//	point p3 = p2 + p1;
//	p3.myPrint();
//	//减重载
//	point p4 = p3 - p2;
//	p4.myPrint();
//
//
//	cout << p2 << endl;
//	system("pause");
//}



class human{
	int c;
public:
	human(int c){
		cout << "父类构造函数" << endl;
		this->c = c;
	}
	~human(){
		cout << "父类析构函数" << endl;
	}
	 void say(){
		cout << "我是父类，hello!!!" << endl;
	}
};

class sunman:public human{
public:
    //由于父类没有无参构造函数
	sunman(int d):human(d){
		cout << "子类构造函数" << endl;
	}

	~sunman(){
		cout << "子类析构函数" << endl;
	}
	 void say(){
	    
		cout << "我是子类，hell0" << endl;
	}
};


void fun5(){

	sunman m2(2);
}
//继承
/*
   1.只继承public/protected
   2.父类没有无参构造函数时，子类必须重写构造函数。
   3.父类构造函数先调用，然后子类才调用
   4.子类析构先调用，然后父类才调用
   5.如果父类的继承权限public/protected/private的不同，导致子类访问其类型不同
*/
//void main(){  
//	sunman m(1);
//	m.say();
//	cout << "---------实验父类与子类创建与销毁顺序-------" << endl;
//	fun5();
//	cout << "----------------------------------" << endl;
//	//方法覆盖
//	sunman m3(3);
//	m3.say();
//	m3.human::say();
//
//	human hu = m3;
//	hu.say();
//	system("pause");
//}

class dad{
private:
	int dad_private = 10;

	void getAccessPrivate(){
		cout << "父类private方法被访问" << endl;
	}
protected:
	int dad_protected = 100;

	void getAccessProtected(){
		cout << "父类protected方法被访问" << endl;
	}
public:
	int dad_public = 1000;

	//子类访问父类public方法
	void getAccessPublic(){
		cout << "父类public方法被访问" << endl;
	}
};

class son1:public dad{
private:
	void getSonPrivate(){
		//访问父类的public
		cout << "------子类内private方法访问父类public属性------" << endl;
		cout << "dad_public:"<<this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内private方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内private方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
protected:
	void getSonProtected(){
		//访问父类的public
		cout << "------子类内protected方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内protected方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内protected方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
public:
	void getSonPublic(){
		
		cout << "-----------------------public继承父类-------------------------" << endl;
		

		//访问父类的public
		cout << "------子类内public方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内public方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内public方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
		cout << "" << endl;
		getSonProtected();
		cout << "" << endl;
    	getSonPrivate();
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
	
	}
};

class son2 :protected dad{
private:
	void getSonPrivate(){
		//访问父类的public
		cout << "------子类内private方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内private方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内private方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
protected:
	void getSonProtected(){
		//访问父类的public
		cout << "------子类内protected方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内protected方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内protected方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
public:
	void getSonPublic(){

		cout << "-----------------------public继承父类-------------------------" << endl;


		//访问父类的public
		cout << "------子类内public方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内public方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内public方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
		cout << "" << endl;
		getSonProtected();
		cout << "" << endl;
		getSonPrivate();
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;

	}
};

class son3 :private dad{
private:
	void getSonPrivate(){
		//访问父类的public
		cout << "------子类内private方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内private方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内private方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
protected:
	void getSonProtected(){
		//访问父类的public
		cout << "------子类内protected方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内protected方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内protected方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
	}
public:
	void getSonPublic(){

		cout << "-----------------------public继承父类-------------------------" << endl;


		//访问父类的public
		cout << "------子类内public方法访问父类public属性------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//访问父类的protected
		cout << "------子类内public方法访问父类protected属性------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//访问父类的private
		cout << "------子类内public方法访问父类private属性------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********不能被访问*************" << endl;
		cout << "" << endl;
		getSonProtected();
		cout << "" << endl;
		getSonPrivate();
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;

	}
};

//子类访问父类的权限
/*
   在子类外：（main）
      不管继承权限是什么，子类只能访问父类的public属性
   子类内部：
      不管继承权限是什么，子类只能访问父类的public/protected属性
*/
//void main(){
//	//子类外访问父类属性
//	son1 s1;
//	s1.dad_public;
//	s1.getAccessPublic();
//	son1 s2;
//	s2.dad_public;
//	s2.getAccessPublic();
//
//	son1 s3;
//	s3.dad_public;
//	s3.getAccessPublic();
//	cout << "******************************************************************" << endl;
//	//子类内访问父类属性
//	s1.getSonPublic();
//	s2.getSonPublic();
//	s3.getSonPublic();
//	system("pause");
//}

class call{
public:
	char* name;
	 void myPrint(){
		cout << name << endl;
	}
};

class dog:public call{

};

class cat :public call{

};

class who :public dog, public cat{

};


class pig :virtual public call{
};

class ox :virtual public call{

};
class which :public pig, public ox{

};

//继承的二义性
/*
   virtual----解决从不同类继承同源且同名的成员，而调用该同源且同名成员时，导致不明确。
*/

void kindPrint(call& c){
	c.myPrint();
}

//void main(){
//	who wo;
//	//报错，不明确
//	//w.name = "xxx";
//	wo.dog::name = "xxx";
//
//	//用virtual解决不明确
//	which wi;
//	wi.name = "hhh";
//
//	system("pause");
//}



class football{
public:
	void play(){
		cout << "我爱踢足球" << endl;
	}
};

class basketball:public football{
public:
	void play(){
		cout << "我爱打篮球" << endl;
	}
};

class ping_pong{
public:
	virtual void play(){
		cout << "我打乒乓球" << endl;
	}
};

class badminton :public ping_pong{
public:
	virtual void play(){
		cout << "我爱打羽毛球" << endl;
	}
};


void  active(football& f){
	f.play();
}

void  active1(football& f){
	f.play();
}

void  active1(basketball& f){
	f.play();
}
//引用多态
void  active2(ping_pong& f){
	f.play();
}

//指针多态
void  active3(ping_pong* f){
	f->play();
}

//多态
//静态多态---重载
//动态多态----virtual,原理：指针引用随便类型转换，只要其存储的地址不变。
//只有父类引用或者指针，才能实现多态，直接强转父类不能实现多态。

//void main(){
//	football fb;
//	fb.play();
//    
//	basketball bb;
//	bb.play();
//
//	football fbb = bb;
//	//调用football的play
//	fbb.play();
//
//	//只会调用football的play
//	active(fb);
//	active(bb);
//
//
//	//静态多态---重载
//	active1(fb);
//	active1(bb);
//
//	//play方法加入virtual
//	ping_pong pp;
//	badminton bm;
//	
//	//实现引用多态，调用不同类的play
//	active2(pp);
//	active2(bm);
//
//	//实现指针多态，调用不同类的play
//	active3(&pp);
//	active3(&bm);
//	//直接强转父类
//	ping_pong pp2 = bm;
//	pp2.play();
//
//	system("pause");
//}

class shape{
    
public:
	//纯虚函数
	virtual void sayR() = 0;
	//虚函数
	virtual void setVaule();
};

class circle :public shape{
private:
	int r;
public:
	circle(int r){
		this->r = r;
	}
	void sayR(){
	
		cout << "圆的半径："<<r << endl;
	}
};


//纯虚函数（抽象类）
/*
   1.含有纯虚函数的类为抽象类
   2.抽象类不能实例化对象
   3.子类（circle）继承抽象类，必须要实现其纯虚函数
*/
//void main(){
//	circle cc(10);
//	cc.sayR();
//	system("pause");
//}



template <typename T>
void myswap(T& a,T& b){
	T tmp = NULL;
	tmp = a;
	a = b;
	b = tmp;
	cout << "a:"<<a <<",b:"<< b << endl;
}

//模板函数（泛型）

//void  main(){
//	int a = 10;
//	int b = 30;
//	myswap(a,b);
//
//	char x = 'p';
//	char y = 'k';
//	myswap<char>(x,y);
//
//
//	system("pause");
//}

template <class E>
class AA{
public:
	AA(E a){
		this->a = a;
	}
	
protected:
	E a;
	void printAA(){
		cout << "AA:" << a << endl;
	};
};

class BB:public AA<int>{
public:
	BB(int i, int j) :AA(i){
		this->j = j;
	}
	void printBB(){
		this->printAA();
		cout << "BB:" << j << endl;
	};
private:
	int j;
};

//模板类继承模板类
template <class R,class T>
class CC:public AA<T>{
public:
	CC(R j, T i) :AA(i){
		this->j = j;
	}
	void printCC(){
		this->printAA();
		cout << "CC:" << j << endl;
	};
private:
	R j;
};


//模板类
//void main(){
//	BB bb(10,20);
//	bb.printBB();
//	char c = 'c';
//
//	CC<char,int> d(c,520);
//	d.printCC();
//	system("pause");
//}

//void main(){
//
//	system("pause");
//}



//C++异常处理，根据抛出异常数据类型，进入相应的catch块中
//void main(){
//	try{
//		int i = 200;
//		if (i <=0)
//		{
//			throw 100;
//		}
//		if (i<100){
//			throw "你被逮捕了";
//		}
//		if (i>100)
//		{
//			throw 109.8;
//		}
//	
//	}
//	catch (int a){
//		cout << "捕获Int类型异样：" << a << endl;
//	}
//	catch (char* a){
//		cout << "捕获string类型异样：" << a << endl;
//	}
//	catch (...){
//		cout << "捕获未知类型异样" << endl;
//	}
//	system("pause");
//}

class MyException{

};


void mydiv(int b) throw(char*,int){

	if (b<0)
	{
		throw "whhhhhhhhh";
	}

	if (b == 0){
		throw new MyException();
	}
	if (b == 1){
		//只好不要用指针，因为后面要delete
		throw new MyException;
	}
}

//throw 抛出函数外
//void main(){
//	try{
//	
//		mydiv(-1);
//	}
//	catch (char* e){
//		//引用异常也会被捕获
//		cout << "捕获异常:" <<e<< endl;
//	}
//	catch (MyException e){
//		//引用异常也会被捕获
//		cout <<"捕获异常MyException"<< endl;
//	}
//	catch (MyException* e){
//		cout << "捕获异常指针MyException" << endl;
//		delete e;
//	}
//	system("pause");
//}

class customizeErr :public exception{

public:

	customizeErr(char* msg):exception(msg){
	
	}

	//内部类抛出异常
	class myErr:public exception
	{
	public:
		myErr(char* msg):exception(msg){
		
		}
	};
};



//自定义异常
//void main(){
//
//	try{
//		int i = 1;
//		if (i==0)
//		{
//			throw customizeErr("不可为0");
//		}
//		if (i == 1)
//		{   
//			//内部类异常
//			throw customizeErr::myErr("内部类异常");
//		}
//	}
//	catch(customizeErr e){
//		cout << e.what() << endl;
//	}
//	catch (customizeErr::myErr e){
//		cout << e.what() << endl;
//	}
//	system("pause");
//}

#include <stdexcept>

//定义标准异常
//void main(){
//	int i = 5;
//	try{
//		if (i>10)
//		{
//			throw out_of_range("超出范围");
//		}
//		if (i = 5)
//		{
//			throw invalid_argument("参数错误");
//		}
//	}
//    catch (exception e){
//		cout << e.what() << endl;
//	}
//	system("pause");
//}


//c++类型转换
//   static_cast
//   const_cast
//   dynamic_cast  父类转子类
//   reinterpret_cast  函数指针转型，不具备移植性


//隐式转换不好处：可读性不高，且不安全--dynamic_cast中演示。



//   static_cast
//   const_cast
//void main(){
//     
//	//static_cast
//	int i = 0;
//	int k = 0;
//	double j = 9.5;
//	//隐式
//	i = j;
//	cout << i << endl;
//	k = static_cast<int>(j);
//	cout << k << endl;
//
//
//	//   const_cast
//	const double t = 10.0;
//
//	//隐士
//	double g =(double)t;
//	cout << g << endl;
//	g = 20;
//	cout << g << endl;
//	//去除const
//
//	double b = const_cast<double&>(t);
//	cout << b << endl;
//	b = 50;
//	cout << b << endl;
//	system("pause");
//}



class person{
public:
	virtual void classify(){
		cout << "我是人类" << endl;
	}

};


class man :public person{
public:
	virtual void classify(){
		cout << "我是男人" << endl;
	}

	void play(){
		cout << "我喜欢打飞机" << endl;
	}
};


class woman :public person{
public:
	virtual void classify(){
		cout << "我是女人" << endl;
	}
	void play(){
		cout << "我喜欢逛街" << endl;
	}
};


//dynamic_cast
void fun(person *obj){
	obj->classify();
	//不安全的强转,本来是man的指针，结果可以强转为woman.
	woman* wm = (woman*)obj;
	wm->play();

	man* m = dynamic_cast<man*>(obj);
	m->play();

}

void fun1(){
	cout << "fun1....." << endl;
}

char* fun2(){
	cout << "fun2....." << endl;
	return "abc";
}

typedef void(*func)();//定义指针函数

//   dynamic_cast  父类转子类
//   reinterpret_cast  函数指针转型，不具备移植性
//void main(){
//
//	//dynamic_cast
//	man m;
//	person *p = &m;
//	//将父类转子类
//	fun(p);
//
//	//reinterpret_cast
//	func f[2];
//	f[0] = fun1;
//	//char* 转换成void
//	f[1] =reinterpret_cast<func>(fun2);
//	char* ch = reinterpret_cast<char*>(f[1]);
//
//	printf("%s\n",ch);
//
//	system("pause");
//}





//IO流
#include <fstream>





//文本文件的操作
//void main(){
//	char* path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\cpp.txt";
//	
//	ofstream fout(path);
//
//	if (fout.bad())
//	{  
//		cout << "文件输出流打开失败" << endl;
//		return;
//	}
//
//	//写入
//	fout << "jack" << endl;
//	fout << "Rose" << endl;
//
//	//关闭
//	fout.close();
//
//	//读取
//	ifstream fin(path);
//	if (fin.bad())
//	{
//		cout << "文件输出流打开失败" << endl;
//		return;
//	}
//	char ch;
//	while (fin.get(ch)){
//		cout << ch;
//	}
//
//	fin.close();
//
//	system("pause");
//}



//二进制文件复制
//void main(){
//
//	char* src = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture.png";
//	char* dest = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture2.png";
//
//	//ios---输出模式  binary--二进制
//	ifstream fin(src, ios::binary);
//	ofstream  fout(dest,ios::binary);
//
//	if (fin.bad()||fout.bad()){
//		cout << "文件流打开失败" << endl;
//		return;
//	}
//
//
//	while (!fin.eof())
//	{
//		char buff[1024] = { 0 };
//		//末尾为0不会写进去
//		fin.read(buff,1024);
//
//		fout.write(buff,1024);
//	}
//
//	fin.close();
//	fout.close();
//
//	system("pause");
//}

class bbq{
	char* name;
	int Age;
public:
	bbq(){}
	bbq(char* name,int age){
		this->name=name;
		this->Age=age;
	}
	void myPrint(){
		cout << "名字：" << name << ",年龄：" << Age << endl;
	}
};

//读取对象
//void main(){
//	char* path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\obj.txt";
//
//	ofstream fout(path,ios::binary);
//	if (fout.bad())
//	{
//		return;
//	}
//
//	bbq bq("小朋友",16);
//	bbq bq2("成年人", 18);
//	fout.write((char*)(&bq),sizeof(bbq));
//	fout.write((char*)(&bq2), sizeof(bbq));
//	fout.close();
//
//	ifstream fin(path,ios::binary);
//	if (fin.bad())
//	{
//		return;
//	}
//
//	bbq tmp;
//
//	fin.read((char*)(&tmp),sizeof(bbq));
//	tmp.myPrint();
//
//	fin.read((char*)(&tmp), sizeof(bbq));
//	tmp.myPrint();
//
//
//	fin.close();
//	system("pause");
//}


#include <string>
//stl  ----standard template library
//标准模板库---类似于Java 集合的util

//string
//void main(){
//
//
//	//字符串
//	string s1 = "hello ";
//	string s2 = "world";
//    cout << s1+s2<< endl;
//
//	//append
//	s1.append(" girls");
//	cout << s1 << endl;
//
//	//assigin
//	string s3;
//	s3.assign(s2, 1, 2);
//	cout << s3 << endl;//or
//
//	//at
//	char ch = s2.at(1);
//	cout << ch << endl;
//
//	//length
//	int i = 0;
//	for (; i < s2.length(); i++){
//		cout << s2[i] << endl;
//	}
//
//	// c_str/data-----string转char*
//	char* cp=(char*)malloc(sizeof(char)*s2.length()+1);
//	strcpy(cp,s2.c_str());
//	//最好不要这样用，因为string是new出来的，最终会自动析构的，容易导致cp1也为空。
//	char* cp1 = (char*)s2.c_str();
//	char* cp2 = (char*)s2.data();
//
//	//compare
//	string str1("green apple");
//	string str2("red apple");
//
//	if (str1.compare(str2) != 0)
//		cout << str1 << " is not " << str2 << '\n';
//
//	if (str1.compare(6, 5, "apple") == 0)
//		cout << "still, " << str1 << " is an apple\n";
//
//	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
//		cout << "and " << str2 << " is also an apple\n";
//
//	if (str1.compare(6, 5, str2, 4, 5) == 0)
//		cout << "therefore, both are apples\n";
//
//
//	//copy
//	string str3 = "str3";
//    string str4 = ",wo de m y";
//	char buff[20];
//	str3.copy((char*)str4.data(), 4);
//	cout << str4 << endl;
//
//
//	//empty
//	string tmp = "";
//	string tmp2 ;
//	if (tmp.empty()){//true
//		cout << "string 为空" << endl;
//	}
//	if (tmp2.empty()){  //true
//		cout << "string 为空" << endl;
//	}
//
//
//
//	//erase 删除
//	string  name = "i do not";
//	name.erase(4,4);  
//	cout <<name << endl; //i do
//
//
//	//find
//	string gg = "faeesfdfeedaeef";
//	int index=gg.find("ee");
//	cout << index << endl; //2
//	index = gg.find("ee",3);
//	if (index!=string::npos)
//	   cout << "第二次找到字符串ee的下标为："<<index << endl; //8
//
//	//insert
//	string in = "acd";
//	in.insert(1,"b");
//	cout << in << endl;
//     
//	//replace
//	string re = "it is err";
//    re.replace(6,3,"ok");
//	cout << re << endl;
//
//	//resize---改变数组大小
//	 string res = "i like to code in c";
//	 unsigned sz=res.size();
//	 res.resize(sz+2,'+');
//	 cout << res << endl;
//
//
//	 //substr
//	 string su = "hot day";
//	 cout << su.substr(4)<< endl;
//
//
//	 //swap---交换
//	 string sa = "sasasa";
//	 string sb = "sbsbsb";
//	 sa.swap(sb);
//	 cout << sa << endl;
//	 cout << sb << endl;
//
//
//	 //判断相等用compare/strcmp,不能用==，其为地址是否相等
//	 string de = "123123";
//	 string dd = "asdfafafd";
//	 string dd2 = "asdfafafd";
//	 char* sbp = (char*)de.c_str();
//	 char* sdd = (char*)dd.data();
//	 char* sdd2 = (char*)dd2.data();
//	 //==
//     cout << (de == dd) << endl;//0
//	 cout << (dd == dd2) << endl;//1
//	 //strcmp
//	 cout << (strcmp(sbp,sdd)) << endl;//-1
//	 cout << (strcmp(sdd2, sdd)) << endl;//0
//
//	 //compare
//	 cout << de.compare(dd) << endl;//-1
//	 cout << dd2.compare(dd) << endl;//0
//	system("pause");
//}


#include <vector>

//加入随机库
#include <ctime>
#include <cstdlib>
//sort 
#include <algorithm>
//vector----类似Java  list


void printVecotr(vector<int> &obj){
	int i = 0;
	for (; i < obj.size(); i++){
		cout << obj[i] <<",";
	}
	cout << endl;
}

//void main(){
//
//	vector<int> obj;
//	obj.push_back(1);
//	obj.push_back(2);
//	obj.push_back(3);
//
//	//错误
//	//obj[4] = 4;
//	//obj[3] = 13;
//	//去掉最后一个
//	obj.pop_back();
//
//	printVecotr(obj);
//
//	//清除
//	obj.clear();
//
//	int i = 0;
//	int tmp=0;
//	srand(int(time(0)));
//	for (;i<5;i++){
//		tmp = rand() % 10;
//		obj.push_back(tmp);
//		cout << tmp<<",";
//	}
//	cout << endl;
//
//	//从小到大
//	sort(obj.begin(),obj.end());
//
//	printVecotr(obj);
//
//	//从大到小
//	reverse(obj.begin(), obj.end());
//
//
//	//迭代器
//	vector<int>::iterator it;
//	for (it = obj.begin(); it != obj.end();it++){
//		cout << *it << ",";
//	}
//	cout << endl;
//
//
//	//二维数组
//	vector<vector<int>> arr(5); 
//
//	for (int i = 0; i< obj.size(); i++)//动态二维数组为5行6列，值全为0 
//	{
//		arr[i].resize(6);
//	}
//
//	for (int i = 0; i< arr.size(); i++)//输出二维动态数组 
//	{
//		for (int j = 0; j<arr[i].size(); j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	cout << "\n";
//	vector<vector<int>> arb(5,vector<int>(6));
//
//	for (int i = 0; i< arb.size(); i++)//输出二维动态数组 
//	{
//		for (int j = 0; j<arb[i].size(); j++)
//		{
//			cout << arb[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//
//	//方法
//
//	//assign
//	vector<int> v1;
//	vector<int> v2;
//	v1.assign(5, 100);
//	printVecotr(v1);//100,100,100,100,100,
//	vector<int>::iterator it2;
//	it = v1.begin() + 1;
//	v2.assign(it,v1.end()-1);
//    printVecotr(v2);//100,100,100,
//
//	//at 
//    i = 0;
//	for (; i < 5; i++) {
//		cout << "Element " << i << " is " << v1.at(i) << endl;
//	}
//
//	//empty
//	if (!v1.empty()){
//	
//		cout << "v1不为空，清除" << endl;
//		v1.clear();
//	}
//
//	//erase  ---擦除
//	vector<char> ch;
//	vector<char>::iterator it3;
//
//	string str = "abcdefg";
//	string::iterator its;
//	for (its = str.begin(); its != str.end(); its++){
//		ch.push_back(*its);
//	}
//
//	it3 = ch.begin() + 3;
//	ch.erase(it3);
//	 
//	i = 0;
//	for (;i<ch.size();i++){
//		cout << ch[i] << ',';
//	}
//	cout << endl;
//
//
//	//insert
//	vector<char> ch2;
//	ch2.push_back('a');
//	ch2.push_back('a');
//	ch2.push_back('a');
//	ch2.push_back('a');
//
//	ch2.insert(ch2.begin()+2,'b');
//
//	i = 0;
//	for (; i<ch2.size(); i++){
//		cout << ch2[i] << ',';
//	}
//	cout << endl;
//
//    //rend---返回当前位置的迭代器
//	
//	//swap---交换
//	vector<string> v4(1,"over");
//	vector<string> v5(1, "finsh");
//	v4.swap(v5);
//	cout << v4[0] << endl;
//	cout << v5[0] << endl;
//	system("pause");
//}



void main(){
	char c = 'c';
	int a = 4;
	float f = 3.14;
	double d = 1.212;
	float x = c + a / (int)d + f;
	cout <<x<< endl;
	system("pause");
}