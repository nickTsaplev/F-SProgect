/*
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif
*/

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::chrono::high_resolution_clock Clock;
#define nanosec std::chrono::duration_cast<std::chrono::nanoseconds>
using namespace std;
int n, m, maxm;
unsigned int i = 0;
int r = 0;
vector<int>in;
vector<int>toFind;

#include "find.h"
#include "bubble.h"



////////////////////////////////////////////////////////////

int place(vector<int> & a, int tf, int rd)
{
	int l = -1;
	int r = rd;
	int mid = 0;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (a[mid] <= tf)
			l = mid;
		else
			r = mid;
	}
	if (l != -1)
		if (abs(a[l] - tf) <= abs(a[r] - tf))
			return l;
		else
			return r;
	else
		return 0;

}

void Bsort(vector<int> * p2)
{

	for (int h = 0; h < 2; h++)
	{
		for (int i = 1; i < n; i++)
		{
			int buf = (*p2)[i];
			int buf2 = place(*p2, buf, i);
			for (int j = i - 1; j >= buf2; j--)
				(*p2)[j + 1] = (*p2)[j];
			(*p2)[buf2] = buf;
		}
	}

}

void Shsort(vector<int> * p2, int k)
{
	for (int h = n - 1; h > 0; h = h / k)
	{
		for (int h = 0; h < 2; h++)
		{
			for (int i = 1; i < n; i++)
			{
				int buf = (*p2)[i];
				int buf2 = place(*p2, buf, i);
				for (int j = i - 1; j >= buf2; j-=k)
					(*p2)[j + 1] = (*p2)[j];
				(*p2)[buf2] = buf;
			}
		}
	}
}

////////////////////////////////////////////////

int minSearch(vector<int> & p2)
{
	int min = p2[0];
	int minpos = 0;
	for (int i = 0; i < n; i++)
		if (p2[i] < min) {
			min = p2[i];
			minpos = i;
		}
	return minpos;
}

// select sort
void Vsort(vector<int> * p1, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		int minP = i;
		for (int j = i; j < n; j++)
		{
			if ((*p1)[j] < (*p1)[minP])
				minP = j;
		}
		int buf;
		buf = (*p1)[i];
		(*p1)[i] = (*p1)[minP];
		(*p1)[minP] = buf;
	}
}

/*void qsort(int* p1, int s)
{
	if (s > 1)
	{
		int m = p1[s / 2];
		//cout << m << " ";
		int* a = new int[s];
		int ac = 0;
		int* b = new int[s];
		int bc = 0;
		int* c = new int[s];
		int cc = 0;
		for (int i = 0; i < s; i++)
		{
			if (p1[i] < m)
			{
				a[ac] = p1[i];
				ac++;
				//cout << "A ";
			}
			else if (p1[i] > m)
			{
				b[bc] = p1[i];
				bc++;
				//cout << "B ";
			}
			else
			{
				c[cc] = p1[i];
				cc++;
				//cout << "C ";
			}
		}
		//cout << endl;
		if (ac > 1)
			qsort(a, ac);
		if (bc > 1)
			qsort(b, bc);
		for (int i = 0; i < ac; i++)
			p1[i] = a[i];
		for (int i = 0; i < cc; i++)
			p1[i + ac] = c[i];
		for (int i = 0; i < bc; i++)
			p1[i + ac + cc] = b[i];
		delete[] a;
		delete[] c;
		delete[] b;

	}

}*/

void qsort(int* p1, int s)
{
	if (s > 1)
	{
    
		int m = p1[s / 2];
		//cout << m << " ";
		int* a = p1;
		int ac = 0;
		int* b = p1;
		int bc = 0;
		//int* c = new int[s];
		int cc = 0;
		for (int i = 0; i < s; i++)
		{
			if (p1[i] < m)
			{
				//a[ac] = p1[i];
				ac++;
				cout << "A ";
			}
			else if (p1[i] > m)
			{
				//b[bc] = p1[i];
				bc++;
				cout << "B ";
			}
			else
			{
				//c[cc] = p1[i];
				cc++;
				cout << "C ";
			}
		}
     
    b=p1+ac+cc;
		for (int i = 0; i < ac+cc; i++)
		{
			if(p1[i]>m)
			{
				for(int j=s;j>ac+cc-1;j--)
        {
          if(p1[j]<=m)
          {
            swap(p1[i],p1[j]);
          }
        }
			}
		}
    for(int i = 0;i<ac;i++)
    {
      if(p1[i]==m)
      {
				
				for(int j=ac+cc-1;j>0;j--)
        {
          if(p1[j]<m)
          {
            swap(p1[i],p1[j]);
          }
        }
      }
    }

		cout << endl;
		if (ac > 1)
			qsort(a, ac);
		if (bc > 1)
			qsort(b, bc);
  

	}

}

inline int pr(int x)
{
	if (x % 2 == 1)
	{
		return (x - 1) / 2;
	}
	else
	{
		return x / 2;
	}
}


void siftUp(vector<int> & p, int s,int c)
{
	for(int i=c;p[pr(i)]<p[i];i=pr(i))
		swap(p[i],p[pr(i)]);
}
void Hsort(vector<int> & p, int s)
{
	if(s>1)
	{
		bool f = true;
		for(int i=0;i<s;i++)
			siftUp(p,s,i);
		swap(p[s - 1], p[0]);
		Hsort(p, s - 1);
    }
}

bool fo = false;

///////////////////////////////////////////////
inline void Co()
{
	if (fo) {
		for (int i = 0; i < n; i++)
			cout << in[i] << " ";
		cout << endl;
	}
}
int up=true; int a;int b;bool inFor;

#ifdef WIN
int _tmain(int argc, _TCHAR* argv[])
#else
int main()
#endif
{
	auto seed = time(0);
	auto start_time = Clock::now();
	auto stop_time = Clock::now();
	while (true) {
		if (fo)
			cout << "D$ ";
		else
			cout << "$ ";
		char ch1;
		char ch2;
		char ch3;
		cin >> ch1;

		if (ch1 == 'F' || ch1 == 'f')
		{
			cin >> ch2;
			if (ch2 == 'L' || ch2 == 'l')
			{
				cin >> ch3;
				if (ch3 == '0')
				{
					r = 0;
					start_time = Clock::now();

					for (int j = 0; j < m; j++)
						if (lineFind0(in, toFind[j]))
							r++;

					stop_time = Clock::now();
					cout << r << " L1 " <<
						(nanosec(stop_time - start_time).count()) / (double)
						1000000 << " ms" << endl;
				}
				else
				{
					r = 0;
					start_time = Clock::now();

					for (int j = 0; j < m; j++) {
						in[n] = toFind[j];

						if (lineFind1(in, toFind[j]))
							r++;
					}

					stop_time = Clock::now();
					cout << r << " L2 " <<
						(nanosec(stop_time - start_time).count()) / (double)
						1000000 << " ms" << endl;
				}
			}
			else
			{
				r = 0;
				start_time = Clock::now();

				for (int j = 0; j < m; j++) {
					if (binFind0(in, toFind[j]))
						r++;
				}

				stop_time = Clock::now();
				cout << r << " B1 " << (nanosec(stop_time - start_time).count())
					/ (double)1000000 << " ms" << endl;
			}

		}
		else if (ch1 == 'G' || ch1 == 'g')
		{
			cin >> n >> m >> maxm;
			auto seed = time(0);
			srand(seed);

			r = 0;
			auto start_time = Clock::now();

			in.reserve(n + 1);
			for (int j = 0; j < n; j++)
				in[j] = (rand() % maxm);
			in[n] = -1;

			auto stop_time = Clock::now();
			cout << r << " GEN " << (nanosec(stop_time - start_time).count()) /
				(double)1000000 << " ms" << endl;

			toFind.reserve(m);
			for (int j = 0; j < m; j++)
				toFind[j] = rand() % maxm;

		}
		else if (ch1 == 'S' || ch1 == 's')
		{
			cin >> ch2;
			if (ch2 == 'B' || ch2 == 'b')
			{
				cin >> ch3;
				if (ch3 == '0') {
					r = 0;
					start_time = Clock::now();

					wood_sort(&in);
					Co();

					stop_time = Clock::now();
					cout << r << " Bubble " <<
						(nanosec(stop_time - start_time).count()) / (double)
						1000000 << " ms" << endl;
				}
				else if (ch3 == 'S' || ch3 == 's')
				{


                    srand(seed);
						for (int j = 0; j < n; j++)
							in[j] = (rand() % maxm);
					r = 0;
					start_time = Clock::now();
					wood_sort2(&in);
					Co();
					stop_time = Clock::now();
					cout << r << " Shaker " <<
						(nanosec(stop_time - start_time).count()) / (double)
						1000000 << " ms" << endl;
				}
				else {
					srand(seed);
					for (int j = 0; j < n; j++)
						in[j] = (rand() % maxm);
					r = 0;
					start_time = Clock::now();

					wood_sort1(&in);
					Co();
					stop_time = Clock::now();
					cout << r << " Bubble min " <<
						(nanosec(stop_time - start_time).count()) / (double)
						1000000 << " ms" << endl;
				}
			}
			else if (ch2 == 'V' || ch2 == 'v')
			{
				srand(seed);
				for (int j = 0; j < n; j++)
					in[j] = (rand() % maxm);
				r = 0;
				start_time = Clock::now();
				Vsort(&in, n);
				Co();
				stop_time = Clock::now();
				cout << r << " Vsort " <<
					(nanosec(stop_time - start_time).count()) / (double)
					1000000 << " ms" << endl;
			}
			else if (ch2 == 'I' || ch2 == 'i')
			{
				srand(seed);
				for (int j = 0; j < n; j++)
					in[j] = (rand() % maxm);
				r = 0;
				start_time = Clock::now();
				Bsort(&in);
				Co();
				stop_time = Clock::now();
				cout << r << " Binary " <<
					(nanosec(stop_time - start_time).count()) / (double)
					1000000 << " ms" << endl;
			}
			else if (ch2 == 'S' || ch2 == 's')
			{
				int k = 0;
				cin >> k;
				srand(seed);
				for (int j = 0; j < n; j++)
					in[j] = (rand() % maxm);
				r = 0;
				start_time = Clock::now();
				Shsort(&in, k);
				Co();
				stop_time = Clock::now();
				cout << r << " Shell " <<
					(nanosec(stop_time - start_time).count()) / (double)
					1000000 << " ms" << endl;
			}
			else if (ch2 == 'Q' || ch2 == 'q')
			{
				cin>>ch3;
				if(ch3=='C' || ch3=='c')
                        up=!up;
				else
				{
				if(up)
					{
						srand(seed);
						for (int j = 0; j < n; j++)
							in[j] = (rand() % maxm);
					}else
					{
						srand(seed);
						for (int j = 0; j < n; j++)
							in[j] =4+(rand() %2);
					}

				r = 0;
				int* pp = new int[n];
				for (int i = 0; i < n; i++)
					pp[i] = in[i];

				start_time = Clock::now();
				qsort(pp, n);

				stop_time = Clock::now();

				for (int i = 0; i < n; i++)
					in[i] = pp[i];
				delete[]pp;
				Co();

				cout << r << " Qsort " <<
					(nanosec(stop_time - start_time).count()) / (double)
					1000000 << " ms" << endl;
                }
			}
			else if (ch2 == 'H' || ch2 == 'h')
			{
                 srand(seed);
				for (int j = 0; j < n; j++)
					in[j] = (rand() % maxm);
				r = 0;
				start_time = Clock::now();
				Hsort(in, n);
				Co();
				stop_time = Clock::now();

				cout << r << " Hsort " <<
					(nanosec(stop_time - start_time).count()) / (double)
					1000000 << " ms" << endl;
			}
		}
		else if (ch1 == 'D' || ch1 == 'd')
		{
			fo = !fo;
		}
		else if (ch1 == 'E' || ch1 == 'e')
			break;
		else if(ch1=='C' || ch1=='c')
            Co();
	}
	return 0;
}
