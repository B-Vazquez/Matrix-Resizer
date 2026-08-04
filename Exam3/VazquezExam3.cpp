#include "Matrix.h"

#include <fstream>
#include <iostream>

using namespace std;

// Validates the reshape dimensions that follow the matrix data in the input stream.
void validateNewRowsAndColumns(istream& in);

int main(int argc, char* argv[]) {
    // Open the source matrix file used by the current program.
    ifstream inputFile("before.txt");

    // Report a missing input file immediately so the program exits cleanly.
    if (!inputFile) {
        cerr << argv[0] << endl;
        cerr << "Error: input file does not exist. Please ensure the input file is stored in the above directory." << endl;
        return -1;
    }

    // Open the destination file used to store the reshaped result.
    ofstream outputFile("after.txt");

    if (!outputFile) {
        cerr << "Error: Could not create or open 'after.txt' in the current working directory." << endl;
        inputFile.close();
        return -1;
    }

    Matrix matrix; // Holds the input matrix until it is reshaped.

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