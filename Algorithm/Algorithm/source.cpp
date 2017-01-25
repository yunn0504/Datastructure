/*bb*/
#include<stdio.h>

const int heapsize = 10;

void MaxHeapify(int[], int);
void BuildMaxHeap(int[]);
int Left(int);
int Right(int);
void PrintTree(int[]);
void swap(int &, int &);

int main(void)
{
	int data[heapsize + 1] = { 0, 8, 5, 2, 7, 10, 1, 9, 3, 6, 4 };
	PrintTree(data);
	BuildMaxHeap(data);
	PrintTree(data);
}

void MaxHeapify(int heap[], int i)
{
	int largest = 0;
	int l = Left(i);
	int r = Right(i);
	if (l <= heapsize && heap[l] > heap[i])
		largest = l;
	else
		largest = i;
	if (r <= heapsize && heap[r] > heap[largest])
		largest = r;
	printf("%d %d %d %d\n", largest, i, l, r);
	if (i != largest){
		swap(heap[largest], heap[i]);
		PrintTree(heap);
		MaxHeapify(heap, largest);
	}
	return;
}
void BuildMaxHeap(int heap[])
{
	int i;
	for (i = heapsize / 2; i >= 1; i--)
		MaxHeapify(heap, i);
}

int Left(int i)
{
	return i * 2;
}
int Right(int i)
{
	return i * 2 + 1;
}
void PrintTree(int heap[])
{
	int i = 1;
	int j = 1;
	while (i <= heapsize){
		printf("%3d", heap[i]);
		i++;
		if (i > j){
			printf("\n");
			j = j * 2 + 1;
		}
	}
	printf("\n");
}
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}