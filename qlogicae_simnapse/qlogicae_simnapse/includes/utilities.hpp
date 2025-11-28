#pragma once

#include "assembly.hpp"

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/utilities.hpp"

namespace QLogicaeSimNapse
{
    class Utilities
    {
    public:       
        int DEFAULT_EVALUATION_CURRENT_EPOCH;

        int DEFAULT_EVALUATION_FINAL_EPOCH;

        int DEFAULT_EVALUATION_SLIDER_VALUE;

        int DEFAULT_SETTINGS_SCREEN_TYPE;

        std::string DEFAULT_EVALUATION_ERROR_RATE;

        std::vector<std::vector<std::string>> DEFAULT_EVALUATION_TABLE;

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


        static Utilities& get_instance();

        static void get_instance(
            QLogicaeCore::Result<Utilities*>& result
        );

    protected:
        Utilities();

        ~Utilities();

        Utilities(
            const Utilities& instance
        ) = default;

        Utilities(
            Utilities&& instance
        ) noexcept = delete;

        Utilities& operator = (
            Utilities&& instance
            ) = default;

        Utilities& operator = (
            const Utilities& instance
            ) = delete;
    };

    inline static Utilities& UTILITIES =
        Utilities::get_instance();
}
