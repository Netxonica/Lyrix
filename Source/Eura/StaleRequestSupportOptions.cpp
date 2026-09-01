// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/StaleRequestSupportOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, StaleRequestSupportOptions&
    stale_request_support_options) noexcept -> void
    {
        stale_request_support_options.cancel = object.at("cancel").get<bool>();
        const nlohmann::json& retryOnContentModified = object.at("retryOnContentModified");
        for(const nlohmann::json& retry : retryOnContentModified)
            stale_request_support_options.retryOnContentModified.emplace_back(retry.get<std::string
            >());
    }

    auto to_json(nlohmann::json& object, const StaleRequestSupportOptions&
    stale_request_support_options) noexcept -> void
    {
        object["cancel"] = stale_request_support_options.cancel;
        nlohmann::json retryOnContentModified = nlohmann::json::array();
        for(const std::string& retry : stale_request_support_options.retryOnContentModified)
            retryOnContentModified.emplace_back(retry);
        object["retryOnContentModified"] = retryOnContentModified;
    }
}

#endif