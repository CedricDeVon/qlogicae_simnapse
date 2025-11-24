#pragma once

#include "and_or_neural_network_training_epoch_results.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingConfigurations
	{
		std::string name = "";
		
		size_t maximum_learning_epoch = 100;

		std::vector<std::vector<int>> inputs = {};

		std::vector<int> outputs = {};

		std::vector<double> weights = { 0.0, 0.0 };

		double bias = 0.0;

		double learning_rate = 2.0;

		std::function<void(const AndOrNeuralNetworkTrainingEpochResults&)> callback =
			[](const AndOrNeuralNetworkTrainingEpochResults& result) {};
	};
}
