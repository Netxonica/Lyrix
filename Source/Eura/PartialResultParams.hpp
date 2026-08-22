// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_partial_result_params
#define lyrix_header_guard_eura_partial_result_params
#include "Eura/Json.hpp"
#include "Eura/ProgressToken.hpp"

namespace Eura
{
    struct [[nodiscard]] PartialResultParams final
    {
        std::optional<ProgressToken> partialResultToken;
    };

    auto from_json(const nlohmann::json& object, PartialResultParams& partial_result_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const PartialResultParams& partial_result_params) noexcept
    -> void;
}

#endif
#endif