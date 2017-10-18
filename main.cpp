#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "sort.h"


using namespace std;

//output test results
void output(int o[], int s[], int p[], int n);
//sorted array with 10 values
void testcase1a3();
//reverse sorted array with 10 values
void testcase1a4();

int main()
{

	testcase1a3();
	testcase1a4();
	return 0;
	
}


void testcase1a3()
{

	cout << "\n-----------------------------------------------------------------------------------\n";
	cout << "Test Case 1a3: Insertion sort of an array with sorted values form 1 to 10\n";
	cout << "-----------------------------------------------------------------------------------\n\n";

	int arrayO [10], arrayS[10], arrayP[10];

	//fill the array with sorted values 1 to 10
	for (int i = 0; i < 10; i++)
	{
		arrayO[i] = i + 1;
	}

	//copy values from original array to the sort array to keep original order
	for (int i = 0; i < 10; i++)
	{
		arrayS[i] = arrayO[i];
	}

	//run insertion sort on array
	insertionsort(arrayS, 10, arrayP);
	//output results
	output(arrayO, arrayS, arrayP, 10);

}


void testcase1a4()
{

	cout << "\n-----------------------------------------------------------------------------------\n";
	cout << "Test Case 1a4: Insertion sort of an array with reverse sorted values form 10 to 1\n";
	cout << "-----------------------------------------------------------------------------------\n\n";

	int arrayO[10], arrayS[10], arrayP[10];

	//fill the array with reverse sorted values 10 to 1
	for (int i = 0; i < 10; i++)
	{
		arrayO[i] = 10 - i;
	}

	//copy values from original array to the sort array to keep original order
	for (int i = 0; i < 10; i++)
	{
		arrayS[i] = arrayO[i];
	}

	//run insertion sort on array
	insertionsort(arrayS, 10, arrayP);
	//output results
	output(arrayO, arrayS, arrayP, 10);



}

void output(int o[], int s[], int p[], int n)
{

	cout << "Results: \tOrignal\t|\tsorted\t|\tpostion \n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t" << o[i] << "\t|\t" << s[i] << "\t|\t" << p[i] << "\n";
	}

}