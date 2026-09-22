// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensDeltaParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensDeltaParams&
    semantic_tokens_delta_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(semantic_tokens_delta_params));
        from_json(object, static_cast<PartialResultParams&>(semantic_tokens_delta_params));
        semantic_tokens_delta_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        semantic_tokens_delta_params.previousResultId = object.at("previousResultId").get<std::
        string>();
    }

    auto to_json(nlohmann::json& object, const SemanticTokensDeltaParams&
    semantic_tokens_delta_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(semantic_tokens_delta_params));
        to_json(object, static_cast<const PartialResultParams&>(semantic_tokens_delta_params));
        object["textDocument"] = semantic_tokens_delta_params.textDocument;
        object["previousResultId"] = semantic_tokens_delta_params.previousResultId;
    }
}

#endif