#include "HyperbolicTangentFunction.h"

#include <cmath>

hyperbolic_tangent * hyperbolic_tangent::hyptan;

hyperbolic_tangent::hyperbolic_tangent(){}
hyperbolic_tangent::~hyperbolic_tangent(){}

hyperbolic_tangent * hyperbolic_tangent::get_hyperbolic_tangent(){
	if(hyptan == nullptr){
		hyptan = new hyperbolic_tangent();
	}
	hyptan->ref_counter++;
	return hyptan;
}

void hyperbolic_tangent::deref(){
	ref_counter--;
	if(ref_counter == 0){
		delete this;
		hyptan = nullptr;
	}
}

double hyperbolic_tangent::function(double val){
	return tanh(val);
}
double hyperbolic_tangent::function_derivative(double val){
	double v = function(val);
	double v_squ = v * v;
	return (1 - v_squ);
}
std::string hyperbolic_tangent::get_type(){
	return type;
}


unsigned int hyperbolic_tangent::get_reference_counter(){
	return ref_counter;
}