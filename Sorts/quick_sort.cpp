#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

class data
{
long int A[1000 + 1];
long int i, j;
public:

	void input(long int n);
	void quick_sort(int p, int r);
	int partition(int p, int r);
	void output(long int n);
};

void data::input(long int n)
{
	//input
	ifstream inputfile;
	inputfile.open("r1000.txt");
	for(i=1;i<=n;i++)
	{		
		inputfile >> A[i];
	}
	inputfile.close();
}

void data::quick_sort(int p, int r)
{
	
	if(p<r)
	{
		int q = partition(p,r);
		quick_sort(p,q-1);
		quick_sort(q+1,r);
	}

}

int data::partition(int p,int r)
{
	int x = A[p];
	while(p<r)
	{
		while(A[p] < x)
		{
			p++;
		}
		while(A[r] > x)
		{
			r--;
		}
		if(A[p] == A[r])
		{
			p++;
		}
		else if(p<r)
		{
			int temp = A[p];
			A[p] = A[r];
			A[r] = temp;
		}
	}
	return r;
}

void data::output(long int n)
{
	//output
	ofstream outputfile;
	outputfile.open("outputr1000.txt");
	for(i=1;i<=n;i++)
	{
		outputfile << A[i] << "\n";
	}
	outputfile.close();
}

int main(void)
{
	long int number = 1000;
	data object;
	object.input(number);
	//sorting time
	clock_t begin, end;
	double time_spent;
	//sort
	object.quick_sort(0, number);
	end = clock();
	//Sorting time
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ofstream sort_time;
	sort_time.open("sort_time.txt", fstream::app);
	sort_time << "merge sort time for "<< number << " inputs is " << setprecision(5) << time_spent << " sec \n";
	sort_time.close();		
	object.output(number);
	return 0;
}
