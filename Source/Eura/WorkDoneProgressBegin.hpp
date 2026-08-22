// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_work_done_progress_begin
#define lyrix_header_guard_eura_work_done_progress_begin
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkDoneProgressBegin final
    {
        std::string kind, title;

        std::optional<bool> cancellable;

        std::optional<std::string> message;

        std::optional<std::uint32_t> percentage;
    };

    auto from_json(const nlohmann::json& object, WorkDoneProgressBegin& work_done_progress_begin)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkDoneProgressBegin&
    work_done_progress_begin) noexcept -> void;
}

#endif
#endif