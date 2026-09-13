// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentLinkOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentLinkOptions& document_link_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(document_link_options));
        if(object.contains("resolveProvider"))
            document_link_options.resolveProvider = object.at("resolveProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DocumentLinkOptions& document_link_options) noexcept
    -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(document_link_options));
        if(document_link_options.resolveProvider.has_value())
            object["resolveProvider"] = *document_link_options.resolveProvider;
    }
}

#endif