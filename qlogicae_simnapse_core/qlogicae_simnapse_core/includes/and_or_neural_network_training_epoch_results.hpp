#pragma once

#include "and_or_neural_network_training_configurations.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingEpochResults
	{
		size_t current_epoch = 0;

		double bias = 0;

		double sum = 0;

		double pred = 0;

		double error = 0;

		std::vector<double> weights = {};

		std::string timestamp_started = "";

		std::string timestamp_ended = "";
	};
}
