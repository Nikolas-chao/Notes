#include "system.h"

void system_student_score(student *head)
{
    int input = 0;
    char name[10] = {0};
    float max = 0;
    do
    {
        menu();
        printf("input your choose:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            if(head==NULL)
            {
                head = create_list();
                break;
            }
            else
            {
                 insert_tail(head);
                 break;
            }     
            case 2:
                output(head);
                break;
            case 3:
                printf("input delect name:>");
                scanf("%s",name);
                delete_node(head, name);
                break;
            case 4:
                printf("input revise name:>");
                scanf("%s", name);
                revise_info(head, name);
                break;
            case 5:
                printf("input seek max score:>");
                scanf("%s", name);
                max = seek_max_score(head, name);
                printf("max score is:>%.2f", max);
                break;
            case 0:
                list_free(head);
                printf("Successful exit!\n");
                break;
            default:
                printf("The selection is invalid!\n");
                break;
        }
    } while (input);  
}

