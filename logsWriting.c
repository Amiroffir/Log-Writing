#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable : 4996)
	
void LogError(char message[100]);
void LogEvent(char message[100]);
void log(char message[1000]);


int main() {
	
	LogEvent("Start running\n");
	printf("Please enter a num: ");
	char userInput[1000];
	scanf("%s", &userInput);
	strcat(userInput, " - input number entered by the user\n");
	LogEvent(userInput);
	FILE* f = fopen("numbers.txt", "w");
	if (f == NULL) {
		LogError("\nFile open is failed");
	}
	else {
		LogEvent("File opened succsessfully\n");
		char put[1000];
		for (int i = 1; i <= atoi(userInput); i++) {
			sprintf(put, "%d\n", i);
			fputs(put, f);
		}
	}
	LogEvent("End\n");
}


void log(char message[1000]) {
	// time stamps for the log file
time_t t;
time(&t);
char strTime[100];
struct tm* timeinfo;
timeinfo = localtime(&t);

 sprintf(strTime, "%d:%d:%d - %s", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
	FILE* f = fopen("log.log", "a");
	fputs(strTime, f);
	fclose(f);
}
// log error function
void LogError(char message[100]) {
	char Error[100] = "Error - ";
	strcat(Error,message);
	log(Error);
}
// log event function
void LogEvent(char message[100]) {
	char event[100] = "Event - ";
	strcat(event,message);
	log(event);
}

