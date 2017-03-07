#ifndef HYPERBOLICTANGENTFUNCTION_H
#define HYPERBOLICTANGENTFUNCTION_H

//! File Information
/*!
	\file HyperbolicTangentFunction.h
	Author:	Kenneth Cornett, student at Tennessee Tech University
	Date:	March 3, 2017
	Contains the skeleton for a hyperbolic_tangent object.
 */

#include "TransferFunction.h"

//!	hyperbolic_tangent class
/*!	\class hyperbolic_tangent
 *	\brief A class which implements the hyperbolic tangent function.
 *	
 *	A class which is used to add the hyperbolic tangent function to
 *	other objects which need to use it.  The class uses the singleton
 *	design pattern since a single object reference is returned to all
 *	objects needing to use the hyperbolic tangent function.  It is
 *	appropriate to use this design pattern, since, this object does
 *	not store information.
 */
class hyperbolic_tangent : public transfer_function{
	private:
		const std::string type = "hyperbolic_tangent";
		//!	Private Constructor
		/*!
		 *	A private constructor to enforce factory
		 *	and singleton design patterns for this
		 *	program.
		 */
		hyperbolic_tangent();
		
		static hyperbolic_tangent * hyptan;
	
	protected:
		//!	A virtual destructor
		/*!
		 *	This destructor destroys information in the inheritance
		 *	heirarchy for hyperbolic_tangent()
		 */
		virtual ~hyperbolic_tangent();
	
	public:
		//!	A function which returns a pointer to the hyperbolic_tangent object.
		/*!
		 *	This function returns a pointer to a static 
		 *	hyperbolic_tangent object.
		 *	
		 *	\param	void
		 *	\return	pointer to a hyperbolic_tangent object.
		 *	\sa		hyperbolic_tangent()
		 */
		static hyperbolic_tangent * get_hyperbolic_tangent();
		
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
		 *	The function used is the Hyperbolic Tangent Function, denoted hyptan:
		 *		hyptan(val) = (e^(val)-e^(-val))/(e^(val)+e^(-val))
		 *		
		 *	\param	double val
		 *	\return	double result
		 */
		virtual double function(double val);
		
		//!	Takes the value given and passes it into the derivative of this function.
		/*!
		 *	This function will take the given value and pass it into the derivative
		 *	of the hyperbolic tangent function.  It will return the result.
		 *
		 *	The derivative of the Hyperbolic Tangent Function, denoted hyptan`:
		 *		hyptan`(val) = 1 - square(hyptan(val))
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
		 *	\return	string 'hyperbolic_tangent'
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