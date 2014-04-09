#ifndef COMPLEXMATRIX_H
#define COMPLEXMATRIX_H

#include <iostream>
#include "Complex.h"

class ComplexMatrix{
//friends:
	friend std::ostream &operator<<(std::ostream &, const ComplexMatrix &);
	
public:
	//constructor
	ComplexMatrix(int n = 0);
	//copy constructor
	ComplexMatrix(const ComplexMatrix &);
	//destructor
	~ComplexMatrix();
	//operator overload
	ComplexMatrix operator+(const ComplexMatrix &);
	ComplexMatrix operator*(const ComplexMatrix &);
	//function
	void fillMatrix();
	//() overload
	Complex &operator()(int, int);
	
private:
	int size;
	//ptr is a 1-D array
	//[i*size + j] will give the (i, j) element in the matrix
	Complex *ptr;
};

#endif
