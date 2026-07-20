#include "Matrix.h"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Open the input file.
    ifstream inputFile("before.txt");

    // Test whether the input file was successfully opened.
    if (!inputFile) {
        cout << argv[0] << endl;
        cout << "Error: input file does not exist. Please ensure the input file is stored in the above directory." << endl;
        system("pause");
        return -1;
    }

    // Open the output file.
    ofstream outputFile("after.txt");

    Matrix matrix; // Matrix object

    // Passes the matrix stored in the input file to the matrix object
    inputFile >> matrix;

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