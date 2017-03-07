#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include "TypeDefs.h"

class matrix{
	private:
		double * mat; //! The array to the content of this matrix in.
		uint rows;
		uint cols;
		
	public:
		matrix(uint r, uint c, double v=0.0);
		matrix(const matrix &matr);
		~matrix();
		
		matrix add(const matrix &matr);
		matrix dot(const matrix &matr);
		matrix sub(const matrix &matr);
		matrix transpose();
		
		double get_element(uint r, uint c);
		void set_element(uint r, uint c, double v);
		
		uint num_rows();
		uint num_cols();
};

#endif