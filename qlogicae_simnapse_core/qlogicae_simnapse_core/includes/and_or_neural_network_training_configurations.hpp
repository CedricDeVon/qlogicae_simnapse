#pragma once

#include "and_or_neural_network_training_epoch_results.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingConfigurations
	{
		std::string model_name = "";
		
		std::vector<std::vector<int>> inputs = {};

		std::vector<int> outputs = {};

		double model_bias = 0.0;

		double model_learning_rate = 2.0;

		size_t maximum_learning_epoch = 100;

		std::function<void(const AndOrNeuralNetworkTrainingEpochResults&)> callback =
			[](const AndOrNeuralNetworkTrainingEpochResults& result) {};

		std::vector<double> model_weights = { 0.0, 0.0 };
	};
}
