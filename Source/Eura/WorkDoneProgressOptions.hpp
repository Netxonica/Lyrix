// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_work_done_progress_options
#define lyrix_header_guard_eura_work_done_progress_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkDoneProgressOptions
    {
        std::optional<bool> workDoneProgress;
    };

    auto from_json(const nlohmann::json& object, WorkDoneProgressOptions&
    work_done_progress_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkDoneProgressOptions& work_done_progress_options)
    noexcept -> void;
}

#endif
#endif