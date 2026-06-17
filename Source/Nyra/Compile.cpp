// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Compile.hpp"
#include "Nyra/File.hpp"
#include "Nyra/Orion.hpp"
#include "Elyra/Lexer.hpp"
#include "Eura/Server.hpp"

namespace Nyra
{
    auto Compile(const std::string_view name) noexcept -> void
    {
        const std::optional<Orion> project = Orionify(name);
        if(project.has_value())
        {
            const std::optional<std::string> content = File::Read(project->Elyra());
            if(content.has_value())
            {
                std::expected<int, std::unique_ptr<Elyra::Error>> lexer = Elyra::Lexer(*content);
                if(not lexer.has_value())
                {
                    *lexer.error() = project->Elyra();
                    lexer.error()->Report();
                }
                else
                {
                    Eura::Listen();
                }
            }
        }
    }
}

#endif