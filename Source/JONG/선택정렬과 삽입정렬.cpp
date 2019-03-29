#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		int minIndex = i;
		for (int j = minIndex + 1; j < vec.size(); j++)
			if (vec[minIndex] > vec[j])
				minIndex = j;
		swap(vec[i], vec[minIndex]);
	}
}

void insertionSort(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		//A[0...i-1]에 A[i]를 끼워넣는다.
		int j = i;
		while (j > 0 && vec[j - 1] > vec[j])
		{
			swap(vec[j - 1], vec[j]);
			j--;
		}
	}
}

int main()
{
	vector<int> ret;
	ret.push_back(10);
	ret.push_back(6);
	ret.push_back(4);
	ret.push_back(8);
	ret.push_back(2);

	//selectionSort(ret);
	insertionSort(ret);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

}