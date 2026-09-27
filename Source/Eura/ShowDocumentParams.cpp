// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowDocumentParams& show_document_params) noexcept
    -> void
    {
        show_document_params.uri = object.at("uri").get<URI>();
        if(object.contains("external"))
            show_document_params.external = object.at("external").get<bool>();
        if(object.contains("takeFocus"))
            show_document_params.takeFocus = object.at("takeFocus").get<bool>();
        if(object.contains("selection"))
            show_document_params.selection = object.at("selection").get<Range>();
    }

    auto to_json(nlohmann::json& object, const ShowDocumentParams& show_document_params) noexcept
    -> void
    {
        object["uri"] = show_document_params.uri;
        if(show_document_params.external.has_value())
            object["external"] = *show_document_params.external;
        if(show_document_params.takeFocus.has_value())
            object["takeFocus"] = *show_document_params.takeFocus;
        if(show_document_params.selection.has_value())
            object["selection"] = *show_document_params.selection;
    }
}

#endif