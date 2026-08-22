// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_work_done_progress_end
#define lyrix_header_guard_eura_work_done_progress_end
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkDoneProgressEnd final
    {
        std::string kind;

        std::optional<std::string> message;
    };

    auto from_json(const nlohmann::json& object, WorkDoneProgressEnd& work_done_progress_end)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkDoneProgressEnd& work_done_progress_end)
    noexcept -> void;
}

#endif
#endif