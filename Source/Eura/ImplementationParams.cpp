// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ImplementationParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ImplementationParams& implementation_params)
    noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(implementation_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(implementation_params));
        from_json(object, static_cast<PartialResultParams&>(implementation_params));
    }

    auto to_json(nlohmann::json& object, const ImplementationParams& implementation_params)
    noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(implementation_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(implementation_params));
        to_json(object, static_cast<const PartialResultParams&>(implementation_params));
    }
}

#endif