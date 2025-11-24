#pragma once

namespace QLogicaeSimNapseCore
{
	struct AndOrNeuralNetworkTrainingEpochResults
	{
		size_t current_epoch = 0;

		double bias = 0.0;

		std::vector<int> predictions = { 0, 0, 0, 0 };

		std::vector<int> errors = { 0, 0, 0, 0 };

		std::vector<double> weights = { 0.0, 0.0 };

		double timestamp_started = 0.0;

		double timestamp_ended = 0.0;
	};
}
