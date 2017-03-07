#ifndef MATRIX_H_
#define MATRIX_H_
// Matrix Class
/*
 *	Author:		Kenneth Cornett (Aero)
 *	Namespace:	AeroSW
 *	File:		matrix.h
 */
#include <string>
#include <vector>

namespace AeroSW{
	typedef unsigned int uint;
	class matrix{
		private:
			//std::vector<double> m;
			double * m;
			uint num_rows;
			uint num_cols;
			uint num_elem;
			
		public:
			matrix(); // default array, does nothing since there are no parameters.
			matrix(const matrix &mat);
			matrix(uint r, uint c);
			matrix(uint r, uint c, double * itms);
			
			~matrix();
			
			double get_elem(uint id);
			double get_elem(uint r, uint c);
			
			matrix add(matrix &mat);
			//matrix cross(matrix &mat);
			matrix dot(matrix &mat);
			/* Returns an identity matrix with dimensions nxn */
			static matrix ident(uint n);
			/* invert uses the Gauss-Jordan elimination or Augmented Matrix Method to find inverse. */
			matrix invert(); // to-do
			matrix scalar_add(double scalar);
			matrix scalar_add(long long scalar);
			matrix scalar_mult(double scalar);
			matrix scalar_mult(long long scalar);
			matrix scalar_sub(double scalar);
			matrix scalar_sub(long long scalar);
			matrix sub(matrix &mat);
			matrix transpose();
			
			std::string to_string();
			static std::string get_type();
			
			uint * get_dim();
			uint row_count();
			uint col_count();
			
			void set_elem(uint index, double val);
			void set_elem(uint r, uint c, double val);
			
			matrix& operator=(const matrix &matr);
	};
}
#endif