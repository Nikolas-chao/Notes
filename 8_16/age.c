/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: age.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月16日 星期三 19时15分55秒
***************************************************/

#include <stdio.h>
#include <string.h>
struct struct_info
{
	char name[50];          // 姓名
	int stu_num;            // 学号
	int age;                // 年龄
};

struct struct_info input_struct_info(struct struct_info info);

int main(int argc,const char* argv[])
{
	struct struct_info info[3];
	int i=0;
	int sum=0;
	float average=0;
	for(i=0;i<3;i++)
	{
		info[i]=input_struct_info(info[i]);
	}
	for(i=0;i<3;i++)
	{
		sum+=info[i].age;
	}
	average=sum/3.0;
	printf("average is:>%.2f\n",average);
	return 0;
}
struct struct_info input_struct_info(struct struct_info info)
{
	bzero(&info, sizeof(info));

	printf("input studen name:> ");
	scanf("%s", info.name);
	getchar();

	printf("input student number:> ");
	scanf("%d", &info.stu_num);
	getchar();


	printf("input student age:> ");
	scanf("%d", &info.age);
	getchar();

	return info;
}
