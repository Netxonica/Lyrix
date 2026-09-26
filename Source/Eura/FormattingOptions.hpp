// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_formatting_options
#define lyrix_header_guard_eura_formatting_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] FormattingOptions final
    {
        std::uint32_t tabSize;

        bool insertSpaces;

        std::optional<bool> trimTrailingWhitespace, insertFinalNewline, trimFinalNewlines;

        std::unordered_map<std::string, std::variant<bool, std::int32_t, std::string>> optional; // optional
    };

    auto from_json(const nlohmann::json& object, FormattingOptions& formatting_options) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const FormattingOptions& formatting_options) noexcept ->
    void;
}

#endif
#endif