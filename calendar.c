#include <stdio.h>
#include <time.h>
#include <math.h>

int calcDayOfWeek(int month, int year){
	int dayOfWeek, yearOfCentury = (year+1900)%100;
	float century = year/100; 

	if(month == 1){
		month = 13;
	}
	else if (month == 2){
		month = 14;
	}
	
	dayOfWeek = 1 + floor((13*(month+1))/5) + yearOfCentury + floor(yearOfCentury/4) + floor(century/4) - 2 * century;
	dayOfWeek = dayOfWeek%7;
	return dayOfWeek;
}

int main(void) {

	int dayOfWeek, days, i, j;
	char *monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int monDay[12] = {30, 28, 30, 31, 30, 31, 30, 30, 31, 30, 31, 30};

	time_t t = time(NULL);
	struct tm tm = *localtime(&t); 

	dayOfWeek = calcDayOfWeek(tm.tm_mon+1, tm.tm_year);
	days = ((tm.tm_year % 400 == 0 || tm.tm_year % 100 == 0 || tm.tm_year % 4 == 0) && tm.tm_mon + 1 == 2) ? 29 : monDay[tm.tm_mon];

//	printf("%d\n", dayOfWeek);
	printf("\n\n\t  %d\n", tm.tm_year+1900);	
	printf("\t%s\n\n", monthName[tm.tm_mon]);

	printf(" Su  M  T  W Th  F Sa\n");

	for (i = 1; i <= dayOfWeek; i++){
		printf("   ");
	}

	for (j = 1; j <= days; j++, i++){	


		if(j == tm.tm_mday){
			printf(" \033[96m\033[7m%2d\033[0m", j);
		}
		else printf("%3d", j);

		if (i % 7 == 0){ 
			printf("\n");	
		}

		
	}

	printf("\n\n\n");
	return 0;

}
