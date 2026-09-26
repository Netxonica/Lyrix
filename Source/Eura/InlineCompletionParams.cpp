// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineCompletionParams& inline_completion_params)
    noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(inline_completion_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(inline_completion_params));
        inline_completion_params.context = object.at("context").get<InlineCompletionContext>();
    }

    auto to_json(nlohmann::json& object, const InlineCompletionParams& inline_completion_params)
    noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(inline_completion_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(inline_completion_params));
        object["context"] = inline_completion_params.context;
    }
}

#endif