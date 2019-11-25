/*
410508339 資工一B 楊立璿 
*/

#include <stdio.h>
int main(){
	puts("Enter your height(cm) and weight(kg)");
	float weight;
	float heightcm;
	scanf("%f %f",&heightcm,&weight);
	float bmi = weight/((heightcm/100)*(heightcm/100));
	printf("Your BMI is %.2f\n",bmi);
	//BMI
	int beauty,smart,sweet; // variable;
	int score = 0;
	int gentle; //gentle must be 0 or 1;
	puts("plz enter how beauty you are for score 1~5: ");
	scanf("%d",&beauty);
	puts("plz enter how sweet you are for score 1~5: ");
	scanf("%d",&sweet);
	puts("plz enter how smart you are for score 1~5: ");
	scanf("%d",&smart);
	puts("plz enter if you are gentle for 0 or 1: ");
	scanf("%d",&gentle);
	if(beauty>5||beauty<0||sweet>5||sweet<0||smart>5||smart<0||gentle>1||gentle<0){
		puts("Error!");
	return 0;}
	//+=score
	if(beauty>2){
		if(sweet>2&&gentle==1){
			score+=66;
		}
		else{
			score+=33;}
	}
	else{
		if(sweet>2&&gentle==1){
			score+=33;
		}
	}
	if(sweet<=2&&gentle==0){
		if(smart>=3){
			score+=33;
		}
	}
	else{
		if(smart>=3){
			score+=33;
		}
}
	//score
	if(score>=0&&score<=33){puts("you are not the one I want,sorry.\nscore:0~33\nPriority = 3");}
	else if(score>33&&score<=66){puts("You are great, but plz give me some times\nscore:33~66\nPriority = 2");}
	else if(score>66&&score<=100){puts("You are who I need!\nscore:66~100\nPriority:1");}
	else if(score>100){puts("Error!");}
	else{puts("Error!");}
	return 0;
}
