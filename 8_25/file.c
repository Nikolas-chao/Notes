#include "file.h"

void write_file(int n)
{
    FILE *fp = NULL;
    int set = 0;

    stu *head = NULL;
    stu *end = head;
    end = input_info(n);
    output_info(end);

    fp = fopen("./student.dat", "w");


    end = end->next;

    for (int i = 0; i < n;i++)
    {   
        set = fwrite(end, sizeof(INFO), 1, fp);
        if(set!=1)
        {
            perror("fwrite");
            exit(-1);
        }
        end = end->next;
    }
    free_list(head);
    fclose(fp);
}

void read_file(int n)
{ 
    FILE *fp = NULL;
    int ret = 0;

    stu *head = malloc(sizeof(stu));
    memset(head, 0, sizeof(stu));

    stu *end = head;
    stu *node = NULL;

    fp = fopen("./student.dat", "r");
    if(fp==NULL)
    {
        perror("fopen");
        exit(-1);
    }

    printf("name\tage\tscore\n");
    
    for (int i = 0; i < n;i++)
    {   
        node = malloc(sizeof(stu));
        memset(node,0,sizeof(stu));
        ret = fread(node, sizeof(INFO), 1, fp);
        if(ret!=1)
        {
            perror("fread");
            exit(-1);
        }
        printf("%s\t%d\t%.1f\n", node->info.name, node->info.age, node->info.score);

        end->next = node;
        end = end->next;
    }
    
    end = NULL;
    free_list(head);
    fclose(fp);
}
