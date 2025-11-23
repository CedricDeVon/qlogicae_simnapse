#pragma once

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingConfigurations
	{
		std::string model_name = "";
		
		std::vector<std::vector<bool>> inputs = {};

		std::vector<bool> outputs = {};

		std::vector<double> model_weights = {};

		double model_bias = 0;

		double model_learning_rate = 2.0;

		size_t maximum_learning_epoch = 1000;
	};
}
