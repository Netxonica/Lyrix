// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_code_action_literal_options
#define lyrix_header_guard_eura_client_code_action_literal_options
#include "Eura/ClientCodeActionKindOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCodeActionLiteralOptions final
    {
        ClientCodeActionKindOptions codeActionKind;
    };

    auto from_json(const nlohmann::json& object, ClientCodeActionLiteralOptions&
    client_code_action_literal_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientCodeActionLiteralOptions&
    client_code_action_literal_options) noexcept -> void;
}

#endif
#endif