// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeAction.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeAction& code_action) noexcept -> void
    {
        code_action.title = object.at("title").get<std::string>();
        if(object.contains("kind"))
            code_action.kind = object.at("kind").get<CodeActionKind>();
        if(object.contains("diagnostics"))
        {
            code_action.diagnostics = std::vector<Diagnostic>{};
            const nlohmann::json& diagnostics = object.at("diagnostics");
            for(const nlohmann::json& diagnostic : diagnostics)
                code_action.diagnostics->emplace_back(diagnostic.get<Diagnostic>());
        }
        if(object.contains("isPreferred"))
            code_action.isPreferred = object.at("isPreferred").get<bool>();
        if(object.contains("disabled"))
            code_action.disabled = object.at("disabled").get<CodeActionDisabled>();
        if(object.contains("edit"))
            code_action.edit = object.at("edit").get<WorkspaceEdit>();
        if(object.contains("command"))
            code_action.command = object.at("command").get<Command>();
        if(object.contains("data"))
            code_action.data = object.at("data");
        if(object.contains("tags"))
        {
            code_action.tags = std::vector<CodeActionTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                code_action.tags->emplace_back(tag.get<CodeActionTag>());
        }
    }

    auto to_json(nlohmann::json& object, const CodeAction& code_action) noexcept -> void
    {
        object["title"] = code_action.title;
        if(code_action.kind.has_value())
            object["kind"] = *code_action.kind;
        if(code_action.diagnostics.has_value())
        {
            nlohmann::json diagnostics = nlohmann::json::array();
            for(const Diagnostic& diagnostic : *code_action.diagnostics)
                diagnostics.emplace_back(diagnostic);
            object["diagnostics"] = diagnostics;
        }
        if(code_action.isPreferred.has_value())
            object["isPreferred"] = *code_action.isPreferred;
        if(code_action.disabled.has_value())
            object["disabled"] = *code_action.disabled;
        if(code_action.edit.has_value())
            object["edit"] = *code_action.edit;
        if(code_action.command.has_value())
            object["command"] = *code_action.command;
        if(code_action.data.has_value())
            object["data"] = *code_action.data;
        if(code_action.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const CodeActionTag tag : *code_action.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
    }
}

#endif