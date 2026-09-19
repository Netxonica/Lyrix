// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CallHierarchyItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CallHierarchyItem& call_hierarchy_item) noexcept
    -> void
    {
        call_hierarchy_item.name = object.at("name").get<std::string>();
        call_hierarchy_item.kind = object.at("kind").get<SymbolKind>();
        if(object.contains("tags"))
        {
            call_hierarchy_item.tags = std::vector<SymbolTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                call_hierarchy_item.tags->emplace_back(tag.get<SymbolTag>());
        }
        if(object.contains("detail"))
            call_hierarchy_item.detail = object.at("detail").get<std::string>();
        call_hierarchy_item.range = object.at("range").get<Range>();
        call_hierarchy_item.selectionRange = object.at("selectionRange").get<Range>();
        if(object.contains("data"))
            call_hierarchy_item.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const CallHierarchyItem& call_hierarchy_item) noexcept ->
    void
    {
        object["name"] = call_hierarchy_item.name;
        object["kind"] = call_hierarchy_item.kind;
        if(call_hierarchy_item.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const SymbolTag tag : *call_hierarchy_item.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
        if(call_hierarchy_item.detail.has_value())
            object["detail"] = *call_hierarchy_item.detail;
        object["range"] = call_hierarchy_item.range;
        object["selectionRange"] = call_hierarchy_item.selectionRange;
        if(call_hierarchy_item.data.has_value())
            object["data"] = *call_hierarchy_item.data;
    }
}

#endif