// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/StaticRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, StaticRegistrationOptions&
    static_registration_options) noexcept -> void
    {
        if(object.contains("id"))
            static_registration_options.id = object.at("id").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const StaticRegistrationOptions&
    static_registration_options) noexcept -> void
    {
        if(static_registration_options.id.has_value())
            object["id"] = *static_registration_options.id;
    }
}

#endif