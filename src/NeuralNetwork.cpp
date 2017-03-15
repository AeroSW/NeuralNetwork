neural_network::neural_network(uint * blueprint, uint bp_sze, func_id fid):
num_layers(bp_size){
	structure = new uint[num_layers];
	for(uint cx = 0; cx < num_layers; cx++){
		structure[cx] = blueprint[cx];
		for(uint dx = 0; dx < structure[cx]; dx++){
			uint num_weights = 1;
			if(cx > 0){
				num_weights = structure[cx-1];
			}
			neuron node(num_weights, 0.0, fid);
			neurons.push_back(node);
		}
	}
}

neural_network::neural_network(const neural_network &net):
num_layers(net.num_layers), neurons(net.neurons){
	structure = new uint[num_layers];
	for(uint cx = 0; cx < num_layers; cx++){
		structure[cx] = net.structure[cx];
	}
}

neural_network::~neural_network(){
	delete[] structure;
}

matrix neural_network::feed(matrix &inputs){
	// Check if it is a row or column vector.
	uint num_inputs = inputs.row_count() * inputs.col_count();
	if(num_inputs != structure[0]) throw neural_network_error();
	for(uint cx = 0; cx < num_inputs; cx++){
		neurons[cx].set_value(inputs.get_elem(cx));
	}
	for(uint al = 1; al < num_layers; al++){
		uint start = 0;
		for(uint cx = 0; cx < al-1; cx++) start += structure[cx];
		uint end = start + structure[al];
		double * inputs_array = new double[structure[al-1]];
		for(uint cx = start; cx < end; cx++){
			inputs_array[cx - start] = neurons[cx].get_value();
		}
		matrix input(1, structure[al], inputs_array);
		delete[] inputs_array;
		start = 0;
		for(uint cx = 0; cx < al; cx++) start += structure[cx];
		if(al != num_layers-1){
			end = start + structure[al+1];
		}
		else{
			end = neurons.size();
		}
		for(uint cx = start; cx < end; cx++){
			neurons[cx]->feed(input);
		}
	}
	uint start = 0;
	for(uint cx = 0; cx < num_layers; cx++) start += structure[cx];
	uint end = neurons.size();
	uint num_outputs = structure[num_layers-1];
	matrix output(num_outputs, 1);
	for(uint cx = start; cx < end; cx++){
		output.set_elem(cx-start, neurons[start].get_value());
	}
	return output;
}

