// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item_defaults
#define lyrix_header_guard_eura_completion_item_defaults
#include "Eura/InsertTextMode.hpp"
#include "Eura/InsertTextFormat.hpp"
#include "Eura/EditRangeWithInsertReplace.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionItemDefaults final
    {
        std::optional<std::vector<std::string>> commitCharacters;

        std::optional<std::variant<Range, EditRangeWithInsertReplace>> editRange;

        std::optional<InsertTextFormat> insertTextFormat;

        std::optional<InsertTextMode> insertTextMode;

        std::optional<nlohmann::json> data;
    };

    auto from_json(const nlohmann::json& object, CompletionItemDefaults& completion_item_defaults)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionItemDefaults& completion_item_defaults)
    noexcept -> void;
}

#endif
#endif