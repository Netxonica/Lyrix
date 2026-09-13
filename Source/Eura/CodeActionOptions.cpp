// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionOptions& code_action_options) noexcept
    -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(code_action_options));
        if(object.contains("codeActionKinds"))
        {
            code_action_options.codeActionKinds = std::vector<CodeActionKind>{};
            const nlohmann::json& codeActionKinds = object.at("codeActionKinds");
            for(const nlohmann::json& codeActionKind : codeActionKinds)
                code_action_options.codeActionKinds->emplace_back(codeActionKind.get<CodeActionKind
                >());
        }
        if(object.contains("documentation"))
        {
            code_action_options.documentation = std::vector<CodeActionKindDocumentation>{};
            const nlohmann::json& documentation = object.at("documentation");
            for(const nlohmann::json& doc : documentation)
                code_action_options.documentation->emplace_back(doc.get<CodeActionKindDocumentation
                >());
        }
        if(object.contains("resolveProvider"))
            code_action_options.resolveProvider = object.at("resolveProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const CodeActionOptions& code_action_options) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(code_action_options));
        if(code_action_options.codeActionKinds.has_value())
        {
            nlohmann::json codeActionKinds = nlohmann::json::array();
            for(const CodeActionKind& codeActionKind : *code_action_options.codeActionKinds)
                codeActionKinds.emplace_back(codeActionKind);
            object["codeActionKinds"] = codeActionKinds;
        }
        if(code_action_options.documentation.has_value())
        {
            nlohmann::json documentation = nlohmann::json::array();
            for(const CodeActionKindDocumentation& doc : *code_action_options.documentation)
                documentation.emplace_back(doc);
            object["documentation"] = documentation;
        }
        if(code_action_options.resolveProvider.has_value())
            object["resolveProvider"] = *code_action_options.resolveProvider;
    }
}

#endif