#ifndef SIGMOIDFUNCTION_H
#define SIGMOIDFUNCTION_H

//! File Information
/*!
	\file SigmoidFunction.h
	Author:	Kenneth Cornett, student at Tennessee Tech University
	Date:	March 3, 2017
	Contains the skeleton for a sigmoid object.
 */

#include "TransferFunction.h"

//!	sigmoid class
/*!	\class sigmoid
 *	\brief A class which implements the logistic regression function.
 *	
 *	A class which is used to add the logistic regression function to
 *	other objects which need to use it.  The class uses the singleton
 *	design pattern since a single object reference is returned to all
 *	objects needing to use the logistic regression function.  It is
 *	appropriate to use this design pattern, since, this object does
 *	not store information.
 */
class sigmoid : public transfer_function{
	private:
		const std::string type = "sigmoid";
		//!	Private Constructor
		/*!
		 *	A private constructor to enforce factory
		 *	and singleton design patterns for this
		 *	program.
		 */
		sigmoid();
		
		static sigmoid * logsig;
		
	protected:
		//!	A virtual destructor
		/*!
		 *	This destructor destroys information in the inheritance
		 *	heirarchy for sigmoid()
		 */
		virtual ~sigmoid();
		
	public:
		//!	A function which returns a pointer to the sigmoid object.
		/*!
		 *	This function returns a pointer to a static sigmoid
		 *	object.
		 *	
		 *	\param	void
		 *	\return	pointer to a sigmoid object.
		 *	\sa		sigmoid()
		 */
		static sigmoid * get_sigmoid();
		
		//!	A function which keeps track of when to dereference this object.
		/*!
		 *	This function decrements a counter variable until it reaches 0.
		 *	At the point which the counter variable reaches 0, the object
		 *	is dereferenced.
		 *
		 *	\param	void
		 *	\return	void
		 *
		 *	\sa		Singleton.h
		 */
		virtual void deref();
		
		//!	Takes the given value and runs it through the transfer function.
		/*!
		 *	This method takes the passed in object and passes it into the
		 *	defined function.  It will return the result.
		 *
		 *	The function used is the Logistic Sigmoid Function, denoted logsig:
		 *		logsig(val) = (1 / (1 + e^(-val)))
		 *		
		 *	\param	double val
		 *	\return	double result
		 */
		virtual double function(double val);
		
		//!	Takes the value given and passes it into the derivative of this function.
		/*!
		 *	This function will take the given value and pass it into this function's
		 *	derivative.  It will return the result.
		 *
		 *	The derivative of the Logistic Sigmoid Function, denoted logsig`:
		 *		logsig`(val) = (logsig(val))*(1-logsig(val))
		 *
		 *	\param	double val
		 *	\return double result
		 */
		virtual double function_derivative(double val);
		
		//!	Returns the object type as a C++ standard string object.
		/*!
		 *	This function returns the class name as a string object.
		 *	This is to allow type checking if it is necessary.
		 *
		 *	\param	void
		 *	\return	string 'sigmoid'
		 */
		virtual std::string get_type();
		
		//!	Returns the current reference count for sigmoid.
		/*!
		 *	This function returns the current number of references to this
		 *	object.
		 *
		 *	\param	void
		 *	\return	unsigned int[current reference count]
		 *	\sa		Singleton.h
		 */
		virtual unsigned int get_reference_counter();
};

#endif