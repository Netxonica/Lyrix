// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_edit_client_capabilities
#define lyrix_header_guard_eura_workspace_edit_client_capabilities
#include "Eura/FailureHandlingKind.hpp"
#include "Eura/ResourceOperationKind.hpp"
#include "Eura/ChangeAnnotationsSupportOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceEditClientCapabilities final
    {
        std::optional<bool> documentChanges;

        std::optional<std::vector<ResourceOperationKind>> resourceOperations;

        std::optional<FailureHandlingKind> failureHandling;

        std::optional<bool> normalizesLineEndings;

        std::optional<ChangeAnnotationsSupportOptions> changeAnnotationSupport;

        std::optional<bool> metadataSupport, snippetEditSupport;
    };

    auto from_json(const nlohmann::json& object, WorkspaceEditClientCapabilities&
    workspace_edit_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceEditClientCapabilities&
    workspace_edit_client_capabilities) noexcept -> void;
}

#endif
#endif