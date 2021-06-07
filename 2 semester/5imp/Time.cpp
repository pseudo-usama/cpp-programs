// Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "ctime"
using namespace std;



int main(int argc, _TCHAR* argv[]) {


	time_t timer;
	struct tm y2k = { 0 };
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));

	printf("%.f seconds since January 1, 2000 in the current timezone", seconds);


	time_t current_time;
	char* c_time_string;

	/* Obtain current time. */
	current_time = time(NULL);

	if (current_time == ((time_t)-1))
	{
		(void)fprintf(stderr, "Failure to obtain the current time.\n");
		exit(EXIT_FAILURE);
	}

	/* Convert to local time format. */
	c_time_string = ctime_s(&current_time);

	if (c_time_string == NULL)
	{
		(void)fprintf(stderr, "Failure to convert the current time.\n");
		exit(EXIT_FAILURE);
	}

	/* Print to stdout. ctime() has already added a terminating newline character. */
	(void)printf("Current time is %s", c_time_string);
	exit(EXIT_SUCCESS);

}




