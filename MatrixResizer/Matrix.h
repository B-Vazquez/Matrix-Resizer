#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>


class Matrix {
public:
	// Constructor
	Matrix(unsigned int = 0, unsigned int = 0); // Default constructor

	// Class-member function
	void reshape(unsigned int, unsigned int); // Reshapes the matrix 

	// Operators
	friend std::istream& operator >> (std::istream&, Matrix&); // Overloads '>>' for "istream >> Matrix"
	friend std::ostream& operator << (std::ostream&, const Matrix&); // Overloads '<<' for "ostream << Matrix"

private:
	// Data fields
	unsigned int num_of_rows; // Stores the number of rows of the matrix
	unsigned int num_of_columns; // Stores the number of columns of the matrix
	std::vector<std::vector<char>> data; // Stores the data of the matrix
};

#endif