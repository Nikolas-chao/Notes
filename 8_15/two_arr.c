// 1、计算学生的成绩最大值，平均值
// 2、计算单科的最值，平均值
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stu_score(int (*arr)[3], int row, int col);
void subject_score(int (*arr)[3], int row, int col);
int main()
{
    int arr[3][3] = {0};
    int i = 0;
    int j = 0;
    srand(time(NULL));
    for (i = 0; i < 3;i++)
    {
        for (j = 0; j < 3;j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    stu_score(arr,3,3);
    subject_score(arr, 3, 3);

    return 0;
}

void stu_score(int (*arr)[3], int row, int col)
{
    printf("个人成绩的最值，平均值:\n");
    int max_row = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < row; i++)
    {
        max_row = (*arr)[j];
        int sum_row = 0;
        float average_row = 0;
        for (j = 0; j < col; j++)
        {

            max_row = max_row < arr[i][j] ? arr[i][j] : max_row;
            sum_row += arr[i][j];
        }
        average_row = sum_row / 3.0;
        printf("max_row:%d\t", max_row);
        printf("average:%.2f\n", average_row);
        printf("\n");
    }
}
void subject_score(int (*arr)[3], int row, int col)
{
    printf("单科的最值，平均值:\n");
    int max_col = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        max_col = (*arr)[0];
        int sum_col = 0;
        float average_col = 0;
        for (j = 0; j < 3; j++)
        {
            max_col = max_col < arr[j][i] ? arr[j][i] : max_col;
            sum_col += arr[j][i];
        }
        average_col = sum_col / 3.0;
        printf("max_col:%d\t", max_col);
        printf("average:%.2f\n", average_col);
        printf("\n");
    }
}

// 学生成绩最大值，平均值，--->行不变，列变
/*   printf("个人成绩的最值，平均值:\n");
   int max_row = 0;

   for (i = 0; i < 3; i++)
   {
       max_row = arr[0][0];
       int sum_row = 0;
       float average_row = 0;
       for (j = 0; j < 3; j++)
       {

           max_row = max_row < arr[i][j] ? arr[i][j] : max_row;
           sum_row += arr[i][j];
       }
       average_row = sum_row / 3.0;
       printf("max_row:%d\t", max_row);
       printf("average:%.2f\n", average_row);
       printf("\n");
   }


   // 单科的最值，平均值 -->行变，列不变
   printf("单科的最值，平均值:\n");
   int max_col = 0;

   for (i = 0; i < 3; i++)
   {
       max_col = arr[0][0];
       int sum_col = 0;
       float average_col = 0;
       for (j = 0; j < 3; j++)
       {
           max_col = max_col < arr[j][i] ? arr[j][i] : max_col;
           sum_col += arr[j][i];
       }
       average_col = sum_col / 3.0;
       printf("max_col:%d\t", max_col);
       printf("average:%.2f\n", average_col);
       printf("\n");
   }
*/
