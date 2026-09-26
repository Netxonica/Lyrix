// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_selected_completion_info
#define lyrix_header_guard_eura_selected_completion_info
#include "Eura/Range.hpp"

namespace Eura
{
    struct [[nodiscard]] SelectedCompletionInfo final
    {
        Range range;

        std::string text;
    };

    auto from_json(const nlohmann::json& object, SelectedCompletionInfo& selected_completion_info)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SelectedCompletionInfo& selected_completion_info)
    noexcept -> void;
}

#endif
#endif