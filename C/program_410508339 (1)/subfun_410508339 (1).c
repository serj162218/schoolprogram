 char display(char *name)
{
	printf("%s,選擇一個選項\n(A)請輸入個人資料\n(B)請輸入成績資料\n(C)顯示成績結果\n(D)請先執行B\n(E)離開程式\n",name);
	char choice;
	scanf("%c", &choice);
	return choice;
}
void sort(float total[])
{
	char *myscore[4] = {"C語言", "java程式", "計概", "英文"};
	char *tmpscore;
	float tmptotal;
	int i = 0, j = 0;
	for(i=0; i<4; i++) {
		for(j=3; j>i; j--) {
			if(total[j] < total[j-1]) {
				tmpscore = myscore[j];
				myscore[j] = myscore[j-1];
				myscore[j-1] = tmpscore;
				tmptotal = total[j];
				total[j] = total[j-1];
				total[j-1] = tmptotal;
			}
		}
	}
	i = 0;
	for(i=0; i<4; i++) {
		printf("%s:%.2f ", myscore[i], total[i]);
	}
	printf("\n");
}

void printscore(float a, float b, float c, float d){
	if(a>=b && a>=c && a>=d) printf("C語言:%.2f ", a);
	else if(b>=a && b>=c && b>=d) printf("java程式:%.2f ", b);
	else if(c>=b && c>=a && c>=d) printf("計概:%.2f ", c);
	else if(d>=b && d>=c && d>=a) printf("英文:%.2f ", d);
	if(d<=b && d<=c && d<=a) printf("英文:%.2f\n", d);
	else if(a<=b && a<=c && a<=d) printf("C語言:%.2f\n", a);
	else if(b<=a && b<=c && b<=d) printf("java程式:%.2f\n", b);
	else if(c<=b && c<=a && c<=d) printf("計概:%.2f\n", c);
}

void fun_A(Person *std, char *name) 
{
	srand(time(NULL));
	printf("請選擇班級:\n(A)資工1A \n(B)資工1B \n(C)資工2A \n(D)資工2B \n(E)資工3A \n(F)資工3B \n(G)資工4A \n(H)資工4B\n");
	char choose;
	scanf("%s",&choose);
	char theclass[255];
	if(choose=='A'){
		strcpy(std->cname,"資工一A");
	}
	else if(choose=='B'){
		strcpy(std->cname,"資工一B");
	}
	else if(choose=='C'){
		strcpy(std->cname,"資工二A");
	}
	else if(choose=='D'){
		strcpy(std->cname,"資工二B");
	}
	else if(choose=='E'){
		strcpy(std->cname,"資工三A");
	}
	else if(choose=='F'){
		strcpy(std->cname,"資工三B");
	}
	else if(choose=='G'){
		strcpy(std->cname,"資工四A");
	}
	else if(choose=='H'){
		strcpy(std->cname,"資工四B");
	}
	
	std->stdid = 410000000+(rand()%1000000);
	printf("輸入身高及體重\n");
	scanf("%f %f", &std->height, &std->weight);
	printf("輸入電話號碼\n");
	scanf("%s", std->phone_number);
	printf("姓名:%s\n", name);
	printf("班級:%s\n", std->cname);
	printf("學號:%d\n", std->stdid);
	printf("身高:%.2f 體重:%.2f\n", std->height, std->weight);
	printf("電話:%s\n", std->phone_number);
	std->count=1;
	system("PAUSE");
}

int fun_B(Person *std)
{
	int thecount = 0;
	
	while(thecount != 4){
		printf("(1)C語言 (2)java程式 (3)計概 (4)英文\n");
		if(std->count != 1) {
			printf("尚未執行(A)");
			return 0;
		}
		int num;
		scanf("%d", &num);
		if(num > 4 || num < 1)
			continue;	
		std->snum.score[num-1][0] = rand()%100;	
		std->snum.score[num-1][1] = rand()%100;
		printf("輸入期末成績\n");
		scanf("%f", &std->snum.score[num-1][2]);
		std->snum.total[num-1] = std->snum.score[num-1][0]*0.3 + std->snum.score[num-1][1]*0.3 + std->snum.score[num-1][2]*0.4;
		thecount++;
	}
	
	printf("成績比例=平時:30%*期中:30%*期末:40% \n");
	printf("C語言: %.2f %.2f %.2f %.2f\n", std->snum.score[0][0], std->snum.score[0][1], std->snum.score[0][2], std->snum.total[0]);
	printf("java程式: %.2f %.2f %.2f %.2f\n", std->snum.score[1][0], std->snum.score[1][1], std->snum.score[1][2], std->snum.total[1]);
	printf("計概: %.2f %.2f %.2f %.2f\n", std->snum.score[2][0], std->snum.score[2][1], std->snum.score[2][2], std->snum.total[2]);
	printf("英文: %.2f %.2f %.2f %.2f\n", std->snum.score[3][0], std->snum.score[3][1], std->snum.score[3][2], std->snum.total[3]);
	std->count=2;
	system("PAUSE");
	
	return 0;
}

int fun_C(Person *std)
{
	if(std->count != 2) {
		printf("尚未執行B");
		return 0;
	}
	puts("各科總成績排序");
	sort(std->snum.total);
	puts("最高與最低期中成績:");
	printscore(std->snum.score[0][1], std->snum.score[1][1], std->snum.score[2][1], std->snum.score[3][1]);
	puts("最高與最低期末成績");
	printscore(std->snum.score[0][2], std->snum.score[1][2], std->snum.score[2][2], std->snum.score[3][2]);
	puts("最高與最低總成績");
	printscore(std->snum.total[0], std->snum.total[1], std->snum.total[2], std->snum.total[3]);
	system("PAUSE");
	return 0;
}

int fun_D(Person *std, char *my_name){
	if(std->count != 2) {
		printf("尚未執行B");
		return 0;
	}
	FILE *ftp = fopen("data.txt", "r");
	FILE *fp = fopen("myfriend_410508339.txt", "a");
	
	float bmi_range[2];
	float score_range[2];
	printf("輸入BMI交友範圍最小~最大\n");
	scanf("%f",&bmi_range[0]);
	scanf("%f",&bmi_range[1]);
	printf("輸入成績交友範圍最小~最大\n");
	scanf("%f",&score_range[0]);
	scanf("%f",&score_range[1]);
	if(ftp != NULL) {
		char name[6][255];
		char firname[6][255];
		char secname[6][255];
		char thiname[6][255];
		char minname[6][255];
		float fir=0;
		int i=0;
		float sec=0;
		float thi=0;
		float min=100;
		float c_total = 0;
		float j_total = 0;
		int allcount=0;
		int count=0;
		while(fscanf(ftp,"%s %s %s %s %s %s", name[0], name[1], name[2], name[3], name[4], name[5])!=EOF) {
			if(atof(name[3]) >= bmi_range[0] && atof(name[3]) <= bmi_range[1] && (atof(name[4]) + atof(name[5])) / 2 >= score_range[0] && (atof(name[4]) + atof(name[5])) / 2  <=score_range[1]) 
			{
				fprintf(fp, "%s %s %s %s %s %s\n",name[0], name[1], name[2], name[3], name[4],name[5]);
			}
			if((atof(name[4]) + atof(name[5])) / 2 > (std->snum.total[0]+std->snum.total[1])/2){
				count++;
			}
			if((atof(name[4]) + atof(name[5])) / 2  > fir){
				fir = (atof(name[4]) + atof(name[5])) / 2;
			for( i = 0;i<6;i++)
				strcpy(firname[i],name[i]);
			}
			else if((atof(name[4]) + atof(name[5])) / 2  > sec) {
				sec = (atof(name[4]) + atof(name[5])) / 2  ;
			for(i = 0;i<6;i++)
				strcpy(secname[i],name[i]);
			}
			else if((atof(name[4]) + atof(name[5])) / 2  > thi) {
				thi = (atof(name[4]) + atof(name[5])) / 2  ;
			for(i = 0;i<6;i++)
				strcpy(thiname[i],name[i]);
			}
			else if(min > (atof(name[4]) + atof(name[5])) / 2  ){
				min = (atof(name[4]) + atof(name[5])) / 2  ;
			for(i = 0;i<6;i++)
				strcpy(minname[i],name[i]);
}
			c_total += atof(name[4]);
			j_total += atof(name[5]);
			allcount++;
		}
		while(1){
		system("CLS");
		printf("%s,選擇一個選項\n(A)找出最高總平均與最低總平均的同學\n(B)全班\"C語言\"與\"Java語言\"的平均成績的總平均\n(C)比使用者%s兩科總平均成績大的同學數量\n(D)總平均最高前三位\n(E)離開程式\n",my_name,my_name);
		char thischoice;
		scanf("%s",&thischoice);
		if(thischoice == 'A'){
		printf("最高分:%.0f %s %s %s %s %s %s\n", fir,firname[0], firname[1], firname[2], firname[3], firname[4], firname[5]);
		printf("最低分:%.0f %s %s %s %s %s %s\n", min,minname[0], minname[1], minname[2], minname[3], minname[4], minname[5]);
		system("PAUSE");
		}
		else if(thischoice =='B'){
		printf("C語言平均:%.2f JAVA平均:%.2f\n", c_total / allcount, j_total / allcount);
		system("PAUSE");
		}
		else if(thischoice =='C'){
		printf("比%s成績高的人數為%d\n",my_name,count);
		system("PAUSE");
		}
		else if(thischoice =='D'){
		printf("第一名:%s %s %s %s %s %s\n", firname[0], firname[1], firname[2], firname[3], firname[4], firname[5]);
		printf("第二名:%s %s %s %s %s %s\n", secname[0], secname[1], secname[2], secname[3], secname[4], secname[5]);
		printf("第三名:%s %s %s %s %s %s\n", thiname[0], thiname[1], thiname[2], thiname[3], thiname[4], thiname[5]);
		system("PAUSE");
		}
		else if(thischoice == 'E')
			break;
		}
		fprintf(fp,"%s %ld %s %.2f %.2f %.2f\n", std->cname, std->stdid, my_name, std->weight / ((std->height/100)*(std->height/100)), std->snum.total[1], std->snum.total[2]);
	}
	fclose(ftp);
	system("PAUSE");
	return 0;
}

