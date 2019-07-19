#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <string.h>
#include <stdio.h>


struct piece
{
	char *path;
	int size;
};

//����ļ���С
int getFileSize(FILE * path){
	long size = 0;
	fseek(path, 0, SEEK_END);
	size = ftell(path);
	fseek(path, 0, SEEK_SET);
	return (int)size;
}

//��֤�ļ����Ƿ�ɹ�
bool isOpen(FILE *path){
	if (path != NULL)
	{
		return true;
	}
	return false;
}
void divideText(char *path, struct piece content[], int index){
	FILE *dividePath = fopen(path, "r");
	if (!isOpen(dividePath))
	{
		return;
	}

	//�ָ���
	int divideNum = index;
	printf("divideNum:%d\n", divideNum);
	if (divideNum <= 0)
	{
		printf("�ָ��ļ���������Ϊ0\n");
		return;
	}
	//������ļ���С
	int total = getFileSize(dividePath);
	//ÿ���ָ��ļ���С
	int  divideSize = (total / divideNum);
	//��������������
	int remainder = total%divideNum;
	//���Ƿָ��ļ������ݵ���һ����char����������ÿ���ַ�ռ2 byte.���Ƿָ�ʱҪ���ǣ����һ���ַ��Ƿ�ᱻ�ָ
	if (divideSize % 2 != 0){
		divideSize--;
		remainder = remainder + divideNum;
	}
	//����fgets �ڲ��ǿ�����\n�Ľ���������-1�������������Լ��ı��ָ�û�п���\n������Ҫ+1��
	int loop = divideSize / 50;
	if (loop<0)
	{
		divideSize = divideSize + 1;
	}
	else{
		//���ڴ���50byte���ļ���ÿ��ѭ��һȦ�����1
		divideSize = divideSize + 1 + loop;
	}

	if (divideSize <= 0)
	{
		printf("�ļ�̫С�����ܱ�����");
		return;
	}

	//����Ѿ��ָ���ļ�����
	int i = 0;
	//ÿ���ָ��ļ��Ĵ�С
	int len = 0;
	//ÿ�ΰ��˵Ļ���---50byte
	char buff[50];
	//ÿ�ΰ��˴�С��byte��
	int carry = 50;

	if (divideSize < 50){
		carry = divideSize;
	}
	else
	{
		carry = 50;
	}
	printf("divideSize��ֵ%d\n", divideSize);
	printf("total��ֵ%d\n", total);

	FILE * obj = NULL;

	while (fgets(buff, carry, dividePath))
	{
		//�ж��Ƿ���Ҫ�����ָ��ļ�
		if ((len <= 0) && (i < divideNum))
		{
			//�ر�ÿһ���ļ���
			if (isOpen(obj))
			{
				int  size = getFileSize(obj);
				printf("��%d�ָ��ļ��Ĵ�СΪ��%d\n", i, size);
				fclose(obj);
			}

			struct piece b = content[i];
			//��ÿһ���ָ������С

			printf("-------��%d�ηָ�------\n", i + 1);
			printf("�ļ�·��:%s\n", content[i].path);
			if (remainder != 0 && i >= divideNum - 1){
				b.size = divideSize + remainder;
			}
			else{
				b.size = divideSize;
			}
			printf("Ԥ�Ƶ�%d�ָ��ļ��Ĵ�СΪ��%d\n", i + 1, b.size);
			//��ʼ��������
			i++;
			len = b.size;
			//�����µķָ��ļ�
			FILE *fileName = fopen(b.path, "w");
			obj = fileName;
			fileName = NULL;

		}
		if (!isOpen(obj))
		{
			printf("�˳�\n");
			return;
		}

		len = len - carry;
		printf("len,carry---%d,%d\n", len, carry);
		fputs(buff, obj);

		//fwrite 

		//fwrite(buff, carry, 1, obj);
		//fwrite(buff,(carry-1)/2,2,obj);
		//�ָ��ļ�����50�����
		if (len > 0 && len < 50)
		{
			carry = len;
		}

		//һ�ΰ��˽���
		else if (len <= 0)
		{

			if (divideSize < 50)
			{
				//���һ�ε�carry
				if ((i == divideNum - 1) && (remainder != 0))
				{
					carry = divideSize + remainder;
				}
				else
				{
					carry = divideSize;
				}
			}
			else
			{
				//����50byte���ļ���
				carry = 50;
			}

			//�ָ����
			if (i >= divideNum){
				printf("�ָ��ļ����\n");
				break;
			}
		}


		//��ֹcarry����buff��Χ
		if (carry > 50)
		{
			carry = 50;
		}

	}



	fclose(dividePath);
	if (isOpen(obj)){
		int size = getFileSize(obj);
		printf("��%d�ָ��ļ��Ĵ�СΪ��%ld\n", 2, size);
		fclose(obj);
	}
	dividePath = NULL;
	obj = NULL;

}

void mergeText(char *path1, char *path2){


}

void main(){

	char *path = "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\come.txt";
	struct piece b1 = { "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\divide1.txt", 0 };
	struct piece b2 = { "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\divide2.txt", 0 };
	struct piece b3 = { "D:\\Users\\Miss\\BaiduNetdiskDownload\\android\\ndk\\divide3.txt", 0 };

	struct piece content[] = { b1, b2, b3 };
	divideText(path, content, (sizeof(content) / sizeof(struct piece)));

	system("pause");
}