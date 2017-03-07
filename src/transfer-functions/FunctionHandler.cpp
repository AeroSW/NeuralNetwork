#include "FunctionHandler.h"

/*
 *	Exception Throwing:
 *		throw 1 -> type not defined
 *		throw 2 -> incorrect object type
 *		throw 3 -> func_id not defined
 */

// get_id()
func_id function_handler::get_id(const std::string &func_type){
	if(func_type.compare("sigmoid") == 0){
		return func_id::LOGSIG;
	}
	else if(func_type.compare("hyperbolic_tangent") == 0){
		return func_id::HYPTAN;
	}
	throw 1;
}
func_id function_handler::get_id(transfer_function * tf){
	std::string func_type = tf->get_type();
	if(func_type.compare("sigmoid") == 0){
		return func_id::LOGSIG;
	}
	else if(func_type.compare("hyperbolic_tangent") == 0){
		return func_id::HYPTAN;
	}
	throw 2;
}

// get_type
std::string function_handler::get_type(const func_id &fid){
	unsigned int index = (unsigned int) fid;
	transfer_function * tf;
	switch(fid){
		case func_id::LOGSIG:
			tf = sigmoid::get_sigmoid();
			break;
		case func_id::HYPTAN:
			tf = hyperbolic_tangent::get_hyperbolic_tangent();
			break;
		default:
			throw 3;
	};
	std::string type = tf->get_type();
	tf->deref();
	return type;
}
std::string function_handler::get_type(transfer_function * tf){
	std::string type = tf->get_type();
	return type;
}

// get_function
transfer_function * function_handler::get_function(const func_id &fid){
	switch(fid){
		case func_id::LOGSIG:
			return sigmoid::get_sigmoid();
		case func_id::HYPTAN:
			return hyperbolic_tangent::get_hyperbolic_tangent();
	}
	throw 3;
}
transfer_function * function_handler::get_function(const std::string &type){
	if(type.compare("sigmoid") == 0){
		return sigmoid::get_sigmoid();
	}
	else if(type.compare("hyperbolic_tangent") == 0){
		return hyperbolic_tangent::get_hyperbolic_tangent();
	}
	throw 1;
}

