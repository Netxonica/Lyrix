// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureHelpParams& signature_help_params)
    noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(signature_help_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(signature_help_params));
        if(object.contains("context"))
            signature_help_params.context = object.at("context").get<SignatureHelpContext>();
    }

    auto to_json(nlohmann::json& object, const SignatureHelpParams& signature_help_params) noexcept
    -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(signature_help_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(signature_help_params));
        if(signature_help_params.context.has_value())
            object["context"] = *signature_help_params.context;
    }
}

#endif