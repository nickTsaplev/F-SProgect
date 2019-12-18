bool lineFind0(vector<int> & p1, int tf)
{
	for (i = 0; i < p1.size(); i++)
		if (p1[i] == tf)
			break;
	return (p1[i] == tf);
}

bool lineFind1(vector<int> & p1, int tf)
{
	for (i = 0; p1[i] != tf; i++);
	return !(i == n);
}

bool binFind0(vector<int> & p1, int tf)
{
	int l = -1;
	int r =  p1.size();
	int mid = 0;
	while (r - l > 1) {
		mid = (l + r) / 2;
		if (p1[mid] <= tf)
			l = mid;
		else
			r = mid;
	}
	return (l != -1 && p1[l] == tf);
}
