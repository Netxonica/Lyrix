// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MonikerRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, MonikerRegistrationOptions&
    moniker_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        moniker_registration_options));
        from_json(object, static_cast<MonikerOptions&>(moniker_registration_options));
    }

    auto to_json(nlohmann::json& object, const MonikerRegistrationOptions&
    moniker_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        moniker_registration_options));
        to_json(object, static_cast<const MonikerOptions&>(moniker_registration_options));
    }
}

#endif