// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensParams& semantic_tokens_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(semantic_tokens_params));
        from_json(object, static_cast<PartialResultParams&>(semantic_tokens_params));
        semantic_tokens_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>
        ();
    }

    auto to_json(nlohmann::json& object, const SemanticTokensParams& semantic_tokens_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(semantic_tokens_params));
        to_json(object, static_cast<const PartialResultParams&>(semantic_tokens_params));
        object["textDocument"] = semantic_tokens_params.textDocument;
    }
}

#endif