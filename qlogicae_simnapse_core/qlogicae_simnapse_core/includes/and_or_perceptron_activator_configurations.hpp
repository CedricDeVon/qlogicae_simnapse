#pragma once

namespace QLogicaeSimNapseCore
{
	struct AndOrPerceptronActivatorConfigurations
	{		
		std::vector<int> inputs = {};

		std::vector<double> model_weights = {};

		double model_bias = 0;
	};
}
