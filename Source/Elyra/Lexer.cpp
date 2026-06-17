// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Elyra/Lexer.hpp"
#include <print>

namespace Elyra
{
    [[nodiscard]] auto Lexer(const std::string_view content) noexcept -> std::expected<int, std::
    unique_ptr<Error>>
    {
        std::print("{}", content);
        return content[0];
    }
}

#endif