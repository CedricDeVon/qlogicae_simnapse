#pragma once

namespace QLogicaeSimNapseCore
{
	struct AndOrPerceptronActivatorConfigurations
	{		
		std::vector<int> inputs = {};

		std::vector<double> weights = {};

		double bias = 0;
	};
}
