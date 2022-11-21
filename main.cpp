// =================================================================
//
// File: main.cpp
// Author: José Ricardo Rosales Castañeda - A01709449
// Author: Uri Gopar Morales - A01709413
// Date: 20/11/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include "heap.h"

using namespace std;

// =================================================================
// main function
//
// @param argc, the number of parameters
// @param argv, the parameters
// @return 0 if the program ends correctly
// @complexity O(n log n)
// =================================================================
int main(int argc, char* argv[]) {
	int size, val, res, aux;
	fstream input(argv[1], ios::in);
	fstream output(argv[2], ios::out);

	input >> size;
	Heap<int> heap(size);

	for (int i = 0; i < size; i++){
		input >> val;
		heap.add(val);
	}
	
	while (heap.length() > 1) {
		aux = heap.remove() + heap.remove();
		res += aux - 1;
		heap.add(aux);
	}

	output << res << endl;
	return 0;
}
