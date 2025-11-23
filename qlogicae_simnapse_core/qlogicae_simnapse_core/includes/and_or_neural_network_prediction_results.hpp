#pragma once

#include "and_or_neural_network_prediction_configurations.hpp"

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkPredictionResults
	{
		bool data = 0;

		std::string timestamp_started = "";

		std::string timestamp_ended = "";

		AndOrNeuralNetworkPredictionConfigurations configurations = {};
	};
}
