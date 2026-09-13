// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DiagnosticRegistrationOptions&
    diagnostic_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        diagnostic_registration_options));
        from_json(object, static_cast<DiagnosticOptions&>(diagnostic_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(diagnostic_registration_options))
        ;
    }

    auto to_json(nlohmann::json& object, const DiagnosticRegistrationOptions&
    diagnostic_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        diagnostic_registration_options));
        to_json(object, static_cast<const DiagnosticOptions&>(diagnostic_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        diagnostic_registration_options));
    }
}

#endif