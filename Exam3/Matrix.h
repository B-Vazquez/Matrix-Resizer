#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

using std::vector;
using std::istream;
using std::ostream;
using std::endl;

class Matrix {
public:
	// Constructor
	Matrix(unsigned int = 0, unsigned int = 0); // Default constructor

	// Class-member function
	void reshape(unsigned int, unsigned int); // Reshapes the matrix 

	// Operators
	friend istream& operator >> (istream&, Matrix&); // Overloads '>>' for "istream >> Matrix"
	friend ostream& operator << (ostream&, const Matrix&); // Overloads '<<' for "ostream << Matrix"

private:
	// Data fields
	vector<vector<char>> data; // Stores the data of the matrix
	unsigned int num_of_rows; // Stores the number of rows of the matrix
	unsigned int num_of_columns; // Stores the number of columns of the matrix
};

#endif