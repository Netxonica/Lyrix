// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkDoneProgressBegin.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkDoneProgressBegin& work_done_progress_begin)
    noexcept -> void
    {
        work_done_progress_begin.kind = object.at("kind").get<std::string>();
        work_done_progress_begin.title = object.at("title").get<std::string>();
        if(object.contains("cancellable"))
            work_done_progress_begin.cancellable = object.at("cancellable").get<bool>();
        if(object.contains("message"))
            work_done_progress_begin.message = object.at("message").get<std::string>();
        if(object.contains("percentage"))
            work_done_progress_begin.percentage = object.at("percentage").get<std::uint32_t>();
    }

    auto to_json(nlohmann::json& object, const WorkDoneProgressBegin& work_done_progress_begin)
    noexcept -> void
    {
        object["kind"] = work_done_progress_begin.kind;
        object["title"] = work_done_progress_begin.title;
        if(work_done_progress_begin.cancellable.has_value())
            object["cancellable"] = *work_done_progress_begin.cancellable;
        if(work_done_progress_begin.message.has_value())
            object["message"] = *work_done_progress_begin.message;
        if(work_done_progress_begin.percentage.has_value())
            object["percentage"] = *work_done_progress_begin.percentage;
    }
}

#endif