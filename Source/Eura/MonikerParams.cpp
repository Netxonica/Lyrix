// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MonikerParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, MonikerParams& moniker_params) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentPositionParams&>(moniker_params));
        from_json(object, static_cast<WorkDoneProgressParams&>(moniker_params));
        from_json(object, static_cast<PartialResultParams&>(moniker_params));
    }

    auto to_json(nlohmann::json& object, const MonikerParams& moniker_params) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentPositionParams&>(moniker_params));
        to_json(object, static_cast<const WorkDoneProgressParams&>(moniker_params));
        to_json(object, static_cast<const PartialResultParams&>(moniker_params));
    }
}

#endif