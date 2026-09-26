// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentOnTypeFormattingParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentOnTypeFormattingParams&
    document_on_type_formatting_params) noexcept -> void
    {
        document_on_type_formatting_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        document_on_type_formatting_params.position = object.at("position").get<Position>();
        document_on_type_formatting_params.ch = object.at("ch").get<std::string>();
        document_on_type_formatting_params.options = object.at("options").get<FormattingOptions>();
    }

    auto to_json(nlohmann::json& object, const DocumentOnTypeFormattingParams&
    document_on_type_formatting_params) noexcept -> void
    {
        object["textDocument"] = document_on_type_formatting_params.textDocument;
        object["position"] = document_on_type_formatting_params.position;
        object["ch"] = document_on_type_formatting_params.ch;
        object["options"] = document_on_type_formatting_params.options;
    }
}

#endif