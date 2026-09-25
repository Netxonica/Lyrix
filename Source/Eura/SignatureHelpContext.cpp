// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureHelpContext& signature_help_context)
    noexcept -> void
    {
        signature_help_context.triggerKind = object.at("triggerKind").get<SignatureHelpTriggerKind>
        ();
        if(object.contains("triggerCharacter"))
            signature_help_context.triggerCharacter = object.at("triggerCharacter").get<std::string
            >();
        signature_help_context.isRetrigger = object.at("isRetrigger").get<bool>();
        if(object.contains("activeSignatureHelp"))
            signature_help_context.activeSignatureHelp = object.at("activeSignatureHelp").get<
            SignatureHelp>();
    }

    auto to_json(nlohmann::json& object, const SignatureHelpContext& signature_help_context)
    noexcept -> void
    {
        object["triggerKind"] = signature_help_context.triggerKind;
        if(signature_help_context.triggerCharacter.has_value())
            object["triggerCharacter"] = *signature_help_context.triggerCharacter;
        object["isRetrigger"] = signature_help_context.isRetrigger;
        if(signature_help_context.activeSignatureHelp.has_value())
            object["activeSignatureHelp"] = *signature_help_context.activeSignatureHelp;
    }
}

#endif