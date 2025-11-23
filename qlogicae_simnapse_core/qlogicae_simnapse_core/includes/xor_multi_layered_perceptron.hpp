#pragma once

#include "qlogicae_core/includes/result.hpp"

namespace QLogicaeSimNapseCore
{
    class XORMultiLayeredPerceptron
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

        static XORMultiLayeredPerceptron& get_instance();

        static void get_instance(
            QLogicaeCore::Result<XORMultiLayeredPerceptron*>& result
        );

    protected:
        XORMultiLayeredPerceptron();

        ~XORMultiLayeredPerceptron();

        XORMultiLayeredPerceptron(
            const XORMultiLayeredPerceptron& instance
        ) = default;

        XORMultiLayeredPerceptron(
            XORMultiLayeredPerceptron&& instance
        ) noexcept = delete;

        XORMultiLayeredPerceptron& operator = (
            XORMultiLayeredPerceptron&& instance
            ) = default;

        XORMultiLayeredPerceptron& operator = (
            const XORMultiLayeredPerceptron& instance
            ) = delete;
    };

    inline static XORMultiLayeredPerceptron& XOR_MULTI_LAYERED_PERCEPTRON =
        XORMultiLayeredPerceptron::get_instance();
}
