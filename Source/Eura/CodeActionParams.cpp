// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionParams& code_action_params) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(code_action_params));
        from_json(object, static_cast<PartialResultParams&>(code_action_params));
        code_action_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>();
        code_action_params.range = object.at("range").get<Range>();
        code_action_params.context = object.at("context").get<CodeActionContext>();
    }

    auto to_json(nlohmann::json& object, const CodeActionParams& code_action_params) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(code_action_params));
        to_json(object, static_cast<const PartialResultParams&>(code_action_params));
        object["textDocument"] = code_action_params.textDocument;
        object["range"] = code_action_params.range;
        object["context"] = code_action_params.context;
    }
}

#endif