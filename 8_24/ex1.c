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
	int n = strlen(str);
	fp = fopen("D:/github/Notes/8_24/info.txt", "r+");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}

	set = fputs(str,fp);
	if(set == EOF)
	{
		perror("fputs");
		exit(-1);
	}
	rewind(fp);
	fgets(res,n+1,fp);
//	printf("%s\n",res);

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
