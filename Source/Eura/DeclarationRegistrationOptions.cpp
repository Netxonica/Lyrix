// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeclarationRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeclarationRegistrationOptions&
    declaration_registration_options) noexcept -> void
    {
        from_json(object, static_cast<DeclarationOptions&>(declaration_registration_options));
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        declaration_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(declaration_registration_options)
        );
    }

    auto to_json(nlohmann::json& object, const DeclarationRegistrationOptions&
    declaration_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const DeclarationOptions&>(declaration_registration_options));
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        declaration_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        declaration_registration_options));
    }
}

#endif