#include <string>
#include <iostream>
#include "FunctionHandler.h"

using namespace std;

int main(){
	std::cout << '\n';
	std::cout << "<<<< TESTING RETRIEVES >>>>" << endl;
	transfer_function * tf_1 = function_handler::get_function(func_id::LOGSIG);
	transfer_function * tf_2 = function_handler::get_function(func_id::HYPTAN);
	std::cout << "Sigmoid:\t" << tf_1->get_type() << std::endl;
	std::cout << "HypTangent:\t" << tf_2->get_type() << std::endl;
	std::cout << '\n';
	std::cout << "<<<< TESTING FUNCTIONS >>>>" << endl;
	double test_input = 0.675;
	double lsig_output = tf_1->function(test_input);
	double htan_output = tf_2->function(test_input);
	std::cout << "Test Input:\t" << test_input << "\n\t";
	std::cout << "LogSig Output:\t" << lsig_output << "\n\t";
	std::cout << "HypTan Output:\t" << htan_output << endl;
	std::cout << '\n';
	std::cout << "<<<< TESTING DERIVATIVES >>>>" << endl;
	test_input = 0.00142;
	lsig_output = tf_1->function_derivative(test_input);
	htan_output = tf_2->function_derivative(test_input);
	std::cout << "Test Input:\t" << test_input << "\n\t";
	std::cout << "LogSig Output:\t" << lsig_output << "\n\t";
	std::cout << "HypTan Output:\t" << htan_output << endl;
	std::cout << '\n';
	std::cout << "<<<< TESTING COUNTER >>>>" << endl;
	sigmoid * sig = sigmoid::get_sigmoid();
	std::cout << "Sigmoid Counter:\t" << sig->get_reference_counter() << endl;
	sig->deref();
	std::cout << "Sigmoid Counter:\t" << sig->get_reference_counter() << endl;
	tf_1->deref(); // Decrements reference counter to 0, calling destructor.
	tf_2->deref(); // Decrements reference counter to 0, calling destructor.
	// Calling get_reference_counter() below will cause unexpected errors.
//	std::cout << "Sigmoid Counter:\t" << tf_1->get_reference_counter() << endl;
//	std::cout << "HypTan Counter:\t" << tf_2->get_reference_counter() << endl;
	std::cout << '\n' ;
	std::cout << "<<<< TESTING RETREIVES AFTER DEREF >>>>" << endl;
	tf_1 = function_handler::get_function(func_id::LOGSIG);
	std::cout << "SIGMOID Function created." << std::endl;
	std::cout << "Sigmoid:\t" << tf_1->get_type() << endl;
	std::cout << "Sigmoid Ref Count:\t" << tf_1->get_reference_counter() << endl;
	std::cout << endl;
	return 0;
}