// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintOptions& inlay_hint_options) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(inlay_hint_options));
        if(object.contains("resolveProvider"))
            inlay_hint_options.resolveProvider = object.at("resolveProvider").get<bool>();
    }

    auto to_json(nlohmann::json& object, const InlayHintOptions& inlay_hint_options) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(inlay_hint_options));
        if(inlay_hint_options.resolveProvider.has_value())
            object["resolveProvider"] = *inlay_hint_options.resolveProvider;
    }
}

#endif