#pragma once

#include "and_or_neural_network_training_epoch_results.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingResults
	{
		std::vector<AndOrNeuralNetworkTrainingEpochResults> epoch_results =
			std::vector<AndOrNeuralNetworkTrainingEpochResults>();

		double timestamp_started = 0.0;

		double timestamp_ended = 0.0;
	};
}
