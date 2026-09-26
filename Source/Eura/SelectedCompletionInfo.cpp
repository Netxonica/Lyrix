// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SelectedCompletionInfo.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SelectedCompletionInfo& selected_completion_info)
    noexcept -> void
    {
        selected_completion_info.range = object.at("range").get<Range>();
        selected_completion_info.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const SelectedCompletionInfo& selected_completion_info)
    noexcept -> void
    {
        object["range"] = selected_completion_info.range;
        object["text"] = selected_completion_info.text;
    }
}

#endif