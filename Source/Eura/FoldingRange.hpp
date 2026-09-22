// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_folding_range
#define lyrix_header_guard_eura_folding_range
#include "Eura/Json.hpp"
#include "Eura/FoldingRangeKind.hpp"

namespace Eura
{
    struct [[nodiscard]] FoldingRange final
    {
        std::uint32_t startLine;

        std::optional<std::uint32_t> startCharacter;

        std::uint32_t endLine;

        std::optional<std::uint32_t> endCharacter;

        std::optional<FoldingRangeKind> kind;

        std::optional<std::string> collapsedText;
    };

    auto from_json(const nlohmann::json& object, FoldingRange& folding_range) noexcept -> void;

    auto to_json(nlohmann::json& object, const FoldingRange& folding_range) noexcept -> void;
}

#endif
#endif