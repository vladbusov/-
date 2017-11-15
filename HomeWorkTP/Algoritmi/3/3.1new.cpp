int Input(int** A, int* sizeA, int** B, int* sizeB)
{
	int size[2];
	int* IntMas[2];
	cin >> sizeA >> sizeB ;
	for(int j = 0; j < 2; ++j)
	{
		IntMas[j] = new ;
		if (IntMas[j] == NULL)
			return 0;
		int i;
		for(i = 0; i < size[j]; ++i)
		{
			if(scanf("%d", &(IntMas[j][i])) != 1)
			{
				free(IntMas[j]);
				return 0;
			}
		}
	}
	*A = IntMas[0];
	*B = IntMas[1];
	*sizeA = size[0];
	*sizeB = size[1];
	return 1;
}


//Search of limits for binary search
void SearchLimit(int* IntMas, int size, int Num, int* min, int* max)
{
	int i = 0;
	while(IntMas[1 << i] < Num && (1 << i) < size) 
	{
		i++;
	}
	*min = (i == 0) ? 0 : 1 << (i - 1);
	*max = ((1 << i) < size)? 1 << i : size;
}

int BinarySearch(int* IntMas, int left, int right, int num)
{
	int first = left;
	int last = right;
	int mid;
	while( first < last ) 
	{
		mid = (first + last) / 2;
		if(num <= IntMas[mid])
			last = mid;
		else
			first = mid + 1;
	}
	return num <= IntMas[last] ? last : right;
}

int main()
{
	//Getting the size of queuqe and crossout-number
	int *A, *B, sizeA, sizeB;
	if(Input(&A, &sizeA, &B, &sizeB) == 0)
		return 0;

	int i, IndexMin, IndexMax;
	for(i = 0; i < sizeB; i++)
	{
		IndexMin = 0; // минимум
		IndexMax = sizeA; // максимум
		SearchLimit(A, sizeA, B[i], &IndexMin, &IndexMax);
		printf("%d ",BinarySearch(A, IndexMin, IndexMax, B[i]));
	}
	free(A);
	free(B);
	return 0;
}