// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueParams& inline_value_params) noexcept
    -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(inline_value_params));
        inline_value_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>();
        inline_value_params.range = object.at("range").get<Range>();
        inline_value_params.context = object.at("context").get<InlineValueContext>();
    }

    auto to_json(nlohmann::json& object, const InlineValueParams& inline_value_params) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(inline_value_params));
        object["textDocument"] = inline_value_params.textDocument;
        object["range"] = inline_value_params.range;
        object["context"] = inline_value_params.context;
    }
}

#endif