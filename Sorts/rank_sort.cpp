#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

class rank_sort
{
public:
	long int i, j, key, temp;
	int sort(long int n);
};



int rank_sort::sort(long int n)
{	
	long int A[n], R[n], U[n];
	//input
	ifstream inputfile;
	inputfile.open("rank_rdesc50000.txt");
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
		R[j] = 1;
	}
	for(j=2;j<=n;j++)
	{
		for(i=1;i<=j-1;i++)
		{
			if(A[i]<=A[j])
			{
				R[j]=R[j]+1;
			}
			else
			{
				R[i]=R[i]+1;
			}
		}
	}
	
	for(j=1;j<=n;j++)
	{
		U[R[j]] = A[j];
	}
	for(j=1;j<=n;j++)
	{
		A[j] = U[j];
	}
	end = clock();
	//output
	ofstream outputfile;
	outputfile.open("rank_rd50000.txt");
	for(i=1;i<=n;i++)
	{
		outputfile << A[i] << "\n";
	}
	outputfile.close();
	//Sorting time
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ofstream sort_time;
	sort_time.open("sort_timed.txt", fstream::app);
	sort_time << "Rank sort time for "<< n << " inputs is " << setprecision(5) << time_spent << " sec \n";
	sort_time.close();
}

int main(void)
{
	long int number = 50000;
	rank_sort object;
	object.sort(number);
	return 0;
}
