// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/GeneralClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, GeneralClientCapabilities&
    general_client_capabilities) noexcept -> void
    {
        if(object.contains("staleRequestSupport"))
            general_client_capabilities.staleRequestSupport = object.at("staleRequestSupport").get<
            StaleRequestSupportOptions>();
        if(object.contains("regularExpressions"))
            general_client_capabilities.regularExpressions = object.at("regularExpressions").get<
            RegularExpressionsClientCapabilities>();
        if(object.contains("markdown"))
            general_client_capabilities.markdown = object.at("markdown").get<
            MarkdownClientCapabilities>();
        if(object.contains("positionEncodings"))
        {
            general_client_capabilities.positionEncodings = std::vector<PositionEncodingKind>{};
            const nlohmann::json& positionEncodings = object.at("positionEncodings");
            for(const nlohmann::json& positionEncoding : positionEncodings)
                general_client_capabilities.positionEncodings->emplace_back(positionEncoding.get<
                PositionEncodingKind>());
        }
    }

    auto to_json(nlohmann::json& object, const GeneralClientCapabilities&
    general_client_capabilities) noexcept -> void
    {
        if(general_client_capabilities.staleRequestSupport.has_value())
            object["staleRequestSupport"] = *general_client_capabilities.staleRequestSupport;
        if(general_client_capabilities.regularExpressions.has_value())
            object["regularExpressions"] = *general_client_capabilities.regularExpressions;
        if(general_client_capabilities.markdown.has_value())
            object["markdown"] = *general_client_capabilities.markdown;
        if(general_client_capabilities.positionEncodings.has_value())
        {
            nlohmann::json positionEncodings = nlohmann::json::array();
            for(const PositionEncodingKind& positionEncoding : *general_client_capabilities.positionEncodings)
                positionEncodings.emplace_back(positionEncoding);
            object["positionEncodings"] = positionEncodings;
        }
    }
}

#endif