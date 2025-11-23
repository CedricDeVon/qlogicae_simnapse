#pragma once

#include "and_or_perceptron_activator_configurations.hpp"
#include "and_or_neural_network_training_configurations.hpp"

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapseCore
{
    class AndOrPerceptronActivator
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



        bool get_activation(
            const AndOrPerceptronActivatorConfigurations& configurations
        );

        void get_activation(
            QLogicaeCore::Result<bool>& result,
            const AndOrPerceptronActivatorConfigurations& configurations
        );

        std::future<bool> get_activation_async(
            const AndOrPerceptronActivatorConfigurations& configurations
        );

        void get_activation_async(
            const std::function<void(const bool& result)>& callback,
            const AndOrPerceptronActivatorConfigurations& configurations
        );

        void get_activation_async(
            QLogicaeCore::Result<std::future<bool>>& result,
            const AndOrPerceptronActivatorConfigurations& configurations
        );

        void get_activation_async(
            const std::function<void(QLogicaeCore::Result<bool>& result)>& callback,
            const AndOrPerceptronActivatorConfigurations& configurations
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

        static AndOrPerceptronActivator& get_instance();

        static void get_instance(
            QLogicaeCore::Result<AndOrPerceptronActivator*>& result
        );

    protected:
        AndOrPerceptronActivator();

        ~AndOrPerceptronActivator();

        AndOrPerceptronActivator(
            const AndOrPerceptronActivator& instance
        ) = default;

        AndOrPerceptronActivator(
            AndOrPerceptronActivator&& instance
        ) noexcept = delete;

        AndOrPerceptronActivator& operator = (
            AndOrPerceptronActivator&& instance
            ) = default;

        AndOrPerceptronActivator& operator = (
            const AndOrPerceptronActivator& instance
            ) = delete;
    };

    inline static AndOrPerceptronActivator& XOR_MULTI_LAYERED_PERCEPTRON_ACTIVATOR =
        AndOrPerceptronActivator::get_instance();
}
