// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressEnd.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressEnd& work_done_progress_end)
    noexcept -> void
    {
        work_done_progress_end.kind = object.at("kind").get<std::string>();
        if(object.contains("message"))
            work_done_progress_end.message = object.at("message").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressEnd& work_done_progress_end)
    noexcept -> void
    {
        object["kind"] = work_done_progress_end.kind;
        if(work_done_progress_end.message.has_value())
            object["message"] = *work_done_progress_end.message;
    }
}

#endif