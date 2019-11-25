#include "410508339.h"
#include "subfun_410508339.c"
/*
	******已全部完成 楊立璿 資工一B 410508339 
*/
int main(int argc, char *argv[]) 
{
	char *name;
	if(argc == 2) {
		name = argv[1];
	}
	
	
	else {
		char thisname[4]="XXX";
		name = thisname;
	}
	
	Person std;
	int nope;
	while(1) {
		char choice = display(name);
		if(choice == 'A') {
			fun_A(&std, name);
		}
		else if(choice == 'B') {
			nope = fun_B(&std);
		}
		else if(choice == 'C') {
			nope = fun_C(&std);
		}
		else if(choice == 'D') {
			nope = fun_D(&std, name);
		}
		else if(choice == 'E') {
			break;
		}	
		system("CLS");
	}
	return 0;
} 
