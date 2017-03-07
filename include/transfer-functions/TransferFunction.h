#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H

#include <string>
#include "Singleton.h"

class transfer_function : public singleton{
	protected:
		virtual ~transfer_function(){}
	public:
		virtual void deref() = 0;
		virtual double function(double value) = 0;
		virtual double function_derivative(double value) = 0;
		virtual std::string get_type() = 0;
		virtual unsigned int get_reference_counter() = 0;
};

#endif