// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_execute_command_options
#define lyrix_header_guard_eura_execute_command_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ExecuteCommandOptions final : WorkDoneProgressOptions
    {
        std::vector<std::string> commands;
    };

    auto from_json(const nlohmann::json& object, ExecuteCommandOptions& execute_command_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const ExecuteCommandOptions& execute_command_options)
    noexcept -> void;
}

#endif
#endif