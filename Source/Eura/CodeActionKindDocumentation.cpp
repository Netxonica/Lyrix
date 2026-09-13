// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionKindDocumentation.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionKindDocumentation&
    code_action_kind_documentation) noexcept -> void
    {
        code_action_kind_documentation.kind = object.at("kind").get<CodeActionKind>();
        code_action_kind_documentation.command = object.at("command").get<Command>();
    }

    auto to_json(nlohmann::json& object, const CodeActionKindDocumentation&
    code_action_kind_documentation) noexcept -> void
    {
        object["kind"] = code_action_kind_documentation.kind;
        object["command"] = code_action_kind_documentation.command;
    }
}

#endif