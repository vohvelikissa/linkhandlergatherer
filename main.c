#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int args, char * argv[]) {
	if (args >= 2) {
		char toBeExecuted[1024] = "w3m \"duckduckgo.com/?q=\"";
		strcat(toBeExecuted, argv[1]);
		strcat(toBeExecuted, " | grep \"www.\" > changethis.txt");
		system(toBeExecuted);
		system("sed -i 's/\\swww.//g' changethis.txt");
		system("cat changethis.txt | awk '{$1=$1;print}'");
		system("wget --tries=1 $(cat changethis.txt)");
	} else {
		printf("INSERT A SEARCH TERM");
	}
}
