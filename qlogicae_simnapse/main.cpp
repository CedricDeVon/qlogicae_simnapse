#include "pch.hpp"

#include "main.hpp"

int main(
    int argc,
    char *argv[]
)
{
    QLogicaeCore::QLOGICAE_APPLICATION.setup();
    QLogicaeSimNapse::UTILITIES.setup();

    QApplication app(argc, argv);

    QLogicaeSimNapse::Application window;
    window.show();
    
    bool exit_code = app.exec();
    QLogicaeCore::QLOGICAE_APPLICATION.terminate();

    return exit_code;
}

namespace QLogicaeSimNapse
{

}
