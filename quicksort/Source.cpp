#include <iostream>

using namespace std;

class intComp
{
public:
	static bool prior(int num1, int num2) { return num1 < num2; }
};

template <typename E>
void swap(E A[], int index1, int index2)
{
	E temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}

//Quick sort using last element as partition

template <typename E, typename Comp>
void quicksort(E A[], int low, int high)
//inputs: array of values to sort, starting index, ending index
//outputs: array will be sorted in order based on the comparator that is used (Comp)
{

	if (low >= high)	//base case and check for empty array or incorrect indexes
	{
		cout << "Base case reached. High = " << high << "   low = " << low << endl;
		return;
	}

	int partition = high;
	int i = low - 1;				//set to one less than smallest index for current call

	for (int j = low; j < high; j++)	//for loop that runs for the number of elements in this partition
										//loop swaps values to correct side of partition and increments i on each swap
	{
		if (!Comp::prior(A[partition], A[j]))	//if value should come after partition, increment i and do swap
		{
			i++;
			swap<E>(A, j, i);
			//std::swap(A[j], A[i]);
		}
	}
	swap<E>(A, i+1, partition);	//swap partition into correct position (one beyond i's final pos)
	//std::swap(A[i + 1], A[partition]);
	partition = i + 1;

	quicksort<E, Comp>(A, low, partition-1);		//recursive call to sort values less than partition
	quicksort<E, Comp>(A, partition+1, high);	    //recursive call to sort values greater than partition
}

template <typename E>
void printArray(E A[], int num)
{
	for (int i = 0; i < num; i++)
		cout << A[i] << " ";
	cout << endl;
}

const int SIZE = 10;

int main()
{
	int arr[SIZE] = { 5,10,9,3,4,8,7,1,2,6 };

	cout << "Before sort: ";
	printArray(arr, 10);

	quicksort<int, intComp>(arr, 0, SIZE - 1);

	cout << "After sort: ";
	printArray(arr, 10);


	int arr2[2] = { 2,1 };
	quicksort<int, intComp>(arr2, 0, 1);
	cout << "arr2 after sort: ";
	printArray(arr2, 2);

	int arr3[5];
	quicksort<int, intComp>(arr3, 0, 0);
	cout << "arr3 after sort: ";
	printArray(arr3, 0);


	return 0;
}