#include "pch.hpp"

#include "../includes/application.hpp"

namespace QLogicaeVS2022QtDesktop
{
    Application::Application(QWidget* parent)
        : QMainWindow(parent)
    {
        _ui.setupUi(this);
    }

    Application::~Application()
    {

    }
}
