// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeHierarchyItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeHierarchyItem& type_hierarchy_item) noexcept
    -> void
    {
        type_hierarchy_item.name = object.at("name").get<std::string>();
        type_hierarchy_item.kind = object.at("kind").get<SymbolKind>();
        if(object.contains("tags"))
        {
            type_hierarchy_item.tags = std::vector<SymbolTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                type_hierarchy_item.tags->emplace_back(tag.get<SymbolTag>());
        }
        if(object.contains("detail"))
            type_hierarchy_item.detail = object.at("detail").get<std::string>();
        type_hierarchy_item.uri = object.at("uri").get<DocumentUri>();
        type_hierarchy_item.range = object.at("range").get<Range>();
        type_hierarchy_item.selectionRange = object.at("selectionRange").get<Range>();
        if(object.contains("data"))
            type_hierarchy_item.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const TypeHierarchyItem& type_hierarchy_item) noexcept ->
    void
    {
        object["name"] = type_hierarchy_item.name;
        object["kind"] = type_hierarchy_item.kind;
        if(type_hierarchy_item.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const SymbolTag tag : *type_hierarchy_item.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
        if(type_hierarchy_item.detail.has_value())
            object["detail"] = *type_hierarchy_item.detail;
        object["uri"] = type_hierarchy_item.uri;
        object["range"] = type_hierarchy_item.range;
        object["selectionRange"] = type_hierarchy_item.selectionRange;
        if(type_hierarchy_item.data.has_value())
            object["data"] = *type_hierarchy_item.data;
    }
}

#endif