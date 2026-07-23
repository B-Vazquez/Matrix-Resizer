#include "Matrix.h"

#include <fstream>
#include <iostream>

using namespace std;

// Function used in the main() function
void validateNewRowsAndColumns(istream& in);

int main(int argc, char* argv[]) {
    // Open the input file.
    ifstream inputFile("before.txt");

    // Test whether the input file was successfully opened.
    if (!inputFile) {
        cout << argv[0] << endl;
        cout << "Error: input file does not exist. Please ensure the input file is stored in the above directory." << endl;
        return -1;
    }

    // Open the output file.
    ofstream outputFile("after.txt");

    Matrix matrix; // Matrix object

    try{
        // Passes the matrix stored in the input file to the matrix object
        inputFile >> matrix;

        // Validates whether new number of rows and columns are in the input file.
        validateNewRowsAndColumns(inputFile);
    }
    catch (exception& excpt) {
        outputFile << excpt.what() << endl;
        inputFile.close();
        outputFile.close();
        return -1;
    }

    // Variables used to store the number of rows and columns after reshaping the matrix
    unsigned int new_num_rows, new_num_columns;

    inputFile >> new_num_rows >> new_num_columns;

    try {
        matrix.reshape(new_num_rows, new_num_columns);
        outputFile << matrix;
    }
    catch (exception& excpt) {
        outputFile << excpt.what() << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}

/* Validates whether new number of rows and columns are in the input file.
    @param in: An input stream
*/
void validateNewRowsAndColumns(istream& in){
    const std::streampos trailingCheck = in.tellg();
	if (trailingCheck != std::streampos(-1)) {
		unsigned int new_num_rows = 0;
		unsigned int new_num_columns = 0;

		if (!(in >> new_num_rows >> new_num_columns) || (new_num_rows >= 100) || (new_num_columns >= 100) || (new_num_rows == 0) || (new_num_columns == 0)) {
			throw runtime_error("Error: Invalid input for new matrix size.");
		}
		in.seekg(trailingCheck);
	}
}