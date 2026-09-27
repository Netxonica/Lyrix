// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_work_done_progress_cancel_params
#define lyrix_header_guard_eura_work_done_progress_cancel_params
#include "Eura/Json.hpp"
#include "Eura/ProgressToken.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkDoneProgressCancelParams final
    {
        ProgressToken token;
    };

    auto from_json(const nlohmann::json& object, WorkDoneProgressCancelParams&
    work_done_progress_cancel_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkDoneProgressCancelParams&
    work_done_progress_cancel_params) noexcept -> void;
}

#endif
#endif