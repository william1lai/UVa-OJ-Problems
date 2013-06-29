#include <cstdlib>
#include <iostream>

using namespace std;

int bubbleSort(int* arr, int size)
{
  int swaps = 0;
  
  int i;
  int temp;
  for (i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      temp = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = temp;
      swaps++;
    }
  }

  if (swaps > 0)
  {
    return bubbleSort(arr, size) + swaps;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int ncases;
  cin >> ncases;

  int numTrains;
  int* trainArr;
  int i;
  for (i = 0; i < ncases; i++)
  {
    cin >> numTrains;
    trainArr = new int[numTrains];
    int j;
    for (j = 0; j < numTrains; j++)
    {
      cin >> trainArr[j];
    }

    cout << "Optimal train swapping takes " << bubbleSort(trainArr, numTrains) << " swaps.\n";
    delete [] trainArr;
  }
}