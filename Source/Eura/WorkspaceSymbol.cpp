// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceSymbol.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceSymbol& workspace_symbol) noexcept ->
    void
    {
        workspace_symbol.name = object.at("name").get<std::string>();
        workspace_symbol.kind = object.at("kind").get<SymbolKind>();
        if(object.contains("tags"))
        {
            workspace_symbol.tags = std::vector<SymbolTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                workspace_symbol.tags->emplace_back(tag.get<SymbolTag>());
        }
        if(object.contains("containerName"))
            workspace_symbol.containerName = object.at("containerName").get<std::string>();
        const nlohmann::json& location = object.at("location");
        if(location.contains("range"))
            workspace_symbol.location = location.get<Location>();
        else
            workspace_symbol.location = location.get<LocationUriOnly>();
        if(object.contains("data"))
            workspace_symbol.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const WorkspaceSymbol& workspace_symbol) noexcept -> void
    {
        object["name"] = workspace_symbol.name;
        object["kind"] = workspace_symbol.kind;
        if(workspace_symbol.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const SymbolTag tag : *workspace_symbol.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
        if(workspace_symbol.containerName.has_value())
            object["containerName"] = *workspace_symbol.containerName;
        std::visit([&object](auto&& location)
        {
            object["location"] = location;
        }, workspace_symbol.location);
        if(workspace_symbol.data.has_value())
            object["data"] = *workspace_symbol.data;
    }
}

#endif