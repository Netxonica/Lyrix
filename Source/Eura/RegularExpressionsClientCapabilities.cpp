// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RegularExpressionsClientCapabilities.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void
    {
        regular_expressions_client_capabilities.engine = object.Retrieve("engine").As<
        RegularExpressionEngineKind>();
        if(object.Contains("version"))
            regular_expressions_client_capabilities.version = object.Retrieve("version").As<Json::
            String>();
    }

    auto Serialize(Json::Object& object, const RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void
    {
        object.fields.emplace_back("engine", regular_expressions_client_capabilities.engine);
        if(regular_expressions_client_capabilities.version.has_value())
            object.fields.emplace_back("version", *regular_expressions_client_capabilities.version)
            ;
    }
}

#endif