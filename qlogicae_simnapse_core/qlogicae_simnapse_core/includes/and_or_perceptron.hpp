#pragma once

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapseCore
{
    class AndOrPerceptron
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

        static AndOrPerceptron& get_instance();

        static void get_instance(
            QLogicaeCore::Result<AndOrPerceptron*>& result
        );

    protected:
        AndOrPerceptron();

        ~AndOrPerceptron();

        AndOrPerceptron(
            const AndOrPerceptron& instance
        ) = default;

        AndOrPerceptron(
            AndOrPerceptron&& instance
        ) noexcept = delete;

        AndOrPerceptron& operator = (
            AndOrPerceptron&& instance
            ) = default;

        AndOrPerceptron& operator = (
            const AndOrPerceptron& instance
            ) = delete;
    };

    inline static AndOrPerceptron& XOR_MULTI_LAYERED_PERCEPTRON =
        AndOrPerceptron::get_instance();
}
