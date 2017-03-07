#ifndef FUNCTIONHANDLER_H
#define FUNCTIONHANDLER_H

#include "TransferFunctionIncludes.h"
#include <string>


const unsigned int num_funcs = 2; // Global size variable.

enum func_id{
	LOGSIG = 0,
	HYPTAN
};
// Global array of strings containing the types of functions
const std::string func_types[num_funcs] = {"sigmoid","hyperbolic_tangent"};
		
struct function_handler{
		static func_id get_id(const std::string &type);
		static func_id get_id(transfer_function * tf);
		static std::string get_type(const func_id &fid);
		static std::string get_type(transfer_function * tf);
		static transfer_function * get_function(const func_id &fid);
		static transfer_function * get_function(const std::string &type);
};


#endif