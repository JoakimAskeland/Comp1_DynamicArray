#include <iostream>
#include <time.h>	//for using time
#include <chrono>	//for using time

using namespace std;

template <class T>
class dynArr
{
private:
	T* pointerArray;			//points to the array
	int maxSize;				//caps the size of array 
	int numOfElements;			// (length)
	int nextIndex;				//the next highest index value

	int n;
	int low;
	int high;




public:
	dynArr();					//constructor
	~dynArr();					//deconstructor
	T& operator[] (int index);	//indexing operator
	void add(const T& value);	//add value to the end			//int value
	void expand();				//expands the array
	void reduce();				//reduces the array

	void linearSearch();

	void selectionSort();		//works

	//Quick sort
	void quickSort(int low, int high);			//(int low, int high);
	int partition(int low, int high);			//(int low, int high);


	void mergeSort();			
	void bubbleSort();			//works
	void insertionSort();

	void swap(int* xp, int* yp);

	int size();					//return length of array
	void print();				//prints array

	void menu();


};

template<class T>
dynArr<T>::dynArr()
{
	this->maxSize = 1;
	this->numOfElements = 0;
	this->nextIndex = 0;
	this->pointerArray = new T[maxSize]{};
	this->n = sizeof(*pointerArray) / sizeof(pointerArray[0]);
}

template<class T>
dynArr<T>::~dynArr()
{
	delete[] pointerArray;
}

template<class T>
T& dynArr<T>::operator[](int index)
{
	T* pnewa;
	if (index >= numOfElements)
	{
		pnewa = new T[index + 1];

		for (int i = 0; i < nextIndex; i++)
		{
			pnewa[i] = pointerArray[i];
		}
		for (int j = nextIndex; j < index + 1; j++)
		{
			pnewa[j] = 0;
		}

		maxSize = index + 1;
		delete[] pointerArray;
		pointerArray = pnewa;
	}

	if (index > nextIndex)
	{
		nextIndex = index + 1;
	}

	return *(pointerArray + index);
}

template<class T>
void dynArr<T>::add(const T& value)
{
	//Meisam

	if (this->numOfElements < this->maxSize)
	{
		this->pointerArray[this->numOfElements++] = value;
	}
	else
	{
		this->expand();
		this->pointerArray[this->numOfElements++] = value;
	}
}

template<class T>
void dynArr<T>::expand()
{
	this->maxSize += 1;		//expands the array by 1
	T* tempArr = new T[maxSize];

	for (size_t a = 0; a < this->numOfElements; a++)
	{
		tempArr[a] = pointerArray[a];
	}
	delete[] pointerArray;
	pointerArray = tempArr;
}

template<class T>
void dynArr<T>::reduce()
{

	if (numOfElements > 0)
	{
		cout << "Before deleting the last element: ";
		print();

		pointerArray[--maxSize] = NULL; //makes the last value = 0
		numOfElements--;

		cout << "After deleting the last element: ";
		print();
	}
	else
	{
		cout << "Empty array" << endl;
	}
}

template<class T>
void dynArr<T>::linearSearch()
{
	int userSearch;
	bool found = false;

	cout << "The element you would like to find: ";
	cin >> userSearch;
	cout << endl << endl;

	for (int a = 0; a <= numOfElements; a++)
	{
		if (pointerArray[a] == userSearch)
		{
			cout << "Element found! Location in array: " << a + 1 << endl << endl;
			found = true;
		}

		//else
		//{
		//	cout << "Element not found" << endl << endl; //Gets printed anyway. Some quickfix prob, maybe not worth having along though
		//	//Line = false;
		//}
	}

	if (found == false)
	{
		cout << "Element not found" << endl << endl;
	}
}

template<class T>
void dynArr<T>::selectionSort()
{
	cout << "Before Selection sort: ";
	print();

	for (int i = 0; i < maxSize - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < maxSize; j++)
		{
			if (pointerArray[j] < pointerArray[minIndex])
			{
				minIndex = j;
			}
		}
		swap(&pointerArray[minIndex], &pointerArray[i]);
	}

	cout << "After Selection sort: ";
	print();
}

template<class T>
void dynArr<T>::quickSort(int low, int high)
{

	if (low < high)
	{
		int parInd = partition(low, high);

		quickSort(low, parInd - 1);
		quickSort(parInd + 1, high);
	}

}

template<class T>
int dynArr<T>::partition(int low, int high)
{
	int pivot = pointerArray[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (pointerArray[j] < pivot)
		{
			i++;
			swap(&pointerArray[i], &pointerArray[j]);
		}
	}
	swap(&pointerArray[i + 1], &pointerArray[high]);
	return (i + 1);
}

template<class T>
void dynArr<T>::mergeSort()
{

}

template<class T>
void dynArr<T>::bubbleSort()
{
	cout << "Before Bubble sort: ";
	print();

	for (int i = 0; i < maxSize - 1; i++)
	{
		for (int j = 0; j < maxSize - i - 1; j++)
		{
			if (pointerArray[j] > pointerArray[j + 1])
			{
				swap(&pointerArray[j], &pointerArray[j + 1]);
			}
		}
	}

	cout << "After Bubble sort: ";
	print();
}

template<class T>
void dynArr<T>::insertionSort()
{
	cout << "Array before insertion sort: ";
	print();

	for (int a = 1; a < numOfElements; a++)
	{
		T tempArr = pointerArray[a];
		int b = a - 1;

		while (b >= 0 && tempArr <= pointerArray[b])
		{
			pointerArray[b + 1] = pointerArray[b];
			b = b - 1;
		}
		pointerArray[b + 1] = tempArr;
	}

	cout << "Array after insertion sort: ";
	print();
}

template<class T>
void dynArr<T>::swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template<class T>
int dynArr<T>::size()
{
	if (numOfElements > 0)
	{
		cout << "Number of elements: " << this->numOfElements << endl << endl;
	}
	else
	{
		cout << "Empty array" << endl << endl;
	}
	return numOfElements;
}

template<class T>
void dynArr<T>::print()
{
	if (numOfElements > 0)
	{
		for (int i = 0; i < numOfElements; i++)
			cout << pointerArray[i] << " ";	

		cout << endl << endl;
	}

	else
	{
		cout << "Array is empty" << endl << endl;
	}
}

template<class T>
void dynArr<T>::menu()
{
	system("cls");
	int answer;

	cout << "Sup gamer? Please choose what you would like to do with your array" << endl << endl;
	cout << "1: Add a value at the end" << endl;
	cout << "2: Add a value at chosen location" << endl;
	cout << "3: View number of elements in the array" << endl;
	cout << "4: Print the whole array" << endl;
	cout << "5: Delete the last value" << endl;
	cout << "6: Linear search" << endl;
	cout << "7: Selection sort" << endl;
	cout << "8: Quick sort" << endl;
	cout << "10: Bubble sort" << endl;
	cout << "11: Insertion sort" << endl;
	cout << "9: Quit" << endl;

	cin >> answer;
	system("cls");

	switch (answer)
	{
	case 1:
		int userInput;
		cin >> userInput;
		cout << endl << endl;
		this->add(userInput);
		break;

	case 3:
		this->size();
		break;

	case 4:
		this->print();
		break;

	case 5:
		this->reduce();
		break;

	case 6:
		this->linearSearch();
		break;

	case 7:
		this->selectionSort();			
		break;

	case 8:
		cout << "Before quick sort: ";
		print();
		this->quickSort(0, maxSize - 1);				
		cout << "After quick sort: ";
		print();
		break;

	case 9:
		exit(0);
		break;

	case 10:
		this->bubbleSort();
		break;

	case 11:
		this->insertionSort();
		break;

	default:
		cout << "ruh roh, not an option my guy" << endl << endl;
		this->menu();
	}
}

int main()
{
	dynArr<int> a1;

	auto start = chrono::system_clock::now(); //time

	bool continuePlaying = true;

	while (continuePlaying != false)
	{
		a1.menu();

		char continueBool;
		cout << "Keep on changing the array? [y] or [n]" << endl;
		cin >> continueBool;

		if (continueBool == 'n')
		{
			continuePlaying = false;
		}
		else 
		{
			while (continueBool != 'y' && continueBool != 'n')
			{
				cout << "Keep on changing the array? [y] or [n]" << endl;
				cin >> continueBool;
			}
			continuePlaying = true;
		}
	}

	auto finish = chrono::system_clock::now();


	return 0;
}