// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentLink.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentLink& document_link) noexcept -> void
    {
        document_link.range = object.at("range").get<Range>();
        if(object.contains("target"))
            document_link.target = object.at("target").get<URI>();
        if(object.contains("tooltip"))
            document_link.tooltip = object.at("tooltip").get<std::string>();
        if(object.contains("data"))
            document_link.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const DocumentLink& document_link) noexcept -> void
    {
        object["range"] = document_link.range;
        if(document_link.target.has_value())
            object["target"] = *document_link.target;
        if(document_link.tooltip.has_value())
            object["tooltip"] = *document_link.tooltip;
        if(document_link.data.has_value())
            object["data"] = *document_link.data;
    }
}

#endif