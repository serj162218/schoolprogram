#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct {
	float total[4];
	float score[4][3];
} Score;
typedef struct {
	long int stdid;
	float weight, height;
	char phone_number[255];
	char cname[255];
	int count;
	Score snum;
} Person;
 
