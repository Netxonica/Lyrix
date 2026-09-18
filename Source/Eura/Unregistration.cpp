// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Unregistration.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Unregistration& unregistration) noexcept -> void
    {
        unregistration.id = object.at("id").get<std::string>();
        unregistration.method = object.at("method").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const Unregistration& unregistration) noexcept -> void
    {
        object["id"] = unregistration.id;
        object["method"] = unregistration.method;
    }
}

#endif