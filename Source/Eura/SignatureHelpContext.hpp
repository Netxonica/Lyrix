// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_signature_help_context
#define lyrix_header_guard_eura_signature_help_context
#include "Eura/SignatureHelp.hpp"
#include "Eura/SignatureHelpTriggerKind.hpp"

namespace Eura
{
    struct [[nodiscard]] SignatureHelpContext final
    {
        SignatureHelpTriggerKind triggerKind;

        std::optional<std::string> triggerCharacter;

        bool isRetrigger;

        std::optional<SignatureHelp> activeSignatureHelp;
    };

    auto from_json(const nlohmann::json& object, SignatureHelpContext& signature_help_context)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const SignatureHelpContext& signature_help_context)
    noexcept -> void;
}

#endif
#endif