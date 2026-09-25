// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_previous_result_id
#define lyrix_header_guard_eura_previous_result_id
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] PreviousResultId final
    {
        DocumentUri uri;

        std::string value;
    };

    auto from_json(const nlohmann::json& object, PreviousResultId& previous_result_id) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const PreviousResultId& previous_result_id) noexcept ->
    void;
}

#endif
#endif