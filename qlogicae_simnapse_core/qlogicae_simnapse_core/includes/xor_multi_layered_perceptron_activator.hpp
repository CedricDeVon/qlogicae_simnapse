#pragma once

#include "qlogicae_core/includes/result.hpp"

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
