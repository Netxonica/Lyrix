// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressOptions&
    work_done_progress_options) noexcept -> void
    {
        if(object.contains("workDoneProgress"))
            work_done_progress_options.workDoneProgress = object.at("workDoneProgress").get<bool>()
            ;
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressOptions& work_done_progress_options)
    noexcept -> void
    {
        if(work_done_progress_options.workDoneProgress.has_value())
            object["workDoneProgress"] = *work_done_progress_options.workDoneProgress;
    }
}

#endif