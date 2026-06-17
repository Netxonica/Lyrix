// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextDocumentPositionParams&
    text_document_position_params) noexcept -> void
    {
        Deserialize(object.Retrieve("textDocument").As<Json::Object>(),
        text_document_position_params.textDocument);
        Deserialize(object.Retrieve("position").As<Json::Object>(), text_document_position_params.
        position);
    }

    auto Serialize(Json::Object& object, const TextDocumentPositionParams&
    text_document_position_params) noexcept -> void
    {
        Serialize(object.NestedObject("textDocument"), text_document_position_params.textDocument);
        Serialize(object.NestedObject("position"), text_document_position_params.position);
    }
}

#endif