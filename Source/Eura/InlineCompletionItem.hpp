// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_inline_completion_item
#define lyrix_header_guard_eura_inline_completion_item
#include "Eura/Range.hpp"
#include "Eura/Command.hpp"
#include "Eura/StringValue.hpp"

namespace Eura
{
    struct [[nodiscard]] InlineCompletionItem final
    {
        std::variant<std::string, StringValue> insertText;

        std::optional<std::string> filterText;

        std::optional<Range> range;

        std::optional<Command> command;
    };

    auto from_json(const nlohmann::json& object, InlineCompletionItem& inline_completion_item)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const InlineCompletionItem& inline_completion_item)
    noexcept -> void;
}

#endif
#endif