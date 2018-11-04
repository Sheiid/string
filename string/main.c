/*
 * main.c
 *
 *  Created on: Nov 4, 2018
 *      Author: sheida
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM1 8
#define DIM2 4
int search_subString(char s1[], char s2[], int);

int main() {

	char s1[DIM1] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
//	int i;
	char s2[DIM2] = { 'c', 'd', 'e' };
	char s3[DIM2] = { '#', '#', '#' };
	char out[DIM1 * DIM2];

	int i, index, from, to;
	int flag;
	printf("s1:");
	for (i = 0; i < strlen(s1); i++) {
		printf("%c ", s1[i]);
	}
	printf("\n");
	printf("s2:");
	for (i = 0; i < strlen(s2); i++) {
		printf("%c ", s2[i]);
	}
	printf("\n");
	printf("s3:");
	for (i = 0; i < strlen(s1); i++) {
		printf("%c ", s3[i]);
	}
	printf("\n");
	flag = 0;
	from = index = 0;
	printf("processing...\n");
	do {
		printf("the search start at the index %d in vector s1\n",from);
		to = search_subString(s1, s2, from);

		printf("--- similarity found in s1 is :%d \n",to);
		if (to < 0) {
			//it means there was no match between s1 and s2;
			printf("there is no similarity out of the loop\n");
			to = strlen(s1);
			flag = 1;
		}

		//if there was match try to creat output
		for (i = from; i < to; i++) {
			out[index] = s1[i];
			index++;
		}
		if (flag == 0) {
			for (i = 0; i < strlen(s3); i++) {
				out[index] = s3[i];
				index++;

			}

		}

		printf("+++++++++ increasing the index from in vector s1\n");
		from = to + strlen(s2);

	} while (flag == 0);

	out[index] = '\0';

	printf("output:\n");
	for (i = 0; i < index; i++) {
		printf(" %c ", out[i]);
	}
	return 0;

}
int search_subString(char s1[], char s2[], int from) {

	int i, j;
	int flag;
	i = from;
	printf("from = %d in vector s1:\n",i);
	for (i = from; i < strlen(s1) - strlen(s2); i++) {
		flag = 0;
		for (j = 0; j < strlen(s2) && flag == 0; j++) {
			printf("\t \t \t \t s1: %c \t \t \ts2: %c \t \t flag:%d\n",s1[i+j],s2[j],flag);
			if (s1[i + j] != s2[j]) {
				flag = 1;
				printf("\t \t \t \t s1: %c \t \t \ts2: %c \t \t flag:%d\n",s1[i+j],s2[j],flag);
				printf("they are not equal\n");

			}
		}
		if (flag == 0) {
			printf("now I know the start index of overlapping s1 and s2:%d :\n",i);
			return i;
		}

	}
	return -1;
}
