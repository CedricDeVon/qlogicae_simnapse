#pragma once

#include "and_or_neural_network_training_epoch_results.hpp"
#include "and_or_neural_network_training_configurations.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingResults
	{
		std::vector<AndOrNeuralNetworkTrainingEpochResults> epoch_results = {};

		std::string timestamp_started = "";

		std::string timestamp_ended = "";

		AndOrNeuralNetworkTrainingConfigurations configurations = {};
	};
}
