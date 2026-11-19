# Matrix Resizer

Matrix Resizer is a small C++ program that reads a matrix from a text file, validates the matrix contents, and then reshapes it into a new size when the total number of elements remains unchanged.

## What the program does

The program expects an input file named `before.txt` that contains:

1. The original matrix dimensions as `rows columns`
2. Exactly `rows * columns` single-character values
3. The new target dimensions as `new_rows new_columns`

After reading the data, the program writes the reshaped matrix to `after.txt`.

## Build and run

From the workspace root, compile the project with:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic MatrixResizer/main.cpp MatrixResizer/Matrix.cpp -o matrix-resizer
```

Run it from the workspace root so `before.txt` is found:

```sh
./matrix-resizer
```

## Example input format

```text
7	6

Z	Y	X	W	V	U
T	S	R	Q	P	O
N	M	L	K	J	I
H	G	F	E	D	C
B	A	0	1	2	3
4	5	6	7	8	9
a	b	c	d	e	f

2	21
```

This example describes a `7 x 6` matrix followed by the desired `2 x 21` size.

## Notes and limitations

- The program currently uses fixed file names: `before.txt` for input and `after.txt` for output.
- Matrix dimensions must be greater than `0` and less than `100`.
- Each matrix entry must be a single character token.
- The reshape operation is only valid when the total number of elements stays the same.
- If the input is malformed, the program writes an error message instead of crashing.
- The code currently assumes the working directory is set so the input file can be found reliably.

## Project structure

- `MatrixResizer/main.cpp` contains the main program flow
- `MatrixResizer/Matrix.h` declares the `Matrix` class
- `MatrixResizer/Matrix.cpp` implements matrix parsing, output, and reshaping

## Expected behavior

- Valid input: the matrix is reshaped and written to `after.txt`
- Invalid input: a descriptive error message is written to the output file and the program exits with a failure status
- Invalid reshape request: the program reports that the new dimensions do not preserve the total number of elements