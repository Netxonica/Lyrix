// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InitializeParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InitializeParams& initialize_params) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(initialize_params));
        const nlohmann::json& processId = object.at("processId");
        if(processId.is_number_integer())
            initialize_params.processId = processId.get<std::int32_t>();
        else
            initialize_params.processId = nullptr;
        if(object.contains("clientInfo"))
            initialize_params.clientInfo = object.at("clientInfo").get<ClientInfo>();
        if(object.contains("locale"))
            initialize_params.locale = object.at("locale").get<std::string>();
        if(object.contains("rootPath"))
        {
            const nlohmann::json& rootPath = object.at("rootPath");
            if(rootPath.is_string())
                initialize_params.rootPath = rootPath.get<std::string>();
            else
                initialize_params.rootPath = nullptr;
        }
        const nlohmann::json& rootUri = object.at("rootUri");
        if(rootUri.is_string())
            initialize_params.rootUri = rootUri.get<DocumentUri>();
        else
            initialize_params.rootUri = nullptr;
        if(object.contains("initializationOptions"))
            initialize_params.initializationOptions = object.at("initializationOptions");
        initialize_params.capabilities = object.at("capabilities").get<ClientCapabilities>();
        if(object.contains("trace"))
            initialize_params.trace = object.at("trace").get<TraceValue>();
        if(object.contains("workspaceFolders"))
        {
            const nlohmann::json& workspaceFolders = object.at("workspaceFolders");
            if(workspaceFolders.is_array())
            {
                initialize_params.workspaceFolders = std::variant<std::vector<WorkspaceFolder>, std::nullptr_t>{};
                *initialize_params.workspaceFolders = std::vector<WorkspaceFolder>{};
                for(const nlohmann::json& workspaceFolder : workspaceFolders)
                    std::get<std::vector<WorkspaceFolder>>(*initialize_params.workspaceFolders).
                    emplace_back(workspaceFolder.get<WorkspaceFolder>());
            }
            else
                initialize_params.workspaceFolders = nullptr;
        }
    }

    auto to_json(nlohmann::json& object, const InitializeParams& initialize_params) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(initialize_params));
        std::visit([&object](auto&& processId)
        {
            object["processId"] = processId;
        }, initialize_params.processId);
        if(initialize_params.clientInfo.has_value())
            object["clientInfo"] = *initialize_params.clientInfo;
        if(initialize_params.locale.has_value())
            object["locale"] = *initialize_params.locale;
        if(initialize_params.rootPath.has_value())
            std::visit([&object](auto&& rootPath)
            {
                object["rootPath"] = rootPath;
            }, *initialize_params.rootPath);
        std::visit([&object](auto&& rootUri)
        {
            object["rootUri"] = rootUri;
        }, initialize_params.rootUri);
        if(initialize_params.initializationOptions.has_value())
            object["initializationOptions"] = *initialize_params.initializationOptions;
        object["capabilities"] = initialize_params.capabilities;
        if(initialize_params.trace.has_value())
            object["trace"] = *initialize_params.trace;
        if(initialize_params.workspaceFolders.has_value())
        {
            if(std::holds_alternative<std::vector<WorkspaceFolder>>(*initialize_params.
            workspaceFolders))
            {
                nlohmann::json workspaceFolders = nlohmann::json::array();
                for(const WorkspaceFolder& workspaceFolder : std::get<std::vector<WorkspaceFolder>>
                (*initialize_params.workspaceFolders))
                    workspaceFolders.emplace_back(workspaceFolder);
                object["workspaceFolders"] = workspaceFolders;
            }
            else
                object["workspaceFolders"] = nullptr;
        }
    }
}

#endif