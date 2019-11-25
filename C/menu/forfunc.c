#include "libr.h"
int birth(int *x,int *y,int *z){
	scanf("%d %d %d",x,y,z);
}
float hw(float x,float y){
	float bm;
	bm = x/pow(y/100,2);
	return bm;
}
char score(int *q){
	scanf("%d", q);
	if(*q<=100&&*q>=90)
		return (char)'A';
	else if(*q>=80)
		return (char)'B';
	else if(*q>=60)
		return (char)'C';
	else if(*q>=0)
		return (char)'D';
}
void pt(char *argv1,int *birthday,char a,float bmi){
		printf("%s's birthday is %d-%d-%d\n",argv1,birthday[0],birthday[1],birthday[2]);
		printf("%s's bmi is %.2f\n",argv1,bmi);
		printf("%s's score is %c\n",argv1,a);
		system("pause");
}
char display(char name[]){
	printf("(a)%s,請輸入你的生日\n",name);
	printf("(b)%s,請輸入你的身高體重\n",name);
	printf("(c)%s,請輸入你的C語言成績(請輸入分數0-100)\n",name);
	puts("(d)印出個人資料");
	puts("(z)按z離開此程式");
	puts("please choose a,b,c,d,z");
	char ch = getchar();
	return ch;
}
