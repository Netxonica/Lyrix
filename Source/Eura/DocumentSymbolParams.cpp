// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbolParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentSymbolParams& document_symbol_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_symbol_params));
        from_json(object, static_cast<PartialResultParams&>(document_symbol_params));
        document_symbol_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>
        ();
    }

    auto to_json(nlohmann::json& object, const DocumentSymbolParams& document_symbol_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_symbol_params));
        to_json(object, static_cast<const PartialResultParams&>(document_symbol_params));
        object["textDocument"] = document_symbol_params.textDocument;
    }
}

#endif