#include "sort.h"
using namespace std;


//function to sort an array using the insertion sort method
/*v[] --> Array to be sorted,
k  --> size of the arrays
p[] --> Postion array */
void insertionsort(int v[], double k, int p[])
{
	int i, j, key, pkey;
	int sort = 0;
	//guard against a non interger N value, rounds the value down to protect against out of range error
	int n = floor(k);
	//fill the postion array
	posarryint(p, n);

	//exit sort function if array size is less than 2 as an array of 1 is already sorted and to avoid 
	//starting sort with negative numbers
	if (n < 2)
	{
		cout << "Array cannot be sorted: size is less than 2\n";
		return;
	}

	//called sorted function to check if the array is already sorted, exit if it is
	sort = sorted(v, n);
	if (sort == 1) return;
	//call reverese sorted function to check if the array is reverse sorted, if it is the 
	//function will reverese the array values and the sort function will exit
	sort = revsorted(v, p, n);
	if (sort == 1) return;

	for (i = 1; i < n; i++)
	{
		key = v[i];
		pkey = p[i];

		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			p[j + 1] = p[j];
			j = j - 1;

		}
		v[j + 1] = key;
		p[j + 1] = pkey;

	}

	return;
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int v[], int low, int high, int p[])
{
	double pivot = v[high];    // pivot
	int i = (low - 1);  // Index of smaller element
	double temp, ptemp;

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (v[j] <= pivot)
		{
			i++;    // increment index of smaller element
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;

			ptemp = p[i];
			p[i] = p[j];
			p[j] = ptemp;

		}
	}

	temp = v[i + 1];
	v[i + 1] = v[high];
	v[high] = temp;

	ptemp = p[i + 1];
	p[i + 1] = p[high];
	p[high] = ptemp;

	return (i + 1);
}

/* The function that implements the C&P functions before performing QuickSort
v[] --> Array to be sorted,
p[] --> Postion array,
low  --> Starting index,
high  --> Ending index 
k  --> size of the arrays */
void quickSort(int v[], int low, int high, int p[], double k)
{
	//sort value to exit before sort is performed if the array is sorted or reverse sorted
	int sort = 0;
	//guard against a non interger N value, rounds the value down to protect against out of range error
	int n = floor(k);

	//fill the postion array
	posarryint(p, n);

	//exit sort function if array size is less than 2 as an array of 1 is already sorted and to avoid 
	//starting sort with negative numbers
	if (n < 2)
	{
		cout << "Array cannot be sorted: size is less than 2\n";
		return;
	}

	//called sorted function to check if the array is already sorted, exit if it is
	sort = sorted(v, n);
	if (sort == 1) return;
	//call reverese sorted function to check if the array is reverse sorted, if it is the 
	//function will reverese the array values and the sort function will exit
	sort = revsorted(v, p, n);
	if (sort == 1) return;

	//go to the quicksort
	quickSort2(v, low, high, p, n);

}

/*function to check if the array is already sorted to avoid running a redundent sort function
v[] --> Array to be sorted,
n--> size of the array */
int sorted(int v[], int n)
{
	//variable used to show if the array is sorted, set as sorted until proved otherwise
	int sorted = 1;

	for (int i = 0; i < n - 1; i++)
	{
		//check if the next value is bigger the current value
		//if it is then the array is not sorted 
		//so set i equal to n to exit the for loop and set sorted to 0;
		if (v[i] > v[i + 1])
		{
			i = n;
			sorted = 0;
		}
	}

	//display message if the array was already sorted
	if (sorted == 1)
	{
		cout << "The array is already sorted\n";
	}

	//return whether the array was sorted to the function that checked
	return sorted;
}

/*function to reverse the order of an array if it is already reverse sorted instead of performing a full sort
v[] --> Array to be sorted,
p[] --> Postion array,
n--> size of the arrays */
int revsorted(int v[], int p[], int n)
{
	//variable used to show if the array is reverse sorted, set as reverse sorted until proved otherwise
	int revsorted = 1;
	//half the value of n to reverse the array, rounded down to leave the central value
	//unchanged if the array is an odd length
	int k = floor(n / 2);
	int tempS, tempP;

	for (int i = 0; i < n - 1; i++)
	{
		//check if the next value is smaller the current value
		//if it is the the array is not reverese sorted 
		//so set i equal to n to exit the for loop and set sorted to 0;
		if (v[i] < v[i + 1])
		{
			i = n;
			revsorted = 0;
		}
	}

	//If the array is reverse sorted, reverse it and the postion array
	if (revsorted == 1)
	{
		cout << "The array was reverse sorted\n";
		for (int i = 0; i < k; i++)
		{
			//reverse the array
			tempS = v[i];
			v[i] = v[n - i - 1];
			v[n - i - 1] = tempS;

			//reverse the postiona array
			tempP = p[i];
			p[i] = p[n - i - 1];
			p[n - i - 1] = tempP;
		}
	}

	//return whether the array was reverse sorted to the function that checked
	return revsorted;
}

/*function to fill the postion array with incrementing numbers from 1 to n
p[] --> Postion array,
n--> size of the array */
void posarryint(int p[], int n)
{

	for (int i = 0; i < n; i++)
	{
		p[i] = i + 1;
	}

}

/* The function that performs the Quick Sort
v[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index,
p[] --> Postion array,
n  --> size of the arrays */
void quickSort2(int v[], int low, int high, int p[], int n)
{

	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(v, low, high, p);

		// Separately sort elements before
		// partition and after partition
		quickSort2(v, low, pi - 1, p, n);
		quickSort2(v, pi + 1, high, p, n);
	}
}