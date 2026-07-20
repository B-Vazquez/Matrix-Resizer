#include "Matrix.h"


// Constructor
Matrix::Matrix(unsigned int num_of_rows, unsigned int num_of_columns)
	: num_of_rows(num_of_rows), num_of_columns(num_of_columns), data(num_of_rows, vector<char>(num_of_columns)) {}

// Operators

/*	Overloads '>>' for "istream >> Matrix"
	@param in: An input stream
	@param tempMatrix: A matrix object
	@return: Input stream after loading the matrix object
*/
istream& operator >> (istream& in, Matrix& tempMatrix) {
	in >> tempMatrix.num_of_rows >> tempMatrix.num_of_columns;

	char tempChar;

	for (unsigned int i = 0; i < tempMatrix.num_of_rows; i++) {
		tempMatrix.data.push_back(vector<char>(tempMatrix.num_of_columns));
		for (unsigned int j = 0; j < tempMatrix.num_of_columns; j++) {
			in >> tempChar;
			tempMatrix.data[i][j] = tempChar;
		}
	}
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
		throw std::exception("Illegal reshaping");
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