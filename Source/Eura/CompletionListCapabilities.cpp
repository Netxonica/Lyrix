// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionListCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionListCapabilities&
    completion_list_capabilities) noexcept -> void
    {
        if(object.contains("itemDefaults"))
        {
            completion_list_capabilities.itemDefaults = std::vector<std::string>{};
            const nlohmann::json& itemDefaults = object.at("itemDefaults");
            for(const nlohmann::json& itemDefault : itemDefaults)
                completion_list_capabilities.itemDefaults->emplace_back(itemDefault.get<std::string
                >());
        }
        if(object.contains("applyKindSupport"))
            completion_list_capabilities.applyKindSupport = object.at("applyKindSupport").get<bool>
            ();
    }

    auto to_json(nlohmann::json& object, const CompletionListCapabilities&
    completion_list_capabilities) noexcept -> void
    {
        if(completion_list_capabilities.itemDefaults.has_value())
        {
            nlohmann::json itemDefaults = nlohmann::json::array();
            for(const std::string& itemDefault : *completion_list_capabilities.itemDefaults)
                itemDefaults.emplace_back(itemDefault);
            object["itemDefaults"] = itemDefaults;
        }
        if(completion_list_capabilities.applyKindSupport.has_value())
            object["applyKindSupport"] = *completion_list_capabilities.applyKindSupport;
    }
}

#endif