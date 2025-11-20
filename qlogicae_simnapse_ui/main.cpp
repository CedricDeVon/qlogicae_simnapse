#include "pch.hpp"

#include "main.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLogicaeVS2022QtDesktop::Application window;
    window.show();
    
    return app.exec();
}

namespace QLogicaeVS2022QtDesktop
{

}
