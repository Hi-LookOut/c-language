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

//获得文件大小
int getFileSize(FILE * path){
	long size = 0;
	fseek(path, 0, SEEK_END);
	size = ftell(path);
	fseek(path, 0, SEEK_SET);
	return (int)size;
}

//验证文件打开是否成功
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

	//分割数
	int divideNum = index;
	printf("divideNum:%d\n", divideNum);
	if (divideNum <= 0)
	{
		printf("分割文件数不可以为0\n");
		return;
	}
	//获得总文件大小
	int total = getFileSize(dividePath);
	//每个分割文件大小
	int  divideSize = (total / divideNum);
	//不能整除，余数
	int remainder = total%divideNum;
	//我们分割文件的内容当作一个个char来看，所以每个字符占2 byte.于是分割时要考虑，最后一个字符是否会被分割。
	if (divideSize % 2 != 0){
		divideSize--;
		remainder = remainder + divideNum;
	}
	//由于fgets 内部是考虑了\n的结束符，会-1操作，而我们自己文本分割没有考虑\n，所以要+1。
	int loop = divideSize / 50;
	if (loop<0)
	{
		divideSize = divideSize + 1;
	}
	else{
		//对于大于50byte的文件，每多循环一圈，多加1
		divideSize = divideSize + 1 + loop;
	}

	if (divideSize <= 0)
	{
		printf("文件太小，不能被划分");
		return;
	}

	//标记已经分割的文件个数
	int i = 0;
	//每个分割文件的大小
	int len = 0;
	//每次搬运的缓存---50byte
	char buff[50];
	//每次搬运大小（byte）
	int carry = 50;

	if (divideSize < 50){
		carry = divideSize;
	}
	else
	{
		carry = 50;
	}
	printf("divideSize的值%d\n", divideSize);
	printf("total的值%d\n", total);

	FILE * obj = NULL;

	while (fgets(buff, carry, dividePath))
	{
		//判断是否需要创建分割文件
		if ((len <= 0) && (i < divideNum))
		{
			//关闭每一次文件流
			if (isOpen(obj))
			{
				int  size = getFileSize(obj);
				printf("第%d分割文件的大小为：%d\n", i, size);
				fclose(obj);
			}

			struct piece b = content[i];
			//给每一个分割块分配大小

			printf("-------第%d次分割------\n", i + 1);
			printf("文件路径:%s\n", content[i].path);
			if (remainder != 0 && i >= divideNum - 1){
				b.size = divideSize + remainder;
			}
			else{
				b.size = divideSize;
			}
			printf("预计第%d分割文件的大小为：%d\n", i + 1, b.size);
			//初始化变量。
			i++;
			len = b.size;
			//创建新的分割文件
			FILE *fileName = fopen(b.path, "w");
			obj = fileName;
			fileName = NULL;

		}
		if (!isOpen(obj))
		{
			printf("退出\n");
			return;
		}

		len = len - carry;
		printf("len,carry---%d,%d\n", len, carry);
		fputs(buff, obj);

		//fwrite 

		//fwrite(buff, carry, 1, obj);
		//fwrite(buff,(carry-1)/2,2,obj);
		//分割文件大于50的情况
		if (len > 0 && len < 50)
		{
			carry = len;
		}

		//一次搬运结束
		else if (len <= 0)
		{

			if (divideSize < 50)
			{
				//最后一次的carry
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
				//大于50byte的文件，
				carry = 50;
			}

			//分割完成
			if (i >= divideNum){
				printf("分割文件完成\n");
				break;
			}
		}


		//防止carry超出buff范围
		if (carry > 50)
		{
			carry = 50;
		}

	}



	fclose(dividePath);
	if (isOpen(obj)){
		int size = getFileSize(obj);
		printf("第%d分割文件的大小为：%ld\n", 2, size);
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