// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PartialResultParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PartialResultParams& partial_result_params)
    noexcept -> void
    {
        if(object.contains("partialResultToken"))
        {
            const nlohmann::json& partialResultToken = object.at("partialResultToken");
            if(partialResultToken.is_number_integer())
                partial_result_params.partialResultToken = partialResultToken.get<std::int32_t>();
            else
                partial_result_params.partialResultToken = partialResultToken.get<std::string>();
        }
    }

    auto to_json(nlohmann::json& object, const PartialResultParams& partial_result_params) noexcept
    -> void
    {
        if(partial_result_params.partialResultToken.has_value())
            std::visit([&object](auto&& partialResultToken)
            {
                object["partialResultToken"] = partialResultToken;
            }, *partial_result_params.partialResultToken);
    }
}

#endif