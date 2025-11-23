#pragma once

#include "xor_multi_layered_perceptron.hpp"
#include "xor_multi_layered_perceptron_activator.hpp"
#include "xor_multi_layered_perceptron_training_data.hpp"
#include "xor_multi_layered_perceptron_prediction_data.hpp"

#include "qlogicae_core/includes/result.hpp"

namespace QLogicaeSimNapseCore
{
    class XORNeuralNetwork
    {
    public:
        bool setup();

        void setup(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> setup_async();

        void setup_async(
            const std::function<void(const bool& result)>& callback
        );

        void setup_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void setup_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );



        bool terminate();

        void terminate(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> terminate_async();

        void terminate_async(
            const std::function<void(const bool& result)>& callback
        );

        void terminate_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void terminate_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );

        static XORNeuralNetwork& get_instance();

        static void get_instance(
            QLogicaeCore::Result<XORNeuralNetwork*>& result
        );

    protected:
        XORNeuralNetwork();

        ~XORNeuralNetwork();

        XORNeuralNetwork(
            const XORNeuralNetwork& instance
        ) = default;

        XORNeuralNetwork(
            XORNeuralNetwork&& instance
        ) noexcept = delete;

        XORNeuralNetwork& operator = (
            XORNeuralNetwork&& instance
            ) = default;

        XORNeuralNetwork& operator = (
            const XORNeuralNetwork& instance
            ) = delete;
    };

    inline static XORNeuralNetwork& XOR_NEURAL_NETWORK =
        XORNeuralNetwork::get_instance();
}
