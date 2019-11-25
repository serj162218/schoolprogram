#include "libr.h"
int main(int argc,char** argv){
	float weight, height;
	int birthday[3];
	char choice;
	int a;
	float bmi;
	char sc;
	while(1){
		system("CLS");
		choice = display(argv[1]);
		if(choice == 'a'){
			birth(&birthday[0],&birthday[1],&birthday[2]);
			system("pause");
		}
		else if(choice == 'b'){
			puts("Enter your weight and height:");
			scanf("%f %f",&weight,&height);
			bmi = hw(weight,height);
			system("pause");
		}
		else if(choice == 'c'){
			 sc = score(&a);
			system("pause");
		}
		else if(choice == 'd'){
			pt(argv[1],birthday,sc,bmi);
		}
		else if(choice=='z'){
			return 0;
		}
	}
}