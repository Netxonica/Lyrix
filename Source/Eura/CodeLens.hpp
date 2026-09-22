// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_lens
#define lyrix_header_guard_eura_code_lens
#include "Eura/Range.hpp"
#include "Eura/Command.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeLens final
    {
        Range range;

        std::optional<Command> command;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, CodeLens& code_lens) noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeLens& code_lens) noexcept -> void;
}

#endif
#endif