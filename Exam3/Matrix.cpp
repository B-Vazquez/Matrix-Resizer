#include "Matrix.h"

// Constructs a matrix with the requested dimensions.
Matrix::Matrix(unsigned int num_of_rows, unsigned int num_of_columns)
	: num_of_rows(num_of_rows), num_of_columns(num_of_columns), data(num_of_rows, vector<char>(num_of_columns)) {}

// Operators

/*	Overloads '>>' for "istream >> Matrix"
	@param in: An input stream
	@param tempMatrix: A matrix object
	@return: Input stream after loading the matrix object
*/
istream& operator >> (istream& in, Matrix& tempMatrix) {
	unsigned int num_rows = 0;
	unsigned int num_columns = 0;

	if (!(in >> num_rows >> num_columns) || num_rows >= 100 || num_columns >= 100 || num_rows == 0 || num_columns == 0) {
		throw std::runtime_error("Error: Invalid input for current matrix size.");
	}

	vector<vector<char>> tempData(num_rows, vector<char>(num_columns));
	std::string tempString;

	for (unsigned int i = 0; i < num_rows; i++) {
		for (unsigned int j = 0; j < num_columns; j++) {
			// Verifies there is something to pass into the matrix alongside verifying that the registered data is a single character.
			if (!(in >> tempString) || tempString.length() != 1) {
				throw std::runtime_error("Error: Invalid input for matrix data.");
			}
			tempData[i][j] = tempString.c_str()[0];
		}
	}

	tempMatrix.num_of_rows = num_rows;
	tempMatrix.num_of_columns = num_columns;
	tempMatrix.data = tempData;
	return in;
}


/*	Overloads '<<' for "ostream << Matrix"
	@param out: An output stream
	@param tempMatrix: A matrix object
	@return: Output stream after writing the matrix object
*/
ostream& operator << (ostream& out, const Matrix& tempMatrix) {
	out << tempMatrix.num_of_rows << '\t' << tempMatrix.num_of_columns << endl << endl;

	for (unsigned int i = 0; i < tempMatrix.num_of_rows; i++) {
		for (unsigned int j = 0; j < tempMatrix.num_of_columns; j++) {
			out << tempMatrix.data[i][j] << '\t';
		}
		out << endl;
	}
	return out;
}

// Class-member function

/*	Reshapes the matrix
	@param new_num_rows: New number of rows
	@param new_num_columns: New number of columns
*/
void Matrix::reshape(unsigned int new_num_rows, unsigned int new_num_columns) {
	if (new_num_rows * new_num_columns != num_of_rows * num_of_columns) {
		throw std::runtime_error("Reshape failed: new dimensions do not match the total number of elements.");
	}
	else {
		vector<vector<char>> tempData(new_num_rows, vector<char>(new_num_columns));

		unsigned int i = 0, j = 0; // Used to insert the data from the old matrix into the new matrix

		// Loop to reshape the matrix
		for (unsigned int a = 0; a < new_num_rows; a++) {
			for (unsigned int b = 0; b < new_num_columns; b++) {
				if (j == num_of_columns) {
					j = 0;
					i++;
				}
				tempData[a][b] = data[i][j++];
			}
		}
		
		num_of_columns = new_num_columns; // Assigned number of columns to the new number of columns
		num_of_rows = new_num_rows; // Assigned number of rows to the new number of rows
		
		data = tempData;
	}
}