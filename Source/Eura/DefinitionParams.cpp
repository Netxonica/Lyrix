// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DefinitionParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DefinitionParams& definition_params) noexcept ->
    void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(definition_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(definition_params));
        from_json(object, static_cast<PartialResultParams&>(definition_params));
    }

    auto to_json(nlohmann::json& object, const DefinitionParams& definition_params) noexcept ->
    void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(definition_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(definition_params));
        to_json(object, static_cast<const PartialResultParams&>(definition_params));
    }
}

#endif