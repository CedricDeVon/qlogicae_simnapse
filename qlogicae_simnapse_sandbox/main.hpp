#pragma once

#include "qlogicae_simnapse_sandbox/includes/application.hpp"

#include "qlogicae_simnapse_core/includes/and_or_neural_network_configurations.hpp"
#include "qlogicae_simnapse_core/includes/and_or_perceptron_activator_configurations.hpp"

#include "qlogicae_simnapse_core/includes/and_or_neural_network_training_epoch_results.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_training_configurations.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_training_results.hpp"

#include "qlogicae_simnapse_core/includes/and_or_neural_network_prediction_configurations.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network_prediction_results.hpp"

#include "qlogicae_simnapse_core/includes/and_or_perceptron_activator.hpp"
#include "qlogicae_simnapse_core/includes/and_or_perceptron.hpp"
#include "qlogicae_simnapse_core/includes/and_or_neural_network.hpp"

#include "qlogicae_core/includes/all.hpp"

int main(int, char**);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE,
    LPSTR,
    int
)
{
    return main(__argc, __argv);
}

namespace QLogicaeSimNapseSandbox
{

}
