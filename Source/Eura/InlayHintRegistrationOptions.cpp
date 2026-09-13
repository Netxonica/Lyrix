// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlayHintRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlayHintRegistrationOptions&
    inlay_hint_registration_options) noexcept -> void
    {
        from_json(object, static_cast<InlayHintOptions&>(inlay_hint_registration_options));
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        inlay_hint_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(inlay_hint_registration_options))
        ;
    }

    auto to_json(nlohmann::json& object, const InlayHintRegistrationOptions&
    inlay_hint_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const InlayHintOptions&>(inlay_hint_registration_options));
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        inlay_hint_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        inlay_hint_registration_options));
    }
}

#endif