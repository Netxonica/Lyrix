// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressCreateParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressCreateParams&
    work_done_progress_create_params) noexcept -> void
    {
        const nlohmann::json& token = object.at("token");
        if(token.is_number_integer())
            work_done_progress_create_params.token = token.get<std::int32_t>();
        else
            work_done_progress_create_params.token = token.get<std::string>();
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressCreateParams&
    work_done_progress_create_params) noexcept -> void
    {
        std::visit([&object](auto&& token)
        {
            object["token"] = token;
        }, work_done_progress_create_params.token);
    }
}

#endif