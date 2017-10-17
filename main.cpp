#include "vector.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void insertionsort(Vector& v, Vector& p);
void quickSort(Vector &arr, int low, int high, Vector &p);
int partition(Vector &arr, int low, int high, Vector &p);
void output(Vector &arr, const string state, const string file);


int main()
{

	int low, high, n=1;
	bool check = false;
	string name, fname;
	
	while (check == false)
	{
		check = true;
		//ask for number of elements to be sorted
		cout << "Enter array size: ";
		
		//loop until the user provides a value
		while (!(cin >> n))
		{
			cout << "Error: Input must be an interger\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter array size: ";
		}

		//IF the entered value is less than 2 request new value
		if (n < 2)
		{
			check = false;
			cout << "Error: Array size must be greater than 1\n";
		}
		//clear cin to remove any extra inputs
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	


	//define vectors to hold values and orignal postions
	Vector arrayS(n), arrayP(n), create(n);
	
	//ask for name of file to be sorted
	cout << "Enter file name: ";
	cin >> name;
	fname = name + ".dat";

	ifstream file1("vector.dat");

	//import vector data into create array
	for (int i = 0; i < n; i++)
	{
		file1 >> create[i];
	}

	ofstream of(fname, ofstream::out);
	for (int i = 0; i < n; i++)
	{
		of << create[i] << "\n";
	}


	of.close();
		
	low = 0;
	high = n-1;
	

	ifstream file2(fname);

	//import data into the value array
	for (int i = 0; i < n; i++)
	{
		file2 >> arrayS[i];
	}
	
	//fill orignal postion array with incremneting values from 1 to n
	for (int i = 0; i < n; i++)
	{
		arrayP[i] = i + 1;
	}
	
	//output original list
	output(arrayS, "original", name);

	//for use the insertion sort if array is less than 10 else use quicksort
	if (arrayS.getSize() < 10)
	{
		cout << "Insertion sort used\n";
		cout << "Insertion sort start\n";
		insertionsort(arrayS, arrayP);
		cout << "Insertion sort end\n";
	}
	else
	{
		cout << "Quick sort used\n";
		cout << "Quick sort start\n";
		quickSort(arrayS, low, high, arrayP);
		cout << "Quick sort end\n";
	}
	
	//output sorted list
	output(arrayS, "sorted", name);
	//output orignal postions
	output(arrayP, "position", name);
		
	return 0;
}


void insertionsort(Vector& v, Vector& p)
{
	int i, j;
	double key, pkey;
	

	for (i = 1; i < v.getSize(); i++)
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
int partition(Vector &arr, int low, int high, Vector &p)
{
	double pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element
	double temp, ptemp;

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			ptemp = p[i];
			p[i] = p[j];
			p[j] = ptemp;
			
		}
	}
	
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	ptemp = p[i + 1];
	p[i + 1] = p[high];
	p[high] = ptemp;

	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(Vector &arr, int low, int high, Vector &p)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high, p);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1, p);
		quickSort(arr, pi + 1, high, p);
	}
}

//the function which stores a vector in a file
void output(Vector &arr, const string state, const string file)
{
	int n = arr.getSize();
	string oname;
	
	oname = file + "-" + state + ".txt";

	ofstream ofs(oname, ofstream::out);
	for (int i = 0; i < n; i++)
	{
		ofs << arr[i] << "\n";
	}


	ofs.close();

}