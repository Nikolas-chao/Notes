#include "sys_log.h"

void printf_log(const char *file,const char *func,const int line)
{
    time_t tim;
    struct tm *p;
    time(&tim);
    p = localtime(&tim);

    FILE *fp = NULL;
    fp = fopen("./sys_log.txt", "a+");

    fprintf(fp, "%s\t%s\t%d\t%d年%d月%d日\t%d时%d分%d秒\t%s\n",
     file, func, line, 1900 + p->tm_year, 1 + p->tm_mon,
      p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec,strerror(errno));

    fclose(fp);
}