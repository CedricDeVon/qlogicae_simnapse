#include "pch.hpp"

#include "main.hpp"

int main(
    int argc,
    char *argv[]
)
{
    QLogicaeCore::QLOGICAE_APPLICATION.setup();

    QApplication app(argc, argv);

    QLogicaeSimNapse::Application window;
    window.show();
    
    return app.exec();
}

namespace QLogicaeSimNapse
{

}
