// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/CLI.hpp"
#include <memory>
#include "Nyra/Help.hpp"
#include "Nyra/Error.hpp"
#include "Nyra/Create.hpp"
#include "Eura/Server.hpp"
#include "Nyra/Compile.hpp"
#include "Nyra/Version.hpp"
#include "Nyra/Identifier.hpp"

namespace Nyra::CLI
{
    auto Process(int argc, char** argv) noexcept -> void
    {
        switch(argc)
        {
            default:
                std::make_unique<Error>(1uz)->Report();
                Help();
            break;
            case 0:
            case 1:
                std::make_unique<Error>(2uz)->Report();
                Help();
            break;
            case 2:
            {
                const std::string_view command{argv[1]};
                if(command == "create")
                {
                    std::make_unique<Error>(3uz)->Report();
                    Help();
                }
                else if(command == "compile")
                {
                    std::make_unique<Error>(4uz)->Report();
                    Help();
                }
                else if(command == "help")
                    Help();
                else if(command == "version")
                    Version();
                else if(command == "lsp")
                    Eura::Listen();
                else
                {
                    std::make_unique<Error>(5uz, command)->Report();
                    Help();
                }
            }
            break;
            case 3:
                const std::string_view command{argv[1]}, name{argv[2]};
                if(command == "help")
                {
                    std::make_unique<Error>(6uz, name)->Report();
                    Help();
                }
                else if(command == "version")
                {
                    std::make_unique<Error>(7uz, name)->Report();
                    Help();
                }
                else if(command == "lsp")
                {
                    std::make_unique<Error>(8uz, name)->Report();
                    Help();
                }
                else if(command == "create")
                {
                    if(Identifier(name))
                        Create(name);
                    else
                    {
                        std::make_unique<Error>(9uz, name)->Report();
                        Help();
                    }
                }
                else if(command == "compile")
                {
                    if(Identifier(name))
                        Compile(name);
                    else
                    {
                        std::make_unique<Error>(10uz, name)->Report();
                        Help();
                    }
                }
                else
                {
                    std::make_unique<Error>(5uz, command)->Report();
                    Help();
                }
        }
    }
}

#endif