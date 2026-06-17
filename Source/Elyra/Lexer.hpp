// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_elyra_lexer
#define lyrix_header_guard_elyra_lexer
#include <memory>
#include <expected>
#include "Elyra/Error.hpp"

namespace Elyra
{
    [[nodiscard]] auto Lexer(const std::string_view content) noexcept -> std::expected<int, std::
    unique_ptr<Error>>;
}

#endif
#endif