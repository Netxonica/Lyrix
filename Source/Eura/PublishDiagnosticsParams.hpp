// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_publish_diagnostics_params
#define lyrix_header_guard_eura_publish_diagnostics_params
#include "Eura/Diagnostic.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] PublishDiagnosticsParams final
    {
        DocumentUri uri;

        std::optional<std::int32_t> version;

        std::vector<Diagnostic> diagnostics;
    };

    auto from_json(const nlohmann::json& object, PublishDiagnosticsParams&
    publish_diagnostics_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const PublishDiagnosticsParams& publish_diagnostics_params
    ) noexcept -> void;
}

#endif
#endif