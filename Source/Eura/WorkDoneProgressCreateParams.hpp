// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_work_done_progress_create_params
#define lyrix_header_guard_eura_work_done_progress_create_params
#include "Eura/Json.hpp"
#include "Eura/ProgressToken.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkDoneProgressCreateParams final
    {
        ProgressToken token;
    };

    auto from_json(const nlohmann::json& object, WorkDoneProgressCreateParams&
    work_done_progress_create_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkDoneProgressCreateParams&
    work_done_progress_create_params) noexcept -> void;
}

#endif
#endif