#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

class selection_sort
{
public:
	long int i, j, key, temp;
	int sort(long int n);
};



int selection_sort::sort(long int n)
{	
	long int A[n];
	//input
	ifstream inputfile;
	inputfile.open("insert_rdesc100000.txt");
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
		key = j;
		for(i=j+1;i<n;i++)
		{
			if(A[i]<A[key])
			{
				key = i;
			}
		}
		temp = A[j];
		A[j] = A[key];
		A[key] = temp;
	}
	end = clock();
	//output
	ofstream outputfile;
	outputfile.open("select_rd100000.txt");
	for(i=1;i<=n;i++)
	{
		outputfile << A[i] << "\n";
	}
	outputfile.close();
	//Sorting time
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ofstream sort_time;
	sort_time.open("sort_timed.txt", fstream::app);
	sort_time << "Selection sort time for "<< n << " inputs is " << setprecision(5) << time_spent << " sec \n";
	sort_time.close();
}

int main(void)
{
	long int number = 100000;
	selection_sort object;
	object.sort(number);
	return 0;
}
