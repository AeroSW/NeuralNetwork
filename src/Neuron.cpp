#include "Neuron.h"
#include "FunctionHandler.h"

namespace AeroSW{
neuron::neuron(uint num_wts, double b, func_id fid):
bias(b), weights(num_wts, 1){
	function = function_handler::get_function(fid);
}

neuron::neuron(const neuron &node):
bias(node.bias), weights(node.weights){
	std::string func_type = node.function->get_type();
	function = function_handler::get_function(func_type);
}

neuron::~neuron(){
	function->deref();
}

double neuron::feed(matrix &mat){
	if(mat.row_count() > 1){
		mat = mat.transpose();
	}
	matrix dot = weights.dot(mat);
	summs = dot.get_elem(0);
	summs += bias;
	value = function->function(summs);
	return value;
}

double neuron::invert(){
	diffs = function->function_derivative(summs);
	return diffs;
}

double neuron::get_bias(){
	return bias;
}

double neuron::get_diff(){
	return diffs;
}

double neuron::get_value(){
	return value;
}

double neuron::get_weight(uint index){
	return weights.get_elem(index);
}

matrix neuron::get_weights(){
	matrix temp(weights);
	return temp;
}

void neuron::set_bias(double b){
	bias = b;
}

void neuron::set_value(double v){
	value = v;
}

void neuron::set_weight(uint index, double wt){
	weights.set_elem(index, wt);
}

void neuron::set_weights(double * wts, uint num){
	if(weights.row_count() != num){
		throw 1; // Gonna replace with exception once made.
	}
	for(uint cx = 0; cx < num; cx++){
		weights.set_elem(cx, wts[cx]);
	}
}

void neuron::set_weights(matrix &mat){
	if(mat.row_count() != weights.row_count() && weights.row_count() == mat.col_count()){
		weights = mat.transpose();
	}
	else if(mat.row_count() == weights.row_count() && mat.col_count() == 1){
		weights = mat;
	}
	else{
		throw 1;
	}
}

uint neuron::num_inputs(){
	return weights.row_count();
}

std::string neuron::get_type(){
	return type;
}

neuron& neuron::operator=(const neuron &node){
	bias = node.bias;
	weights = node.weights;
	function->deref();
	std::string f_type = node.function->get_type();
	function = function_handler::get_function(f_type);
	return *this;
}
}
