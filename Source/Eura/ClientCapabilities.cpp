// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCapabilities& client_capabilities) noexcept
    -> void
    {
        if(object.contains("workspace"))
            client_capabilities.workspace = object.at("workspace").get<WorkspaceClientCapabilities>
            ();
        if(object.contains("textDocument"))
            client_capabilities.textDocument = object.at("textDocument").get<
            TextDocumentClientCapabilities>();
        if(object.contains("notebookDocument"))
            client_capabilities.notebookDocument = object.at("notebookDocument").get<
            NotebookDocumentClientCapabilities>();
        if(object.contains("window"))
            client_capabilities.window = object.at("window").get<WindowClientCapabilities>();
        if(object.contains("general"))
            client_capabilities.general = object.at("general").get<GeneralClientCapabilities>();
        if(object.contains("experimental"))
            client_capabilities.experimental = object.at("experimental");
    }

    auto to_json(nlohmann::json& object, const ClientCapabilities& client_capabilities) noexcept ->
    void
    {
        if(client_capabilities.workspace.has_value())
            object["workspace"] = *client_capabilities.workspace;
        if(client_capabilities.textDocument.has_value())
            object["textDocument"] = *client_capabilities.textDocument;
        if(client_capabilities.notebookDocument.has_value())
            object["notebookDocument"] = *client_capabilities.notebookDocument;
        if(client_capabilities.window.has_value())
            object["window"] = *client_capabilities.window;
        if(client_capabilities.general.has_value())
            object["general"] = *client_capabilities.general;
        if(client_capabilities.experimental.has_value())
            object["experimental"] = *client_capabilities.experimental;
    }
}

#endif