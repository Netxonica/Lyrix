// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueRegistrationOptions&
    inline_value_registration_options) noexcept -> void
    {
        from_json(object, static_cast<InlineValueOptions&>(inline_value_registration_options));
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        inline_value_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(inline_value_registration_options
        ));
    }

    auto to_json(nlohmann::json& object, const InlineValueRegistrationOptions&
    inline_value_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const InlineValueOptions&>(inline_value_registration_options));
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        inline_value_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        inline_value_registration_options));
    }
}

#endif