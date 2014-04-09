#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Complex.h"
#include "ComplexMatrix.h"

using namespace std;

//Friend implementations
ostream &operator<<(ostream &output, const ComplexMatrix &m){
	int size = m.size;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			//loop through the matrix
			output << "\t" << m.ptr[i*size + j] << "\t";
		}
		//start a new line everytime a row is finished
		output << endl;
	}
	return output;
} 
//constructor
ComplexMatrix::ComplexMatrix(int n)
	:size(n > 0 ? n: throw invalid_argument("Matrix size myst ve greater than 0")),
	ptr(new Complex[size*size])
{
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			//set all the elements to be 0 + i0
			Complex temp;
			ptr[i*size + j]  = temp;
		}
	}
}
//copy constructor
ComplexMatrix::ComplexMatrix(const ComplexMatrix &tocopy)
	:size(tocopy.size),
	ptr(new Complex[size*size])
{
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			ptr[i*size + j] = tocopy.ptr[i*size + j];
		}
	}
}

//destructor
ComplexMatrix::~ComplexMatrix(){
	delete [] ptr;
	cout<<"The memory allocated for the matrix has been deleted."<<endl;
}
//+ overload
ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix &m){
	if(size != m.size) {
		throw invalid_argument("Matrix sizes do not match");
	} else {
		ComplexMatrix temp(size);
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				//add the corresponding elements
				temp.ptr[i*size + j] = ptr[i*size + j] + m.ptr[i*size + j];
			}
		}
		return temp;
	}
}
//* overload
ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix &m){
	if(size != m.size) {
		throw invalid_argument("Matrix sizes do not match");
	} else {
		ComplexMatrix temp(size);
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				for(int k = 0; k < size; k++) {
					//perform multiplication
					temp.ptr[i*size + j] = temp.ptr[i*size + j] + ptr[i*size + k] * m.ptr[k*size + j];
				}
			}
		}
		return temp;
	}
}
//fillMatrix function
void ComplexMatrix::fillMatrix(){
	cout << "Please enter the matrix elements in the order indicated.\n";
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << "Element (" << i << ", " << j << "): ";
			Complex temp;
			//read the input
			cin >> temp;
			//assign the element to correct position
			ptr[i*size + j] = temp;
		}
	}
}
//() overload
Complex &ComplexMatrix::operator()(int x, int y){
	return ptr[x*size + y];
}
