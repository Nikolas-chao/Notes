/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: ex2.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月24日 星期四 16时36分21秒
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	FILE *fp = NULL;
	FILE *cp = NULL;
	fp = fopen("./info.txt","r");
	cp = fopen("./info1.txt","w");
	char ch = 0;
	
	ch = fgetc(fp);
	while(ch!=EOF)
	{
		fputc(ch,cp);
		ch =fgetc(fp);
	}

	fclose(fp);
	fclose(cp);

    return 0;
}
