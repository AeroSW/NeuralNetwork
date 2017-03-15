#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Neuron.h"
#include "Matrix.h"
#include "TypeDefs.h"

#include <vector>
#include <string>

namespace AeroSW{
	class neural_network{
		private:
			std::vector<neuron> neurons;
			uint * structure;
			uint structure_size;
			
		public:
			neural_network(uint * blueprint, uint bp_sze);
			neural_network(const neural_network &net);
			~neural_network();
			
			matrix feed(matrix &inputs);
			
			double get_neuron_bias(uint l_index, uint n_index);
			double get_neuron_weight(uint l_index, uint n_index, uint w_index);
			matrix get_neuron_weights(uint l_index, uint n_index);
			
			void set_neuron_bias(uint l_index, uint n_index, double b);
			void set_neuron_weight(uint l_index, uint n_index, uint w_index, double wt);
			void set_neuron_weights(uint l_index, uint n_index, matrix &new_wts);
			
			uint num_layers();
			uint num_neurons();
			uint num_neurons(uint l_index);
	};
}

#endif