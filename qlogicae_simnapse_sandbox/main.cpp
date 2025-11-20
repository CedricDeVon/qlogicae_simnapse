#include "pch.hpp"

#include "main.hpp"

int main(int argc, char** argv)
{    
    QLogicaeSimNapseCore::sample();

    std::cout << "Enter to exit...\n";

    bool exit_code;
    std::cin >> exit_code;

    return 0;
}

namespace QLogicaeSimNapseSandbox
{

}
