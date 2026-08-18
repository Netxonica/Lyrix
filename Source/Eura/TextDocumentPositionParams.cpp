// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentPositionParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentPositionParams&
    text_document_position_params) noexcept -> void
    {
        text_document_position_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        text_document_position_params.position = object.at("position").get<Position>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentPositionParams&
    text_document_position_params) noexcept -> void
    {
        object["textDocument"] = text_document_position_params.textDocument;
        object["position"] = text_document_position_params.position;
    }
}

#endif