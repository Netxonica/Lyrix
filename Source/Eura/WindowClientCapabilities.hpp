// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_window_client_capabilities
#define lyrix_header_guard_eura_window_client_capabilities
#include "Eura/ShowDocumentClientCapabilities.hpp"
#include "Eura/ShowMessageRequestClientCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] WindowClientCapabilities final
    {
        std::optional<bool> workDoneProgress;

        std::optional<ShowMessageRequestClientCapabilities> showMessage;

        std::optional<ShowDocumentClientCapabilities> showDocument;
    };

    auto from_json(const nlohmann::json& object, WindowClientCapabilities&
    window_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const WindowClientCapabilities& window_client_capabilities
    ) noexcept -> void;
}

#endif
#endif