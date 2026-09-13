// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentSymbolOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentSymbolOptions& document_symbol_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(document_symbol_options));
        if(object.contains("label"))
            document_symbol_options.label = object.at("label").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const DocumentSymbolOptions& document_symbol_options)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(document_symbol_options));
        if(document_symbol_options.label.has_value())
            object["label"] = *document_symbol_options.label;
    }
}

#endif