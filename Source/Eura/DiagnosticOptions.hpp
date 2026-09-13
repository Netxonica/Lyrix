// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_options
#define lyrix_header_guard_eura_diagnostic_options
#include "Eura/WorkDoneProgressOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DiagnosticOptions : WorkDoneProgressOptions
    {
        std::optional<std::string> identifier;

        bool interFileDependencies, workspaceDiagnostics;
    };

    auto from_json(const nlohmann::json& object, DiagnosticOptions& diagnostic_options) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const DiagnosticOptions& diagnostic_options) noexcept ->
    void;
}

#endif
#endif