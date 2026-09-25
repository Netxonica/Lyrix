// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PreviousResultId.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PreviousResultId& previous_result_id) noexcept ->
    void
    {
        previous_result_id.uri = object.at("uri").get<DocumentUri>();
        previous_result_id.value = object.at("value").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const PreviousResultId& previous_result_id) noexcept ->
    void
    {
        object["uri"] = previous_result_id.uri;
        object["value"] = previous_result_id.value;
    }
}

#endif