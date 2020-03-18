/*
头文件
*/
#ifndef _STUDEN_H
#define _STUDEN_H
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<conio.h>
#define LEN sizeof(struct student)

/*
结构体
*/
struct student
{
	long num;
    	char name[100];
    	float s1;
    	float s2;
    	float s3;
    	float sum;
	int rank;
	struct student *next;
};

/*
函数声明
*/
struct student * create(); 
struct student * delname(struct student *head);
struct student * delnum(struct student *head);
void sort(struct student *head);
struct student * changename(struct student *head);
struct student * changenum(struct student *head);
void filein(struct student *head);
void locatename(struct student *head);
void locatenum(struct student *head);
void print(struct student *head);
void ABCD(struct student *head);
void max(struct student *head);
#endif

