// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_rename_client_capabilities
#define lyrix_header_guard_eura_rename_client_capabilities
#include "Eura/Json.hpp"
#include "Eura/PrepareSupportDefaultBehavior.hpp"

namespace Eura
{
    struct [[nodiscard]] RenameClientCapabilities final
    {
        std::optional<bool> dynamicRegistration, prepareSupport;

        std::optional<PrepareSupportDefaultBehavior> prepareSupportDefaultBehavior;

        std::optional<bool> honorsChangeAnnotations;
    };

    auto from_json(const nlohmann::json& object, RenameClientCapabilities&
    rename_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const RenameClientCapabilities& rename_client_capabilities
    ) noexcept -> void;
}

#endif
#endif