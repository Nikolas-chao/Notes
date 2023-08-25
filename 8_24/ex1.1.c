/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: ex1.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月24日 星期四 11时02分27秒
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	FILE *fp = NULL;
	int set = 0 ;
	char str[20]={"hello world"};
	char res[20]={0};
	int i = 0;
	char ch = 0;
	int n = strlen(str);
    fp = fopen("/home/qwe/sixClass/homework/8_24/info.txt","r+");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(str[i]!='\0')
	{
		set = fputc(str[i],fp);
	if(set == EOF)
	{
		perror("fputs");
		exit(-1);
	}
	i++;
	}
//从文本文件读取字符，存到res数组中
	int j = 0;
	rewind(fp);
	ch=fgetc(fp);
	while(ch!=EOF)
	{	
		//	printf("%c",ch);
		res[j] = ch;	
	   	ch = fgetc(fp);		
		j++;
	}
	res[j] = '\0';
	//	fgets(res,n+1,fp);
	//		printf("%s\n",res);

	// 逆序输入 
	rewind(fp);	
	for(i=n-1;i>=0;i--)
	{
		set=fputc(res[i],fp);
		if(set==EOF)
		{
			perror("fputc");
			exit(-1);
		}
	}

	fclose(fp);
    return 0;
}
