#include "Matrix.h"

#include <fstream>
#include <iostream>

using namespace std;

int main(int, char* argv[]) {
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
    unsigned int new_num_rows = 0;
    unsigned int new_num_columns = 0;

    try{
        // Passes the matrix stored in the input file to the matrix object
        inputFile >> matrix;

        if (!(inputFile >> new_num_rows >> new_num_columns) ||
            new_num_rows >= 100 || new_num_columns >= 100 ||
            new_num_rows == 0 || new_num_columns == 0) {
            throw runtime_error("Error: Invalid input for new matrix size.");
        }
    }
    catch (exception& excpt) {
        cerr << excpt.what() << endl;
        inputFile.close();
        outputFile.close();
        return -1;
    }

    try {
        matrix.reshape(new_num_rows, new_num_columns);
        outputFile << matrix;
    }
    catch (exception& excpt) {
        cerr << excpt.what() << endl;
        inputFile.close();
        outputFile.close();
        return -1;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    return 0;
}