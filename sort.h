#ifndef SORT_H //Include guard
#define SORT_H

#include <iostream>

void insertionsort(int v[], double k, int p[]);
void quickSort(int v[], int low, int high, int p[], double k);
void quickSort2(int v[], int low, int high, int p[], int n);
int partition(int v[], int low, int high, int p[]);
int sorted(int v[], int n);
int revsorted(int v[], int p[], int n);
void posarryint(int p[], int n);

#endif