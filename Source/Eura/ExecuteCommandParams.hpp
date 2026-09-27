// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_execute_command_params
#define lyrix_header_guard_eura_execute_command_params
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] ExecuteCommandParams final : WorkDoneProgressParams
    {
        std::string command;

        std::optional<std::vector<nlohmann::json>> arguments;
    };

    auto from_json(const nlohmann::json& object, ExecuteCommandParams& execute_command_params)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const ExecuteCommandParams& execute_command_params)
    noexcept -> void;
}

#endif
#endif