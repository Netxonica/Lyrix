// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbol.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentSymbol& document_symbol) noexcept -> void
    {
        document_symbol.name = object.at("name").get<std::string>();
        if(object.contains("detail"))
            document_symbol.detail = object.at("detail").get<std::string>();
        document_symbol.kind = object.at("kind").get<SymbolKind>();
        if(object.contains("tags"))
        {
            document_symbol.tags = std::vector<SymbolTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                document_symbol.tags->emplace_back(tag.get<SymbolTag>());
        }
        document_symbol.range = object.at("range").get<Range>();
        document_symbol.selectionRange = object.at("selectionRange").get<Range>();
        if(object.contains("children"))
        {
            document_symbol.children = std::vector<DocumentSymbol>{};
            const nlohmann::json& children = object.at("children");
            for(const nlohmann::json& child : children)
                document_symbol.children->emplace_back(child.get<DocumentSymbol>());
        }
    }

    auto to_json(nlohmann::json& object, const DocumentSymbol& document_symbol) noexcept -> void
    {
        object["name"] = document_symbol.name;
        if(document_symbol.detail.has_value())
            object["detail"] = *document_symbol.detail;
        object["kind"] = document_symbol.kind;
        if(document_symbol.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const SymbolTag tag : *document_symbol.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
        object["range"] = document_symbol.range;
        object["selectionRange"] = document_symbol.selectionRange;
        if(document_symbol.children.has_value())
        {
            nlohmann::json children = nlohmann::json::array();
            for(const DocumentSymbol& child : *document_symbol.children)
                children.emplace_back(child);
            object["children"] = children;
        }
    }
}

#endif