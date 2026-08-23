// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameClientCapabilities&
    rename_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            rename_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").get<
            bool>();
        if(object.contains("prepareSupport"))
            rename_client_capabilities.prepareSupport = object.at("prepareSupport").get<bool>();
        if(object.contains("prepareSupportDefaultBehavior"))
            rename_client_capabilities.prepareSupportDefaultBehavior = static_cast<
            PrepareSupportDefaultBehavior>(object.at("prepareSupportDefaultBehavior").get<std::
            uint8_t>());
        if(object.contains("honorsChangeAnnotations"))
            rename_client_capabilities.honorsChangeAnnotations = object.at(
            "honorsChangeAnnotations").get<bool>();
    }

    auto to_json(nlohmann::json& object, const RenameClientCapabilities& rename_client_capabilities
    ) noexcept -> void
    {
        if(rename_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *rename_client_capabilities.dynamicRegistration;
        if(rename_client_capabilities.prepareSupport.has_value())
            object["prepareSupport"] = *rename_client_capabilities.prepareSupport;
        if(rename_client_capabilities.prepareSupportDefaultBehavior.has_value())
            object["prepareSupportDefaultBehavior"] = static_cast<std::uint8_t>(*
            rename_client_capabilities.prepareSupportDefaultBehavior);
        if(rename_client_capabilities.honorsChangeAnnotations.has_value())
            object["honorsChangeAnnotations"] = *rename_client_capabilities.honorsChangeAnnotations
            ;
    }
}

#endif