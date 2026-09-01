// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_show_message_request_client_capabilities
#define lyrix_header_guard_eura_show_message_request_client_capabilities
#include "Eura/ClientShowMessageActionItemOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ShowMessageRequestClientCapabilities final
    {
        std::optional<ClientShowMessageActionItemOptions> messageActionItem;
    };

    auto from_json(const nlohmann::json& object, ShowMessageRequestClientCapabilities&
    show_message_request_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const ShowMessageRequestClientCapabilities&
    show_message_request_client_capabilities) noexcept -> void;
}

#endif
#endif