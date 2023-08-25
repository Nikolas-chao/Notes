#include "file.h"

void write_file(int n)
{
    FILE *fp = NULL;
    int set = 0;

    stu *head_stu = NULL;

    head_stu = input_info(n);

    output_info(head_stu);

    fp = fopen("./student.dat", "w");


    head_stu = head_stu->next;

    for (int i = 0; i < n;i++)
    {   
        set = fwrite(head_stu, sizeof(INFO), 1, fp);
        if(set!=1)
        {
            perror("fwrite");
            exit(-1);
        }
        head_stu = head_stu->next;
    }
    free_list(head_stu);
    fclose(fp);
}

void read_file(int n)
{
    
    FILE *fp = NULL;
    int ret = 0;

    stu *head = malloc(sizeof(INFO));
    memset(head, 0, sizeof(INFO));
    stu *end = head;


    fp = fopen("./student.dat", "r");
    if(fp==NULL)
    {
        perror("fopen");
        exit(-1);
    }

    printf("name\tage\tscore\n");
    
    for (int i = 0; i < n;i++)
    {   
        ret = fread(end, sizeof(INFO), 1, fp);
        if(ret!=1)
        {
            perror("fread");
            exit(-1);
        }
        printf("%s\t%d\t%.1f\n", end->info.name, end->info.age, end->info.score);
        stu *node = malloc(sizeof(stu));
        memset(node,0,sizeof(stu));
        end->next = node;
        end = end->next;
    }
    end->next = NULL;
    free_list(head);

    fclose(fp);
}
