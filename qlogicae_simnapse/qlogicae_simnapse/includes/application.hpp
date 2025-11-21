#pragma once

#include "splash.hpp"
#include "loading.hpp"
#include "main_menu.hpp"

#include "ui_application.h"

namespace QLogicaeSimNapse
{
    class Application :
        public QMainWindow
    {
        Q_OBJECT

    public:
        Application(
            QWidget* parent = nullptr
        );
        ~Application();

    private:
        Ui::ApplicationClass _ui;

        MainMenu* _main_menu_widget;
        Splash* _splash_widget;
        Loading* _loading_widget;

        void _setup_assets();
        void _setup_widgets();
        void _setup_window_screen();
        void _change_screen_type(uint8_t index);
    };
}
