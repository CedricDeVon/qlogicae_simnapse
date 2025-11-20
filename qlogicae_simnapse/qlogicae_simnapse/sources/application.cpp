#include "pch.hpp"

#include "../includes/application.hpp"

namespace QLogicaeSimNapse
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
