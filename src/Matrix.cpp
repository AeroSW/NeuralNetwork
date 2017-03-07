/* matrix.cpp */
/*
 *	Author:		Kenneth Cornett (Aero)
 *	Namespace:	AeroSW
 *	File:		matrix.cpp
 */

#include "Matrix.h"
#include <cmath>
#include <string>
#include "omp.h"

namespace AeroSW{
	typedef unsigned int uint;
	
	matrix::matrix()/*:
	m(2)*/{
		num_rows = 0;
		num_cols = 0;
		num_elem = 0;
		m = new double[2];
	}
	matrix::matrix(const matrix &mat) :
	num_rows(mat.num_rows),num_cols(mat.num_cols){
		num_elem = num_rows * num_cols;
		m = new double[num_elem];
		for(uint i = 0; i < num_elem; i++){
			m[i] = mat.m[i];
		}
	}
	matrix::matrix(uint r, uint c)/*:
	m(r*c)*/{
		num_rows = r;
		num_cols = c;
		num_elem = r * c;
		m = new double[r * c];
	}
	matrix::matrix(uint r, uint c, double * contents)/*:
	m(r*c)*/{
		// Assume contents size is r * c
		num_rows = r;
		num_cols = c;
		num_elem = r * c;
		m = new double[num_elem];
		for(uint i = 0; i < num_elem; i++){
			m[i] = contents[i];
		}
	}
	
	matrix::~matrix(){
		delete[] m;
	}
	
	double matrix::get_elem(uint index){
		if(index > num_elem){
			return 0.0;
		}
		return m[index];
	}
	double matrix::get_elem(uint r, uint c){
		if(r >= num_rows || c >= num_cols){
			return 0.0;
		}
		uint index = (r * num_cols) + c;
		return m[index];
	}
	
	matrix matrix::add(matrix &mat){
		uint mrows = mat.row_count();
		uint mcols = mat.col_count();
		uint nrows;
		uint ncols;
		if(num_rows > mrows){
			nrows = num_rows;
		}
		else{
			nrows = mrows;
		}
		if(num_cols > mcols){
			ncols = num_cols;
		}
		else{
			ncols = mcols;
		}
		double * new_mat = new double[nrows * ncols];
		#pragma omp parallel for schedule(dynamic)
		for(unsigned int r = 0; r < nrows; r++){
			for(unsigned int c = 0; c < ncols; c++){
				double v = (get_elem(r, c) + mat.get_elem(r, c));
				uint i = (r * ncols) + c;
				new_mat[i] = v;
			}
		}
		matrix n(nrows, ncols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::dot(matrix &mat){
		uint nrows = num_rows; // Get number of rows for resulting matrix
		uint ncols = mat.col_count(); // Get number of columns for resulting matrix
		uint m; // m should be the minimum of the set (this matrix's columns and mat's rows)
		double * new_mat = new double[nrows * ncols];
		if(num_cols < mat.row_count()){
			m = num_cols;
		}
		else{
			m = mat.row_count();
		}
		// Algorithm for dot product is done in parallel.
		#pragma omp parallel for schedule(dynamic)
		for(unsigned int r = 0; r < nrows; r++){
			for(unsigned int c = 0; c < ncols; c++){
				double summ = 0;
				for(unsigned int k = 0; k < m; k++){
					summ += (get_elem(r, k) * mat.get_elem(k, c));
				}
				uint i = (r * ncols) + c;
				new_mat[i] = summ;
			}
		}
		matrix n(nrows, ncols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::ident(uint n){
		double * new_mat = new double[n * n];
		#pragma omp parallel for schedule(dynamic)
		for(uint r = 0; r < n; r++){
			for(uint c = 0; c < n; c++){
				uint i = (r * n) + c;
				if(r == c){
					new_mat[i] = 1;
				}
				else{
					new_mat[i] = 0;
				}
			}
		}
		matrix mat(n, n, new_mat);
		delete[] new_mat;
		return mat;
	}
	/*matrix matrix::invert(){
		// to-do
	}*/
	matrix matrix::scalar_add(double scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] + scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::scalar_add(long long scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] + scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::scalar_mult(double scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] * scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::scalar_mult(long long scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] * scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::scalar_sub(double scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] - scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::scalar_sub(long long scalar){
		double * new_mat = new double[num_elem];
		#pragma omp parallel for schedule(dynamic)
		for(uint i = 0; i < num_elem; i++){
			new_mat[i] = m[i] - scalar;
		}
		matrix n(num_rows, num_cols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::sub(matrix &mat){
		uint mrows = mat.row_count();
		uint mcols = mat.col_count();
		double * new_mat;
		uint nrows;
		uint ncols;
		if(num_rows > mrows){
			nrows = num_rows;
		}
		else{
			nrows = mrows;
		}
		if(num_cols > mcols){
			ncols = num_cols;
		}
		else{
			ncols = mcols;
		}
		new_mat = new double[nrows * ncols];
		
		#pragma omp parallel for schedule(dynamic)
		for(unsigned int r = 0; r < nrows; r++){
			for(unsigned int c = 0; c < ncols; c++){
				double v = (get_elem(r, c) - mat.get_elem(r, c));
				uint i = (r * ncols) + c;
				new_mat[i] = v;
			}
		}
		matrix n(nrows, ncols, new_mat);
		delete[] new_mat;
		return n;
	}
	matrix matrix::transpose(){
		matrix new_matrix(num_cols, num_rows);
		for(uint r = 0; r < num_rows; r++){
			for(uint c = 0; c < num_cols; c++){
				new_matrix.set_elem(c, r, get_elem(r, c));
			}
		}
		return new_matrix;
	}
	
	std::string matrix::to_string(){
		std::string str = "";
		for(uint r = 0; r < num_rows; r++){
			for(uint c = 0; c < num_cols; c++){
				uint i = (r * num_cols) + c;
				str += std::to_string(m[i]) + "\t";
			}
			if(r < (num_rows - 1))
				str += "\n";
		}
		return str;
	}
	std::string matrix::get_type(){
		return "matrix";
	}
	
	uint * matrix::get_dim(){
		uint * dimen = new uint[2];
		dimen[0] = num_rows;
		dimen[1] = num_cols;
		return dimen;
	}
	uint matrix::row_count(){
		return num_rows;
	}
	uint matrix::col_count(){
		return num_cols;
	}
	
	void matrix::set_elem(uint index, double val){
		if(index < num_elem){
			m[index] = val;
		}
	}
	void matrix::set_elem(uint r, uint c, double val){
		if(r < num_rows && c < num_cols){
			uint i = (r * num_cols) + c;
			m[i] = val;
		}
	}
	matrix& matrix::operator=(const matrix &matr){
		delete[] m;
		num_rows = matr.num_rows;
		num_cols = matr.num_cols;
		num_elem = matr.num_elem;
		m = new double[num_elem];
		for(uint i = 0; i < num_elem; i++){
			m[i] = matr.m[i];
		}
		return *this;
	}
}
