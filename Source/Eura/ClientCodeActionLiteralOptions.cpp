// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCodeActionLiteralOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCodeActionLiteralOptions&
    client_code_action_literal_options) noexcept -> void
    {
        client_code_action_literal_options.codeActionKind = object.at("codeActionKind").get<
        ClientCodeActionKindOptions>();
    }

    auto to_json(nlohmann::json& object, const ClientCodeActionLiteralOptions&
    client_code_action_literal_options) noexcept -> void
    {
        object["codeActionKind"] = client_code_action_literal_options.codeActionKind;
    }
}

#endif