// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionContext& code_action_context) noexcept
    -> void
    {
        const nlohmann::json& diagnostics = object.at("diagnostics");
        for(const nlohmann::json& diagnostic : diagnostics)
            code_action_context.diagnostics.emplace_back(diagnostic.get<Diagnostic>());
        if(object.contains("only"))
        {
            code_action_context.only = std::vector<CodeActionKind>{};
            const nlohmann::json& only = object.at("only");
            for(const nlohmann::json& onl : only)
                code_action_context.only->emplace_back(onl.get<CodeActionKind>());
        }
        if(object.contains("triggerKind"))
            code_action_context.triggerKind = object.at("triggerKind").get<CodeActionTriggerKind>()
            ;
    }

    auto to_json(nlohmann::json& object, const CodeActionContext& code_action_context) noexcept ->
    void
    {
        nlohmann::json diagnostics = nlohmann::json::array();
        for(const Diagnostic& diagnostic : code_action_context.diagnostics)
            diagnostics.emplace_back(diagnostic);
        object["diagnostics"] = diagnostics;
        if(code_action_context.only.has_value())
        {
            nlohmann::json only = nlohmann::json::array();
            for(const CodeActionKind& onl : *code_action_context.only)
                only.emplace_back(onl);
            object["only"] = only;
        }
        if(code_action_context.triggerKind.has_value())
            object["triggerKind"] = *code_action_context.triggerKind;
    }
}

#endif