#include <stdio.h>

int main(){
	puts("please enter your height and weight: ");
	float weight;
	float heightcm;
	scanf("%f %f",&heightcm,&weight);
	float heightm = heightcm/100;
	char name[]="·¨¥ßÂ{";
	char  stuid[] = "410508339";
	int age = 20;
	
	int a, b, c;
	puts("please enter your three subject scores: ");
	scanf("%d %d %d",&a,&b,&c);
	float bmi = weight/(heightm*heightm);
	int i = 0;
	int j = 0;
	printf("Your name is:");
	while (i < 3){
		printf("%c",name[i]);
		i++;
	}
	puts(" ");
		printf("Your studentID is:");
	while(j <= 8){
		printf("%c",stuid[j]);
		j++;
	}
	puts("");
	printf("Your age is %d\nYour BMI is %f\nYour three subject scores are %d %d %d",age,bmi,a,b,c);
}
