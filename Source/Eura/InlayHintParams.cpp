// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintParams& inlay_hint_params) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(inlay_hint_params));
        inlay_hint_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>();
        inlay_hint_params.range = object.at("range").get<Range>();
    }

    auto to_json(nlohmann::json& object, const InlayHintParams& inlay_hint_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(inlay_hint_params));
        object["textDocument"] = inlay_hint_params.textDocument;
        object["range"] = inlay_hint_params.range;
    }
}

#endif