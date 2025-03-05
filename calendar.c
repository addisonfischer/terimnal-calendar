#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

void centerTxt(char *txt){
	printf("%*s%*s\n", (int)floor(10+strlen(txt)/2),txt,(int)floor(10-strlen(txt)/2),"");	
}

int getDayOfWeek(struct tm tm, int month)
{
	tm.tm_mon = month;
	tm.tm_mday = 1;
	mktime(&tm);
	return tm.tm_wday;
}

void printCalendar(struct tm tm, char *monthName[], int monDay[])
{
	int i, j, dayOfWeek, days, month = tm.tm_mon, year = tm.tm_year+1900;


	for (int k = -1; k < 2; k++){

		dayOfWeek = getDayOfWeek(tm, month+k);

		monthName = &monthName[month+k];	
		days = monDay[month+k];


		printf("\n\n\t%d\n", year);
		centerTxt(*monthName);
		printf(" Su  M  T  W Th  F Sa\n");

		for (i = 1; i <= dayOfWeek; i++){
			printf("   ");
		}

		for (j = 1; j <= days; j++, i++){	


			if(j == tm.tm_mday && month+k == tm.tm_mon){
				printf(" \033[96m\033[7m%2d\033[0m", j);
			}
			else printf("%3d", j);

			if (i % 7 == 0){ 
				printf("\n");	
			}


		}
		printf("\n\n");
	} 
}
int main(void) {

	int i, j;
	char *monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int monDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	time_t t = time(NULL);
	struct tm tm = *localtime(&t); 

//	printf("%d\n", dayOfWeek);

	printCalendar(tm, monthName, monDay);

	printf("\n\n\n");
	return 0;

}
