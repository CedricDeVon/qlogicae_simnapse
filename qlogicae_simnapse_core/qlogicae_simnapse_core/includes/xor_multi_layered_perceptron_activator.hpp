#pragma once

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapseCore
{
    class XORMultiLayeredPerceptronActivator
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



        double get_sigmoid_activation(
            const double& x
        );

        void get_sigmoid_activation(
            QLogicaeCore::Result<double>& result,
            const double& x
        );

        std::future<double> get_sigmoid_activation_async(
            const double& x
        );

        void get_sigmoid_activation_async(
            const std::function<void(const double& result)>& callback,
            const double& x
        );

        void get_sigmoid_activation_async(
            QLogicaeCore::Result<std::future<double>>& result,
            const double& x
        );

        void get_sigmoid_activation_async(
            const std::function<void(QLogicaeCore::Result<double>& result)>& callback,
            const double& x
        );



        double get_sigmoid_derivative(
            const double& x
        );

        void get_sigmoid_derivative(
            QLogicaeCore::Result<double>& result,
            const double& x
        );

        std::future<double> get_sigmoid_derivative_async(
            const double& x
        );

        void get_sigmoid_derivative_async(
            const std::function<void(const double& result)>& callback,
            const double& x
        );

        void get_sigmoid_derivative_async(
            QLogicaeCore::Result<std::future<double>>& result,
            const double& x
        );

        void get_sigmoid_derivative_async(
            const std::function<void(QLogicaeCore::Result<double>& result)>& callback,
            const double& x
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

        static XORMultiLayeredPerceptronActivator& get_instance();

        static void get_instance(
            QLogicaeCore::Result<XORMultiLayeredPerceptronActivator*>& result
        );

    protected:
        XORMultiLayeredPerceptronActivator();

        ~XORMultiLayeredPerceptronActivator();

        XORMultiLayeredPerceptronActivator(
            const XORMultiLayeredPerceptronActivator& instance
        ) = default;

        XORMultiLayeredPerceptronActivator(
            XORMultiLayeredPerceptronActivator&& instance
        ) noexcept = delete;

        XORMultiLayeredPerceptronActivator& operator = (
            XORMultiLayeredPerceptronActivator&& instance
            ) = default;

        XORMultiLayeredPerceptronActivator& operator = (
            const XORMultiLayeredPerceptronActivator& instance
            ) = delete;
    };

    inline static XORMultiLayeredPerceptronActivator& XOR_MULTI_LAYERED_PERCEPTRON_ACTIVATOR =
        XORMultiLayeredPerceptronActivator::get_instance();
}
