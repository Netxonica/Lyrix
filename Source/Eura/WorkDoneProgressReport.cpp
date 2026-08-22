// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressReport& work_done_progress_report)
    noexcept -> void
    {
        work_done_progress_report.kind = object.at("kind").get<std::string>();
        if(object.contains("cancellable"))
            work_done_progress_report.cancellable = object.at("cancellable").get<bool>();
        if(object.contains("message"))
            work_done_progress_report.message = object.at("message").get<std::string>();
        if(object.contains("percentage"))
            work_done_progress_report.percentage = object.at("percentage").get<std::uint32_t>();
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressReport& work_done_progress_report)
    noexcept -> void
    {
        object["kind"] = work_done_progress_report.kind;
        if(work_done_progress_report.cancellable.has_value())
            object["cancellable"] = *work_done_progress_report.cancellable;
        if(work_done_progress_report.message.has_value())
            object["message"] = *work_done_progress_report.message;
        if(work_done_progress_report.percentage.has_value())
            object["percentage"] = *work_done_progress_report.percentage;
    }
}

#endif