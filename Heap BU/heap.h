#ifndef H
#define H

#include<stdio.h>
#define max 200

void heapify(int*, int, int);
void readArray(int array[], int n);
void displayArray(int array[], int n);
void swap(int *x, int *y);
void heapify(int array[], int n, int pos);
void sort(int array[], int n);

#endif