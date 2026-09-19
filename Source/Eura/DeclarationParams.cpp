// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeclarationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeclarationParams& declaration_params) noexcept ->
    void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(declaration_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(declaration_params));
        from_json(object, static_cast<PartialResultParams&>(declaration_params));
    }

    auto to_json(nlohmann::json& object, const DeclarationParams& declaration_params) noexcept ->
    void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(declaration_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(declaration_params));
        to_json(object, static_cast<const PartialResultParams&>(declaration_params));
    }
}

#endif