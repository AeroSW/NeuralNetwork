#include "Matrix.h"
#include "omp.h"

matrix::matrix(uint r, uint c, double v):
rows(r),cols(c){
	mat = new double[r*c](v);
}
matrix::matrix(const matrix &matr):
rows(matr.rows),cols(matr.cols){
	mat = new double[rows * cols];
	uint dx = rows * cols;
	#pragma omp parallel for schedule(dynamic)
	for(uint cx = 0; cx < dx; cx++){
		mat[cx] = matr.mat[cx];
	}
}

matrix::~matrix(){
	delete mat;
}

matrix matrix::add(const matrix &matr){
	res_rows = rows;
	res_cols = cols;
	if(matr.rows > res_rows){
		res_rows = matr.rows;
	}
	if(matr.cols > res_cols){
		res_cols = matr.cols;
	}
	matrix result(res_rows, res_cols);
	#pragma omp parallel for schedule(dynamic)
	for(uint r = 0; r < res_rows; r++){
		for(uint c = 0; c < res_cols; c++){
			double v = get_element(r, c) + matr.get_element(r, c); // using get_element so if we go out of bounds, a 0 is returned.
			result.set_element(r, c, v);
		}
	}
	return result;
}

matrix matrix::dot(const matrix &matr){
	uint res_rows = rows;
	uint res_cols = matr.cols;
	uint m = cols;
	if(m < matr.rows){
		m = matr.rows;
	}
	matrix result(res_rows, res_cols);
	#pragma omp parallel for schedule(dynamic)
	for(uint r = 0; r < res_rows; r++){
		for(uint c = 0; c < res_cols; c++){
			double summ(0.0);
			for(uint k = 0; k < m; k++){
				summ += (get_element(r, k) * matr.get_element(k, c));
			}
			result.set_element(r, c, summ);
		}
	}
	return result;
}

matrix matrix::sub(const matrix &matr){
	uint res_rows = rows;
	uint res_cols = cols;
	if(res_rows < matr.rows){
		res_rows = matr.rows;
	}
	if(res_cols < matr.cols){
		res_cols = matr.cols;
	}
	matrix result(res_rows, res_cols);
	#pragma omp parallel for schedule(dynamic)
	for(uint r = 0; r < res_rows; r++){
		for(uint c = 0; c < res_cols; c++){
			double v = get_element(r, c) - matr.get_element(r, c);
			result.set_element(r, c, v);
		}
	}
	return result;
}

matrix matrix::transpose(){
	matrix result(cols, rows);
	#pragma omp parallel for schedule(dynamic)
	for(uint r = 0; r < rows; r++){
		for(uint c = 0; c < cols; c++){
			double v = get_element(r, c);
			result.set_element(c, r, v);
		}
	}
	return result;
}

double matrix::get_element(uint r, uint c){
	uint index = (cols * r) + c;
	return mat[index];
}

void matrix::set_element(uint r, uint c, double v){
	uint index = (cols * r) + c;
	mat[index] = v;
}

uint matrix::num_rows(){
	return rows;
}
uint matrix::num_cols(){
	return cols;
}