// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RegularExpressionsClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void
    {
        regular_expressions_client_capabilities.engine = object.at("engine").get<
        RegularExpressionEngineKind>();
        if(object.contains("version"))
            regular_expressions_client_capabilities.version = object.at("version").get<std::string>
            ();
    }

    auto to_json(nlohmann::json& object, const RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void
    {
        object["engine"] = regular_expressions_client_capabilities.engine;
        if(regular_expressions_client_capabilities.version.has_value())
            object["version"] = *regular_expressions_client_capabilities.version;
    }
}

#endif