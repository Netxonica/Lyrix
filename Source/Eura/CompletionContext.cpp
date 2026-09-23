// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionContext& completion_context) noexcept ->
    void
    {
        completion_context.triggerKind = object.at("triggerKind").get<CompletionTriggerKind>();
        if(object.contains("triggerCharacter"))
            completion_context.triggerCharacter = object.at("triggerCharacter").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const CompletionContext& completion_context) noexcept ->
    void
    {
        object["triggerKind"] = completion_context.triggerKind;
        if(completion_context.triggerCharacter.has_value())
            object["triggerCharacter"] = *completion_context.triggerCharacter;
    }
}

#endif