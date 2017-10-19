#ifndef SORT_H //Include guard
#define SORT_H

#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int>& v, vector<int>& p);
void quickSort(vector<int>& v, int low, int high, vector<int>& p);
void quickSort2(vector<int>& v, int low, int high, vector<int>& p);
int partition(vector<int>& v, int low, int high, vector<int>& p);
int sorted(vector<int>& v);
int revsorted(vector<int>& v, vector<int>& p);
void posarryint(vector<int>& p);

#endif