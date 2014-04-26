#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
using namespace std;

class data
{
long int A[1000 + 1];
long int i, j, key, k;
public:

	void input(long int n);
	void merge_sort(int p, int r);
	void merge(int p, int q, int r);
	void output(long int n);
};

void data::input(long int n)
{
	//input
	ifstream inputfile;
	inputfile.open("rs1000.txt");
	for(i=1;i<=n;i++)
	{		
		inputfile >> A[i];
	}
	inputfile.close();
}

void data::merge_sort(int p, int r)
{
	
	if(p<r)
	{
		int q = (p+r)/2;
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}

}

void data::merge(int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1],R[n2+1];
	L[n1]=1234567890;
	R[n2]=1234567890;
	for(i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j] = A[q+j+1];
	}
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
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
	object.merge_sort(0, number);
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
