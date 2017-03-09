#ifndef NEURON_H
#define NEURON_H

#include "TransferFunction.h"
#include "FunctionHandler.h"

#include <string>
#include <memory>
#include "Matrix.h"
#include "TypeDefs.h"
#include "TransferFunction.h"
#include "FunctionHandler.h"

//!	neuron class
/*!	\class neuron
 *	\brief An object which acts similar to a neuron in the brain.
 *
 *	A class representing the basic functionality of a neuron.  It
 *	is used in collection in a neural network class.  It takes
 *	inputs in the form of a matrix and produces an output which
 *	is a signal determining whether a signal was strong enough
 *	to invoke some action.
 */
class neuron{
	private:
		double bias; //! bias represents the latent bias in your thought process.
		matrix weights; //! weights which will determine how strong each input feeding into your thoughts.
		transfer_function * function; //! The function which will determine the action being taken.
		double value; //! The value which the result of the function will be stored.
		
	public:
		//!	Constructor
		/*!
		 *	The constructor which creates the neuron object for use.
		 *
		 *	\param	num_weights	The number of weights which this neuron will have.
		 *	\param	bias		The bias present when this neuron feeds on inputs.
		 *	\param	fid			The function ID which this neuron uses for decisions.
		 */
		neuron(uint num_weights, double bias, func_id fid);
		//!	Copy Constructor
		/*!
		 *	The constructor which sets this neuron to be a copy of a previously generated neuron.
		 *
		 *	\param	n	The neuron you are making a copy of.
		 */
		neuron(const neuron &n);
		//!	Virtual Destructor
		/*!
		 *	The destructor which will free up memory in this object.
		 */
		virtual ~neuron();
		
		//!	A function which returns the result from the inputs being fed.
		/*!
		 *	The function takes the given inputs and multiplies them by the weights and
		 *	adds the bias to the given result.  It then feeds this summation into the
		 *	the decision function.  It sets the neuron's value to the result of the
		 *	decision function and returns the result as well.
		 *
		 *	\param	mat	A matrix representation of the inputs.
		 *	\return	A double representation of the result from feeding the inputs.
		 *	\sa		neuron
		 */
		virtual double feed(matrix &mat);
		//!	A function which returns the function's derivative's result.
		/*!
		 *
		 */
		virtual double invert();
		
		//!	A function to retrieve this neuron's bias.
		/*!
		 *	This function returns the bias for this neuron instance.
		 *
		 *	\param	void
		 *	\return	double	The bias for this neuron instance is returned.
		 *	\sa		neuron
		 */
		virtual double get_bias();
		
		//!	A function to retrieve an input's weight.
		/*!
		 *	This function retrieves an input's weight based on the index
		 *	of the input when it is passed into this neuron instance.
		 *
		 *	\param	index	The input's index for which weight being retrieved.
		 *	\return	double	The weight for the input's index.
		 */
		virtual double get_weight(uint index);
		//!	A function to retrieve the weights for this neuron instance.
		/*!
		 *	A function which retrieve's this neuron instance's weights.  Weights are
		 *	returned in a column matrix format, [nx1] where n is the number of inputs
		 *	into this neuron.
		 *
		 *	\param	void
		 *	\return	matrix	The grouping of weights.
		 */
		virtual matrix get_weights();
		
		//!	A function which sets this neuron's bias to a set value.
		/*!
		 *	A function allowing the ability to change the bias's default
		 *	value.
		 *
		 *	\param	b	The bias which you wish to set the value to.
		 *	\return	void
		 */
		virtual void set_bias(double b);
		
		//!	A function allowing the setting of a weight based on input index.
		/*!
		 *	A function which allows the weights of individual inputs to be
		 *	adjusted.
		 *	
		 *	\param	index	The input's index which you wish to adjust the weight for.
		 *	\param	wt	The weight you wish to apply to this input.
		 *	\return	void
		 */
		virtual void set_weight(uint index, double wt);
		//!	A function allowing the changing of all weights in this neuron.
		/*!
		 *	The function which allows changing of all weights easily for this
		 *	neuron instance.  It takes the weights as a double array.  The
		 *	weights in the matrix will then be adjusted to the array's values.
		 *
		 *	The indices in the array correspond to the indices of the inputs
		 *	being applied to the weights.
		 *
		 *	\param	wts	The array of weights to be used
		 *	\param	num	The number of items in the array.
		 *	\return	void
		 *	\exception	neuron_weight_error	An error adjusting the weights occurred.
		 */
		virtual void set_weights(double * wts, uint num);
		//!	A function allowing the changing of all weights in this neuron.
		/*!
		 *	A funtion which allows the changing of all weights easily for this
		 *	neuron instance.  It takes the weights as a matrix.  The weights in
		 *	the matrix will then be set to the new matrix's values.
		 *
		 *	The matrix must be either a column or row vector.  The position in the
		 *	matrix will correspond to the inputs they will be applied to.
		 *
		 *	\param	matr	The matrix containing the weights you wish to set the values to.
		 *	\return	void
		 *	\exception	neuron_weight_error	An error adjusting the weights occurred.
		 */
		virtual void set_weights(matrix &matr);
		
		//!	A function which returns the number of inputs for this neuron instance.
		/*!
		 *	A fuction which will return the number of inputs which are to be fed into
		 *	this neuron instance.
		 *
		 *	\param	void
		 *	\return	uint	The number of inputs.
		 */
		virtual uint num_inputs();
};

#endif