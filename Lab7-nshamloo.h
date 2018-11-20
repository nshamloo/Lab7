//Lab7-nshamloo.h
//Niloufar Shamloo
//11/19/2018

#ifndef SortAlg
#define SortAlg

#include  <vector>
using std::vector;

#include <iostream>
using namespace std;

class SortAlg
{
public:
	void bubbleSort(vector<double> &vec2);
	void insertionSort(vector<double> &vec3);
	void selectionSort(vector<double> &vec4);
	void mergeSort(vector<double> &seq, double start, double end);
	void quickSort(vector<double> &vec5, double start, double end);
};

#endif