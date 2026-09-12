// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TypeDefinitionRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TypeDefinitionRegistrationOptions&
    type_definition_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        type_definition_registration_options));
        from_json(object, static_cast<TypeDefinitionOptions&>(type_definition_registration_options)
        );
        from_json(object, static_cast<StaticRegistrationOptions&>(
        type_definition_registration_options));
    }

    auto to_json(nlohmann::json& object, const TypeDefinitionRegistrationOptions&
    type_definition_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        type_definition_registration_options));
        to_json(object, static_cast<const TypeDefinitionOptions&>(
        type_definition_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        type_definition_registration_options));
    }
}

#endif