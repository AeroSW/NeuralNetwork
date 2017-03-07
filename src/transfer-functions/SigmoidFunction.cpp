#include "SigmoidFunction.h"

#include <cmath>

sigmoid * sigmoid::logsig;

sigmoid::sigmoid(){}
sigmoid::~sigmoid(){}

sigmoid * sigmoid::get_sigmoid(){
	if(logsig == nullptr){
		logsig = new sigmoid();
	}
	logsig->ref_counter++;
	return logsig;
}

void sigmoid::deref(){
	ref_counter--;
	if(ref_counter == 0){
		delete this;
		logsig = nullptr;
	}
}

double sigmoid::function(double val){
	double t = val * -1;
	double e_t = exp(t);
	t = 1 + e_t;
	e_t = 1 / t;
	return e_t;
}
double sigmoid::function_derivative(double val){
	double v = function(val);
	double diff = 1 - v;
	return (v*diff);
}
std::string sigmoid::get_type(){
	return type;
}

unsigned int sigmoid::get_reference_counter(){
	return ref_counter;
}