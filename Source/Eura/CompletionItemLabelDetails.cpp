// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemLabelDetails.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionItemLabelDetails&
    completion_item_label_details) noexcept -> void
    {
        if(object.contains("detail"))
            completion_item_label_details.detail = object.at("detail").get<std::string>();
        if(object.contains("description"))
            completion_item_label_details.description = object.at("description").get<std::string>()
            ;
    }

    auto to_json(nlohmann::json& object, const CompletionItemLabelDetails&
    completion_item_label_details) noexcept -> void
    {
        if(completion_item_label_details.detail.has_value())
            object["detail"] = *completion_item_label_details.detail;
        if(completion_item_label_details.description.has_value())
            object["description"] = *completion_item_label_details.description;
    }
}

#endif