#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


//�Զ��������ռ�------�ȵ���Java�İ�
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

//ʹ���Զ��������ռ�
//void main(){
//
//	using namespace NSP_B;
//	//::�������
//
//	//NSP_A
//	cout << "�Զ���ռ�NSP_A---a��ֵ:" << NSP_A::a << endl;
//	struct NSP_A::MyStruct ms;
//	cout << "�Զ���ռ�NSP_A---xx��ֵ:" << ms.xx<< endl;
//
//	//NSP_B
//	cout << "�Զ���ռ�NSP_B---b��ֵ:" << b << endl;
//	cout << "�Զ���ռ�NSP_B�ÿռ�NSP_A---a��ֵ:" << a << endl;
//	cout << "�Զ���ռ�NSP_B�ÿռ�NSP_C---c��ֵ:" << NSP_B::NSP_C::c << endl;
//	cout << "�Զ���ռ�NSP_B�ÿռ�NSP_C---d��ֵ:" << NSP_C::d << endl;
//	struct stu st;
//	cout << "�Զ���ռ�NSP_B�ÿռ�NSP_C---yy��ֵ:" << st.yy << endl;
//
//
//	//���ռ��ظ�
//	using NSP_A::MyStruct;
//	MyStruct ms1;
//    //��Ϊǰ��mainʹ�õ���NSP_B�Ŀռ䣬���Բ���using NSP_B::MyStruct;
//	MyStruct ms2;
//	//����
//	NSP_A::MyStruct ms3;
//	NSP_B::MyStruct ms4;
//
//	cout << "�Զ���ռ������ṹ��:" << ms1.xx<< endl;
//	cout << "�Զ���ռ������ṹ��:" << ms2.xx << endl;
//	cout << "�Զ���ռ������ṹ��:" << ms3.xx << endl;
//	cout << "�Զ���ռ������ṹ��:" << ms4.xx << endl;
//	system("pause");
//}


//�궨��
#define PI 3.14;

struct ms{
private:
	int i;
	void pp(){
		cout << "i=" << i << ",j=" << j << endl;
		cout << "c++�Ľṹ����c�Ľṹ��������ͬŶ" << endl;
	};
public:
	int j;
	void p(int k){
		i = k;
		pp();
	};
}m;


//c++�Ľṹ����c�Ľṹ��������ͬ
//void main(){
//	cout << "��ӭ�ص�C++" << endl;
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

//���ö�̬����ռ�
void guideSpace(space* &p){
	p = (space*)malloc(sizeof(space));
	p->a = 100;
}
void openSpace(space** p){
	*p = (space*)malloc(sizeof(space));
	(*p)->a = 10;
}

//ָ��������
//void main(){
//	int a = 10;
//	int b = 20;
//	replay(&a,b);
//	//a��b���ı���
//	cout << "ָ�������a=" << a << ",���ò�����b=" << b << endl;
//
//	space* sp=NULL;
//	//����ָ�붯̬����
//	openSpace(&sp);
//	cout << (*sp).a << endl;
//	//���õĶ�̬����
//	guideSpace(sp);
//	cout << (*sp).a << endl;
//	system("pause");
//}



void isNull(int &b){
  
	cout << "����NULL" << endl;
}

//������

//������ָ�������
//1.����ΪNULL��
//void main(){
//
//	int d = 10;
//	const int i = 100;
//	const int &k = i;
//    int* p = (int *)&k;
//	*p = 20;
//	//����k�����ջ�����Կ����޸�
//	cout << k << endl;
//	//����i��ŷ��ű���
//	cout << i<< endl;
//
//	cout << sizeof(i) << endl;
//
//	//int &c = NULL;�������ò���ΪNULL
//
//	system("pause");
//}



void  fpx(int num,...){
	int result = 0;
	va_list vl;     //va_listָ�룬����va_startȡ�ɱ������Ϊchar*
	_crt_va_start(vl, num);       //ȡ�ÿɱ�����б��еĵ�һ��ֵ
	printf("num:%d, vl:%d\n", num, *vl);
	while (*vl>0)
	{
		result = _crt_va_arg(vl, int);//�����vl��������4���ֽڣ�sizeof(int)��С��ָ����һ�����������ص��ǵ�ǰ������������
		//һ��������
		if (*vl<=0)
		{
			break;
		}
		printf("in for  result:%d,  *vl:%d\n", result, *vl);//�����ӡ�£����Կ�����vl����ָ��result������Ǹ�����,v1>
	}

	_crt_va_end(vl);//������־  
}



//�ɱ����
//void main(){
//
//	fpx(10, 1, 2, 3, 4, 5);
//
//	system("pause");
//}



//C++ ��ͨ�÷� 
//header.h---���������header.cpp���ʵ�֣�

//#include "header.h";

//void main(){
//	header h;
//	h.setData(666);
//	h.setTitle("ţ�ư�");
//	cout << h.getData() << endl;
//	cout << h.getTitle() << endl;
//	system("pause");
//}


class Teacher{
private:
	char* name;
	int age;
public:
	//�޲ι��캯��
	Teacher(){
		cout << "�޲ι��캯��" << endl;
	}
	//�вι��캯��
	Teacher(char* name,int age){

		
		//this->name = name;
		//strcpy(this->name, name);
		this->name = name;
		this->age = age;
		cout << "�вι��캯��" << endl;
	}

	//��������
	~Teacher(){
		cout << "��������"  << endl;
		//free(this->name);
	}

};

//Ϊ�˴�����������
void del(){
	Teacher t3("Hi",22);
}


//���캯���������������������캯����
//1.��Javaһ�������д���вι��캯�����������д�޲ι��캯������û���޲ι��캯��

//void main(){
//
//	//�����޲ι��캯��
//	Teacher t1;
//	//�����вι��캯��
//	Teacher t2("��Ů",18);
//	//��һ���÷�
//	Teacher t4=Teacher("goodBoy", 22);
//	//������������
//	del();
//	system("pause");
//}


class student{
private:
	char* name;
	int age;
public:

	//���캯��
	student(char* name,int age){
		cout << "����-----���캯��" << endl;
		this->age = age;
		this->name = name;
	}
	//ǳ�������캯��---ָ��
	student(student *p){
		cout << "����-----ָ��ǳ����" << endl;
		this->age = p->age;
		this->name = p->name;
	}

	//ϵͳĬ��ǳ�������캯��
	student(const student &p){
		cout << "����-----ϵͳĬ��ǳ�������캯��" << endl;
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
//��������---ǳ������ֵ������

//void main(){
//
//	//�������캯����
//	student s1("����ָ��ǳ����", 25);
//
//	//ֵ����
//	student s2 = &s1;//����������ָ�룬��&s1
//
//	//ϵͳĬ�Ͽ������캯��
//	student s3 = s2;
//    //��Ϊ�����ǻᱻ����ϵͳĬ�Ͽ������캯��
//	copy(s3);
//	//��Ϊ����ֵҲ�����ϵͳĬ�Ͽ������캯��
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
	   //��̬����
		this->weight = (int *)malloc(sizeof(int));
	
	}

	void myPrint(){
		cout << "-------------------------" << endl;
		cout << "ageָ���Լ��ĵ�ַ��" << &(this->weight) << endl;
		cout << "ageָ��ָ��ĵ�ַ��" << this->weight << endl;
		cout << "ageָ��ָ��ĵ�ַ��ֵ��" << *(this->weight) << endl;
	}
};

// ��ָ�������ǳ�����Ĳ���ȫ�ԣ��ƻ���ķ�װ��
//void main(){
//
//	//����ȫ�İ���
//	int i = 250;
//	int*p = &i;
//	cout << "pָ���Լ��ĵ�ַ��" << &p << endl;
//	cout << "pָ��ָ��ĵ�ַ��" << p << endl;
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
		//��̬���䣬����ֵ
		this->name = (char *)malloc(sizeof(char)*strlen(obj.name)+1);
		strcpy(this->name,obj.name);
	}

	~car(){
		cout << "--------��������----------" << endl;
		free(this->name);
	}

	void myPrint(){
		cout << "-------------------------" << endl;
		cout << "car.nameָ���Լ��ĵ�ַ��" << &(this->name) << endl;
		cout << "car.nameָ��ָ��ĵ�ַ��" << this->name << endl;
		cout << "car.nameָ��ָ��ĵ�ַ��ֵ��" << *(this->name) << endl;
	}
};

void  gc_car(){
	car c1("������");
	c1.myPrint();
	car c2 = c1;
	c2.myPrint();
}

//��ȿ���

//ʹ��������裺
//1.��дϵͳĬ�Ͽ�������car(const car &obj)���캯��,
//2.�����Աָ�븳ֵ�ĵط����ö�̬����+strcpy��ֵ��
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
		cout << "money----���캯��"<< endl;
		this->num = d;
	}

	~money(){
		cout << "money----��������" << endl;
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
		cout << "wallet----���캯��" << endl;
		this->master = name;
	}

	~wallet(){
		cout << "wallet----��������" << endl;
	}
	void myPrint(){
		cout << "���ˣ�" << master << "��" << m.getMoney() << "��Ԫ" << endl;
	}

};



void order(){
	wallet w("baby",10000);
	w.myPrint();
}

//���е����Զ���ĳ�ʼ��
//���캯������˳��
//1.�ȵ������Զ���Ĺ��캯��
//2.�ٵ������Լ��Ĺ��캯��
//��������˳��
//3.���Լ��ȵ����Լ���������
//4.������Զ�������

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
		cout << "���캯��������" << endl;
		this->name = name;
	}

	~baby(){
		cout << "��������������" << endl;
	}

	void setName(char* name){
		this->name = name;
	}
	void myPrint(){
		cout << this->name << endl;
	}
};


//C++ ͨ��new(delete)��̬�ڴ����
/*
  new(delete)��malloc(free)������
  malloc(free)������ù��������������
*/
//void main(){
//	
//	baby* b = new baby("С��");
//	b->myPrint();
//	delete(b);
//
//	//��c��malloc��free
//	baby* b2 = (baby*)malloc(sizeof(baby));
//	b2->setName("С��");
//	b2->myPrint();
//	free(b2);
//
//
//	//�����÷�
//	int* arr = new int[10];
//	arr[0] = 100;
//	//�ǵüӡ���
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

//static��̬����
/*
   ��Ϊstatic��Ա����û��thisָ�룬���Ծ�̬��Ա���������Է��ʷǾ�̬��Ա��
   �Ǿ�̬��Ա�������Է��ʾ�̬��Ա��
   ��̬���ݳ�Ա����Ĵ�С�޹أ���Ϊ��̬��Աֻ����������ķ�Χ����
*/
//void main(){
//	classmate::num = 100;
//
//	//��̬����
//	classmate::myPrint();
//
//	//�Ǿ�̬�������ʾ�̬�������ͷ���
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
		//this =pi;//���� �����޸ģ���Ϊ pine* const this
		//��ָ���ַ���ݿ����޸�
		this->p = 1000;
		myPrint();
	}


	//const ����this---->const pine* const this
	//����������ָ��ĵ�ַ�����ݶ������޸ģ�ֻ��
	void setThis2()const{
		//pine* pi;
		//this = pi;//����
		//this->p = 100000;//����
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
//	//p2.setThis();//����const����ֻ�ܵ���const����
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
//��Ԫ����
//���Է������г�Ա�����ͷ������������Լ����ǳ�Ա������
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
//��Ԫ��
//�������г�Ա
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

//���������operator
//void main(){
//	point p1(10,20);
//    point p2(20,10);
//	//������
//	point p3 = p2 + p1;
//	p3.myPrint();
//	//������
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
		cout << "���๹�캯��" << endl;
		this->c = c;
	}
	~human(){
		cout << "������������" << endl;
	}
	 void say(){
		cout << "���Ǹ��࣬hello!!!" << endl;
	}
};

class sunman:public human{
public:
    //���ڸ���û���޲ι��캯��
	sunman(int d):human(d){
		cout << "���๹�캯��" << endl;
	}

	~sunman(){
		cout << "������������" << endl;
	}
	 void say(){
	    
		cout << "�������࣬hell0" << endl;
	}
};


void fun5(){

	sunman m2(2);
}
//�̳�
/*
   1.ֻ�̳�public/protected
   2.����û���޲ι��캯��ʱ�����������д���캯����
   3.���๹�캯���ȵ��ã�Ȼ������ŵ���
   4.���������ȵ��ã�Ȼ����ŵ���
   5.�������ļ̳�Ȩ��public/protected/private�Ĳ�ͬ������������������Ͳ�ͬ
*/
//void main(){  
//	sunman m(1);
//	m.say();
//	cout << "---------ʵ�鸸�������ഴ��������˳��-------" << endl;
//	fun5();
//	cout << "----------------------------------" << endl;
//	//��������
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
		cout << "����private����������" << endl;
	}
protected:
	int dad_protected = 100;

	void getAccessProtected(){
		cout << "����protected����������" << endl;
	}
public:
	int dad_public = 1000;

	//������ʸ���public����
	void getAccessPublic(){
		cout << "����public����������" << endl;
	}
};

class son1:public dad{
private:
	void getSonPrivate(){
		//���ʸ����public
		cout << "------������private�������ʸ���public����------" << endl;
		cout << "dad_public:"<<this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������private�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������private�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
protected:
	void getSonProtected(){
		//���ʸ����public
		cout << "------������protected�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������protected�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������protected�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
public:
	void getSonPublic(){
		
		cout << "-----------------------public�̳и���-------------------------" << endl;
		

		//���ʸ����public
		cout << "------������public�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������public�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������public�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
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
		//���ʸ����public
		cout << "------������private�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������private�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������private�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
protected:
	void getSonProtected(){
		//���ʸ����public
		cout << "------������protected�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������protected�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������protected�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
public:
	void getSonPublic(){

		cout << "-----------------------public�̳и���-------------------------" << endl;


		//���ʸ����public
		cout << "------������public�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������public�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������public�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
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
		//���ʸ����public
		cout << "------������private�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������private�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������private�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
protected:
	void getSonProtected(){
		//���ʸ����public
		cout << "------������protected�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������protected�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������protected�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
	}
public:
	void getSonPublic(){

		cout << "-----------------------public�̳и���-------------------------" << endl;


		//���ʸ����public
		cout << "------������public�������ʸ���public����------" << endl;
		cout << "dad_public:" << this->dad_public << endl;
		this->getAccessPublic();
		//���ʸ����protected
		cout << "------������public�������ʸ���protected����------" << endl;
		cout << "dad_public:" << this->dad_protected << endl;
		this->getAccessProtected();
		//���ʸ����private
		cout << "------������public�������ʸ���private����------" << endl;
		//cout << "dad_public:" << this->dad_private << endl; 
		//this->getAccessPrivate();
		cout << "*********���ܱ�����*************" << endl;
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

//������ʸ����Ȩ��
/*
   �������⣺��main��
      ���ܼ̳�Ȩ����ʲô������ֻ�ܷ��ʸ����public����
   �����ڲ���
      ���ܼ̳�Ȩ����ʲô������ֻ�ܷ��ʸ����public/protected����
*/
//void main(){
//	//��������ʸ�������
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
//	//�����ڷ��ʸ�������
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

//�̳еĶ�����
/*
   virtual----����Ӳ�ͬ��̳�ͬԴ��ͬ���ĳ�Ա�������ø�ͬԴ��ͬ����Աʱ�����²���ȷ��
*/

void kindPrint(call& c){
	c.myPrint();
}

//void main(){
//	who wo;
//	//��������ȷ
//	//w.name = "xxx";
//	wo.dog::name = "xxx";
//
//	//��virtual�������ȷ
//	which wi;
//	wi.name = "hhh";
//
//	system("pause");
//}



class football{
public:
	void play(){
		cout << "�Ұ�������" << endl;
	}
};

class basketball:public football{
public:
	void play(){
		cout << "�Ұ�������" << endl;
	}
};

class ping_pong{
public:
	virtual void play(){
		cout << "�Ҵ�ƹ����" << endl;
	}
};

class badminton :public ping_pong{
public:
	virtual void play(){
		cout << "�Ұ�����ë��" << endl;
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
//���ö�̬
void  active2(ping_pong& f){
	f.play();
}

//ָ���̬
void  active3(ping_pong* f){
	f->play();
}

//��̬
//��̬��̬---����
//��̬��̬----virtual,ԭ��ָ�������������ת����ֻҪ��洢�ĵ�ַ���䡣
//ֻ�и������û���ָ�룬����ʵ�ֶ�̬��ֱ��ǿת���಻��ʵ�ֶ�̬��

//void main(){
//	football fb;
//	fb.play();
//    
//	basketball bb;
//	bb.play();
//
//	football fbb = bb;
//	//����football��play
//	fbb.play();
//
//	//ֻ�����football��play
//	active(fb);
//	active(bb);
//
//
//	//��̬��̬---����
//	active1(fb);
//	active1(bb);
//
//	//play��������virtual
//	ping_pong pp;
//	badminton bm;
//	
//	//ʵ�����ö�̬�����ò�ͬ���play
//	active2(pp);
//	active2(bm);
//
//	//ʵ��ָ���̬�����ò�ͬ���play
//	active3(&pp);
//	active3(&bm);
//	//ֱ��ǿת����
//	ping_pong pp2 = bm;
//	pp2.play();
//
//	system("pause");
//}

class shape{
    
public:
	//���麯��
	virtual void sayR() = 0;
	//�麯��
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
	
		cout << "Բ�İ뾶��"<<r << endl;
	}
};


//���麯���������ࣩ
/*
   1.���д��麯������Ϊ������
   2.�����಻��ʵ��������
   3.���ࣨcircle���̳г����࣬����Ҫʵ���䴿�麯��
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

//ģ�庯�������ͣ�

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

//ģ����̳�ģ����
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


//ģ����
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



//C++�쳣���������׳��쳣�������ͣ�������Ӧ��catch����
//void main(){
//	try{
//		int i = 200;
//		if (i <=0)
//		{
//			throw 100;
//		}
//		if (i<100){
//			throw "�㱻������";
//		}
//		if (i>100)
//		{
//			throw 109.8;
//		}
//	
//	}
//	catch (int a){
//		cout << "����Int����������" << a << endl;
//	}
//	catch (char* a){
//		cout << "����string����������" << a << endl;
//	}
//	catch (...){
//		cout << "����δ֪��������" << endl;
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
		//ֻ�ò�Ҫ��ָ�룬��Ϊ����Ҫdelete
		throw new MyException;
	}
}

//throw �׳�������
//void main(){
//	try{
//	
//		mydiv(-1);
//	}
//	catch (char* e){
//		//�����쳣Ҳ�ᱻ����
//		cout << "�����쳣:" <<e<< endl;
//	}
//	catch (MyException e){
//		//�����쳣Ҳ�ᱻ����
//		cout <<"�����쳣MyException"<< endl;
//	}
//	catch (MyException* e){
//		cout << "�����쳣ָ��MyException" << endl;
//		delete e;
//	}
//	system("pause");
//}

class customizeErr :public exception{

public:

	customizeErr(char* msg):exception(msg){
	
	}

	//�ڲ����׳��쳣
	class myErr:public exception
	{
	public:
		myErr(char* msg):exception(msg){
		
		}
	};
};



//�Զ����쳣
//void main(){
//
//	try{
//		int i = 1;
//		if (i==0)
//		{
//			throw customizeErr("����Ϊ0");
//		}
//		if (i == 1)
//		{   
//			//�ڲ����쳣
//			throw customizeErr::myErr("�ڲ����쳣");
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

//�����׼�쳣
//void main(){
//	int i = 5;
//	try{
//		if (i>10)
//		{
//			throw out_of_range("������Χ");
//		}
//		if (i = 5)
//		{
//			throw invalid_argument("��������");
//		}
//	}
//    catch (exception e){
//		cout << e.what() << endl;
//	}
//	system("pause");
//}


//c++����ת��
//   static_cast
//   const_cast
//   dynamic_cast  ����ת����
//   reinterpret_cast  ����ָ��ת�ͣ����߱���ֲ��


//��ʽת�����ô����ɶ��Բ��ߣ��Ҳ���ȫ--dynamic_cast����ʾ��



//   static_cast
//   const_cast
//void main(){
//     
//	//static_cast
//	int i = 0;
//	int k = 0;
//	double j = 9.5;
//	//��ʽ
//	i = j;
//	cout << i << endl;
//	k = static_cast<int>(j);
//	cout << k << endl;
//
//
//	//   const_cast
//	const double t = 10.0;
//
//	//��ʿ
//	double g =(double)t;
//	cout << g << endl;
//	g = 20;
//	cout << g << endl;
//	//ȥ��const
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
		cout << "��������" << endl;
	}

};


class man :public person{
public:
	virtual void classify(){
		cout << "��������" << endl;
	}

	void play(){
		cout << "��ϲ����ɻ�" << endl;
	}
};


class woman :public person{
public:
	virtual void classify(){
		cout << "����Ů��" << endl;
	}
	void play(){
		cout << "��ϲ�����" << endl;
	}
};


//dynamic_cast
void fun(person *obj){
	obj->classify();
	//����ȫ��ǿת,������man��ָ�룬�������ǿתΪwoman.
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

typedef void(*func)();//����ָ�뺯��

//   dynamic_cast  ����ת����
//   reinterpret_cast  ����ָ��ת�ͣ����߱���ֲ��
//void main(){
//
//	//dynamic_cast
//	man m;
//	person *p = &m;
//	//������ת����
//	fun(p);
//
//	//reinterpret_cast
//	func f[2];
//	f[0] = fun1;
//	//char* ת����void
//	f[1] =reinterpret_cast<func>(fun2);
//	char* ch = reinterpret_cast<char*>(f[1]);
//
//	printf("%s\n",ch);
//
//	system("pause");
//}





//IO��
#include <fstream>





//�ı��ļ��Ĳ���
//void main(){
//	char* path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\cpp.txt";
//	
//	ofstream fout(path);
//
//	if (fout.bad())
//	{  
//		cout << "�ļ��������ʧ��" << endl;
//		return;
//	}
//
//	//д��
//	fout << "jack" << endl;
//	fout << "Rose" << endl;
//
//	//�ر�
//	fout.close();
//
//	//��ȡ
//	ifstream fin(path);
//	if (fin.bad())
//	{
//		cout << "�ļ��������ʧ��" << endl;
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



//�������ļ�����
//void main(){
//
//	char* src = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture.png";
//	char* dest = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\picture2.png";
//
//	//ios---���ģʽ  binary--������
//	ifstream fin(src, ios::binary);
//	ofstream  fout(dest,ios::binary);
//
//	if (fin.bad()||fout.bad()){
//		cout << "�ļ�����ʧ��" << endl;
//		return;
//	}
//
//
//	while (!fin.eof())
//	{
//		char buff[1024] = { 0 };
//		//ĩβΪ0����д��ȥ
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
		cout << "���֣�" << name << ",���䣺" << Age << endl;
	}
};

//��ȡ����
//void main(){
//	char* path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\obj.txt";
//
//	ofstream fout(path,ios::binary);
//	if (fout.bad())
//	{
//		return;
//	}
//
//	bbq bq("С����",16);
//	bbq bq2("������", 18);
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
//��׼ģ���---������Java ���ϵ�util

//string
//void main(){
//
//
//	//�ַ���
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
//	// c_str/data-----stringתchar*
//	char* cp=(char*)malloc(sizeof(char)*s2.length()+1);
//	strcpy(cp,s2.c_str());
//	//��ò�Ҫ�����ã���Ϊstring��new�����ģ����ջ��Զ������ģ����׵���cp1ҲΪ�ա�
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
//		cout << "string Ϊ��" << endl;
//	}
//	if (tmp2.empty()){  //true
//		cout << "string Ϊ��" << endl;
//	}
//
//
//
//	//erase ɾ��
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
//	   cout << "�ڶ����ҵ��ַ���ee���±�Ϊ��"<<index << endl; //8
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
//	//resize---�ı������С
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
//	 //swap---����
//	 string sa = "sasasa";
//	 string sb = "sbsbsb";
//	 sa.swap(sb);
//	 cout << sa << endl;
//	 cout << sb << endl;
//
//
//	 //�ж������compare/strcmp,������==����Ϊ��ַ�Ƿ����
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

//���������
#include <ctime>
#include <cstdlib>
//sort 
#include <algorithm>
//vector----����Java  list


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
//	//����
//	//obj[4] = 4;
//	//obj[3] = 13;
//	//ȥ�����һ��
//	obj.pop_back();
//
//	printVecotr(obj);
//
//	//���
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
//	//��С����
//	sort(obj.begin(),obj.end());
//
//	printVecotr(obj);
//
//	//�Ӵ�С
//	reverse(obj.begin(), obj.end());
//
//
//	//������
//	vector<int>::iterator it;
//	for (it = obj.begin(); it != obj.end();it++){
//		cout << *it << ",";
//	}
//	cout << endl;
//
//
//	//��ά����
//	vector<vector<int>> arr(5); 
//
//	for (int i = 0; i< obj.size(); i++)//��̬��ά����Ϊ5��6�У�ֵȫΪ0 
//	{
//		arr[i].resize(6);
//	}
//
//	for (int i = 0; i< arr.size(); i++)//�����ά��̬���� 
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
//	for (int i = 0; i< arb.size(); i++)//�����ά��̬���� 
//	{
//		for (int j = 0; j<arb[i].size(); j++)
//		{
//			cout << arb[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//
//	//����
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
//		cout << "v1��Ϊ�գ����" << endl;
//		v1.clear();
//	}
//
//	//erase  ---����
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
//    //rend---���ص�ǰλ�õĵ�����
//	
//	//swap---����
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