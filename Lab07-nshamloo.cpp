//Lab7-nshamloo.cpp
//Niloufar Shamloo
//11/19/2018

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::ostream;
#include<algorithm>
using std::is_sorted;
#include "Lab7-nshamloo.h"
#include "winTimer.cpp"

int main()
{
	vector <double> vec1 = { 1,2,3,4,5 };
	bubbleSort(vec1);
	insertionSort(vec1);
	mergeSort(vec1);
	selectionSort(vec1);
	quickSort(vec1);

	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i];
	}
	return 0;
}

void swapVal(double x, double y) //to swap two values
{
	double tempVal = x;
	x = y;
	y = tempVal;
}

void SortAlg::bubbleSort(vector<double> & vec2)
{
	double num = vec2.size();
	for (double i = 1; i < num; i++)
	{
		if (vec2[i] > vec2[i - 1])
		{ 
			swapVal(vec2.at[i], vec2.at[i - 1]);
		}
	}
}

void SortAlg::insertionSort(vector<double> &vec3)
{
	double num = vec3.size();
	for (double i = 0; i < num; i++)
	{
		double Value = vec3.at(i);
		double Posi = i;
		while (Posi > 0 && Value < vec3.at(Posi - 1))
		{
			vec3.at(Posi) = vec3.at(Posi - 1);
			Posi--;
		}
		vec3.at(Posi) = Value;
	}
}

void SortAlg::selectionSort(vector<double> & vec4)
{
	double num = vec4.size();
	for (double i = 0; i < num; i++)
	{
		double position = i;
		for (double j = i + 1; j < num; j + 1)
		{
			if (vec4.at(j) < vec4.at(position))
			{
				position = j;
			}
		}
		swapVal(vec4.at(i), vec4.at(position));
	}
}

void merge(vector<double> & vec4, double start, double half, double end)
{
	vector<double> a(vec4.begin() + start, vec4.begin() + half);
	double numHalf = half;
	double aNum = 0;
	double numStart = start;

	while (numHalf < end && aNum < a.size())
	{
		if (vec4.at(numStart) < a.at(aNum))
		{
			vec4.at(aNum) = vec4.at(numHalf);
			numStart++;
			aNum++;
		}
		else
		{
			vec4.at(numStart) = a.at(aNum);
			numStart++;
			aNum++;
		}
	}

	while (numHalf < end)
	{
		vec4.at(numStart) = vec4.at(numHalf);
		numStart++;
		numHalf++;
	}

	while (aNum < a.size())
	{
		vec4.at(numStart) = a.at(aNum);
		numStart++;
		aNum++;
	}
}

void SortAlg::mergeSort(vector<double> &seq, double start, double end)
{
	if ((end - start) < 2)
	{
		return;
	}
	double half = (start + end) / 2;
	mergeSort(seq, start, half);
	mergeSort(seq, half, start);
	merge(seq, start, half, end);
}

void SortAlg::quickSort(vector<double> &vec5, double start, double end)
{
	if ((end - start) < 2)
	{
		return;
	}
	quickSort(vec5, 0, vec5.size());
}