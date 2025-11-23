#pragma once

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkPredictionConfigurations
	{
		std::string model_name;

		std::vector<std::vector<bool>> inputs;
	};
}
