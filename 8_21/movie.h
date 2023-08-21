#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dat
{
    int year;
    int mouth;
    int day;
};
typedef struct film
{
    char name[20];
    int ticket;
    struct dat dat;
    struct film *next;
} FILM;

FILM *input_info(FILM *head, int n);
void printf_info(FILM *head);
FILM* seek_film(FILM *head);
void highest_ticket(FILM *head);
FILM *delete_film(FILM *head);
void Seek_JUNE_Online(FILM *head);
FILM *input_end(FILM *head);

#endif