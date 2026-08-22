// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressParams& work_done_progress_params)
    noexcept -> void
    {
        if(object.contains("workDoneToken"))
        {
            const nlohmann::json& workDoneToken = object.at("workDoneToken");
            if(workDoneToken.is_number_integer())
                work_done_progress_params.workDoneToken = workDoneToken.get<std::int32_t>();
            else
                work_done_progress_params.workDoneToken = workDoneToken.get<std::string>();
        }
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressParams& work_done_progress_params)
    noexcept -> void
    {
        if(work_done_progress_params.workDoneToken.has_value())
            std::visit([&object](auto&& workDoneToken)
            {
                object["workDoneToken"] = workDoneToken;
            }, *work_done_progress_params.workDoneToken);
    }
}

#endif