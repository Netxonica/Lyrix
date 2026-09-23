// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_item_label_details
#define lyrix_header_guard_eura_completion_item_label_details
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionItemLabelDetails final
    {
        std::optional<std::string> detail, description;
    };

    auto from_json(const nlohmann::json& object, CompletionItemLabelDetails&
    completion_item_label_details) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionItemLabelDetails&
    completion_item_label_details) noexcept -> void;
}

#endif
#endif