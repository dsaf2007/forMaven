#include <iostream>
using namespace std;

class Vectornd
{
public:
	int com;
	int *vec;
	Vectornd()
	{

	}
	Vectornd(const int com_)
	{
		com = com_;

		vec = new int[com];
		for (int i = 0; i < com; i++)
		{
			vec[i] = NULL;
		}
	}
};

class MatrixMxN
{
public:
	int row, col;
	int **mat;
	MatrixMxN()
	{

	}
	MatrixMxN(const int row_,const int col_)
	{
		row = row_;
		col = col_;

		mat = new int*[col];
		for (int i = 0; i < row; i++)
		{
			mat[i] = new int[col];
		}

		for(int i=0;i<row;i++)
			for (int j = 0; j < col; j++)
			{
				mat[i][j] = 0;
			}
	
	}
	Vectornd operator*(const Vectornd& input)
	{
		Vectornd vec(input.com);
		for (int i = 0; i < row; i++)
		{
			vec.vec[i] = 0;
		}
		for (int i = 0; i<row; i++)
			for (int j = 0; j < col; j++)
		{
				vec.vec[i] += input.vec[j] * mat[i][j];
		}
		return vec;
	}
};
ostream& operator<<(ostream&os, const Vectornd&vec)
{
	for (int i = 0; i < vec.com; i++)
	{
		os << vec.vec[i] << endl;
	}
	return os;
}

ostream& operator<<(ostream&os, const MatrixMxN&mat)
{
	for (int i = 0; i < mat.row; i++) {
		for (int j = 0; j < mat.col; j++)
		{
			os << mat.mat[i][j] << "/";
		}std::cout << std::endl;
	}
	return os;
}

void main()
{
	Vectornd vec3 = Vectornd(5);
	vec3.vec[0] = 4;
	vec3.vec[1] = 3;
	vec3.vec[2] = 2;
	vec3.vec[3] = 1;

	MatrixMxN mat = MatrixMxN(5, 4);

	for(int i=0;i<mat.row;i++)
		for (int j = 0; j < mat.col; j++)
		{
			mat.mat[i][j] = (i+1)+ j;
		}
	Vectornd y;
	y = mat*vec3;
	std::cout << y<< std::endl;
	
}