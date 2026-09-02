// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_initialize_params
#define lyrix_header_guard_eura_initialize_params
#include "Eura/ClientInfo.hpp"
#include "Eura/TraceValue.hpp"
#include "Eura/DocumentUri.hpp"
#include "Eura/WorkspaceFolder.hpp"
#include "Eura/ClientCapabilities.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] InitializeParams final : WorkDoneProgressParams
    {
        std::variant<std::int32_t, std::nullptr_t> processId;

        std::optional<ClientInfo> clientInfo;

        std::optional<std::string> locale;

        std::optional<std::variant<std::string, std::nullptr_t>> rootPath;

        std::variant<DocumentUri, std::nullptr_t> rootUri;

        std::optional<nlohmann::json> initializationOptions;

        ClientCapabilities capabilities;

        std::optional<TraceValue> trace;

        std::optional<std::variant<std::vector<WorkspaceFolder>, std::nullptr_t>> workspaceFolders;
    };

    auto from_json(const nlohmann::json& object, InitializeParams& initialize_params) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const InitializeParams& initialize_params) noexcept ->
    void;
}

#endif
#endif