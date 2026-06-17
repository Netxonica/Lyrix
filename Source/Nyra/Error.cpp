// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Error.hpp"
#include <print>
#include "Lumina/Style.hpp"

namespace Nyra
{
    Error::Error(const std::size_t code) noexcept : Lumina::Error(code){}

    Error::Error(const std::size_t code, const std::string_view command) noexcept : Lumina::Error(
    code), m_command(command){}

    Error::Error(const std::size_t code, const std::string_view command, const std::string_view
    base) noexcept : Lumina::Error(code), m_command(command), m_base(base){}

    auto Error::Report() const noexcept -> void
    {
        auto Print = [&](const std::string_view message)
        {
            std::println(stderr, "{}{}Lyrix{} {}{}error[nyra{}]{}{} ->{} {}", Lumina::Style::Italic
            , Lumina::Style::Bold, Lumina::Style::Normal, Lumina::Style::Problem, Lumina::Style::
            Bold, code(), Lumina::Style::Normal, Lumina::Style::Data, Lumina::Style::Normal,
            message);
        };
        switch(code())
        {
            case 1uz:
                Print("too many arguments provided");
            break;
            case 2uz:
                Print("no arguments provided");
            break;
            case 3uz:
            {
                std::string message{"expected the "};
                message += Lumina::Style::Bold;
                message += Lumina::Style::Italic;
                message += Lumina::Style::Path;
                message += "NAME";
                message += Lumina::Style::Normal;
                message += " to create the project";
                Print(message);
            }
            break;
            case 4uz:
            {
                std::string message{"expected the "};
                message += Lumina::Style::Bold;
                message += Lumina::Style::Italic;
                message += Lumina::Style::Path;
                message += "NAME";
                message += Lumina::Style::Normal;
                message += " to compile the project";
                Print(message);
            }
            break;
            case 5uz:
            {
                std::string message{"unrecognized command "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                Print(message);
            }
            break;
            case 6uz:
            {
                std::string message{"unexpected argument "};
                message += Lumina::Style::Path;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " for the ";
                message += Lumina::Style::Data;
                message += "help";
                message += Lumina::Style::Normal;
                message += " command";
                Print(message);
            }
            break;
            case 7uz:
            {
                std::string message{"unexpected argument "};
                message += Lumina::Style::Path;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " for the ";
                message += Lumina::Style::Data;
                message += "version";
                message += Lumina::Style::Normal;
                message += " command";
                Print(message);
            }
            break;
            case 8uz:
            {
                std::string message{"unexpected argument "};
                message += Lumina::Style::Path;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " for the ";
                message += Lumina::Style::Data;
                message += "lsp";
                message += Lumina::Style::Normal;
                message += " command";
                Print(message);
            }
            break;
            case 9uz:
            {
                std::string message = "the project creation failed because the ";
                message += Lumina::Style::Bold;
                message += Lumina::Style::Italic;
                message += Lumina::Style::Path;
                message += "NAME ";
                message += Lumina::Style::Normal;
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " is invalid";
                Print(message);
            }
            break;
            case 10uz:
            {
                std::string message = "the project compilation failed because the ";
                message += Lumina::Style::Bold;
                message += Lumina::Style::Italic;
                message += Lumina::Style::Path;
                message += "NAME ";
                message += Lumina::Style::Normal;
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " is invalid";
                Print(message);
            }
            break;
            case 11uz:
            {
                std::string message{"reading the file "};
                message += Lumina::Style::Path;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " failed";
                Print(message);
            }
            break;
            case 12uz:
                Print("couldn't retrieve the host information");
            break;
            case 13uz:
                Print("unknown host architecture");
            break;
            case 14uz:
                Print("unknown host system");
            break;
            case 15uz:
            {
                std::string message{"the project "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " couldn't be created because getting the number of jobs failed";
                Print(message);
            }
            break;
            case 16uz:
            {
                std::string message{"the project "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " couldn't be created because ";
                message += Lumina::Style::Path;
                message += m_base;
                message += Lumina::Style::Normal;
                message += " already exists";
                Print(message);
            }
            break;
            case 17uz:
            {
                std::string message{"the project creation of "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " failed because the Orion folder ";
                message += Lumina::Style::Path;
                message += m_base;
                message += Lumina::Style::Normal;
                message += " couldn't be created";
                Print(message);
            }
            break;
            case 18uz:
            {
                std::string message{"the project creation of "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " failed because the Elyra file ";
                message += Lumina::Style::Path;
                message += m_base;
                message += Lumina::Style::Normal;
                message += " couldn't be created";
                Print(message);
            }
            break;
            case 19uz:
            {
                std::string message{"the compilation for "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " failed because the Orion folder ";
                message += Lumina::Style::Path;
                message += m_base;
                message += Lumina::Style::Normal;
                message += " doesn't exist";
                Print(message);
            }
            break;
            case 20uz:
                std::string message{"the compilation for "};
                message += Lumina::Style::Data;
                message += m_command;
                message += Lumina::Style::Normal;
                message += " failed because the Elyra file ";
                message += Lumina::Style::Path;
                message += m_base;
                message += Lumina::Style::Normal;
                message += " doesn't exist";
                Print(message);
        }
    }
}

#endif