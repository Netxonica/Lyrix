// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionParams& completion_params) noexcept ->
    void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(completion_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(completion_params));
        from_json(object, static_cast<PartialResultParams&>(completion_params));
        if(object.contains("context"))
            completion_params.context = object.at("context").get<CompletionContext>();
    }

    auto to_json(nlohmann::json& object, const CompletionParams& completion_params) noexcept ->
    void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(completion_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(completion_params));
        to_json(object, static_cast<const PartialResultParams&>(completion_params));
        if(completion_params.context.has_value())
            object["context"] = *completion_params.context;
    }
}

#endif