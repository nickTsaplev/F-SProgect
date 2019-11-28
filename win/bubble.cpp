void wood_sort(vector<int> * p1)
{
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n - a - 1; b++)
			if ((*p1)[b] > (*p1)[b + 1])
				swap((*p1)[b], (*p1)[b + 1]);
}

void wood_sort1(vector<int> * p1)
{
	int minP = 0;
	int n1 = n;
	for (int a = 0; a < n1; a++)
	{
		minP = a;
		for (int b = a; b < n - a - 1; b++)
		{
			if ((*p1)[b] > (*p1)[b + 1])
				swap((*p1)[b], (*p1)[b + 1]);
			if ((*p1)[b] < (*p1)[minP])
				minP = b;
		}
		n1--;
		swap((*p1)[a], (*p1)[minP]);
	}
}

void wood_sort2(vector<int> * p1)
{
	for (int a = 0; a < n / 2; a++)
	{
		for (int b = a; b < n - a - 1; b++)
			if ((*p1)[b] > (*p1)[b + 1])
				swap((*p1)[b], (*p1)[b + 1]);
		for (int b = n - a - 1; b > a; b--)
			if ((*p1)[b] < (*p1)[b - 1])
				swap((*p1)[b], (*p1)[b - 1]);
	}
}