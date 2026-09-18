// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Registration.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Registration& registration) noexcept -> void
    {
        registration.id = object.at("id").get<std::string>();
        registration.method = object.at("method").get<std::string>();
        if(object.contains("registerOptions"))
            registration.registerOptions = object.at("registerOptions");
    }

    auto to_json(nlohmann::json& object, const Registration& registration) noexcept -> void
    {
        object["id"] = registration.id;
        object["method"] = registration.method;
        if(registration.registerOptions.has_value())
            object["registerOptions"] = *registration.registerOptions;
    }
}

#endif