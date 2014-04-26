#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

class insertion_sort
{
public:
	long int i, j, key;
	int sort(long int n);
};



int insertion_sort::sort(long int n)
{	
	long int A[n];
	//input
	ifstream inputfile;
	inputfile.open("insert_rdesc500.txt");
	for(i=1;i<=n;i++)
	{		
		inputfile >> A[i];
	}
	inputfile.close();
	//sorting time
	clock_t begin, end;
	double time_spent;
	//sort
	begin = clock();
	for(j=1;j<=n;j++)
	{
		key = A[j];
		i = j-1;
		while(i>0 && A[i]>key)
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
	end = clock();
	//output
	ofstream outputfile;
	outputfile.open("insert_rd500.txt");
	for(i=1;i<=n;i++)
	{
		outputfile << A[i] << "\n";
	}
	outputfile.close();
	//Sorting time
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ofstream sort_time;
	sort_time.open("sort_timed.txt", fstream::app);
	sort_time << "Insertion sort time for "<< n << " inputs is " << setprecision(5) << time_spent << " sec \n";
	sort_time.close();
}

int main(void)
{
	long int number = 500;
	insertion_sort object;
	object.sort(number);
	return 0;
}
