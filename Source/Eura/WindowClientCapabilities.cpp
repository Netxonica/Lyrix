// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WindowClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WindowClientCapabilities&
    window_client_capabilities) noexcept -> void
    {
        if(object.contains("workDoneProgress"))
            window_client_capabilities.workDoneProgress = object.at("workDoneProgress").get<bool>()
            ;
        if(object.contains("showMessage"))
            window_client_capabilities.showMessage = object.at("showMessage").get<
            ShowMessageRequestClientCapabilities>();
        if(object.contains("showDocument"))
            window_client_capabilities.showDocument = object.at("showDocument").get<
            ShowDocumentClientCapabilities>();
    }

    auto to_json(nlohmann::json& object, const WindowClientCapabilities& window_client_capabilities
    ) noexcept -> void
    {
        if(window_client_capabilities.workDoneProgress.has_value())
            object["workDoneProgress"] = *window_client_capabilities.workDoneProgress;
        if(window_client_capabilities.showMessage.has_value())
            object["showMessage"] = *window_client_capabilities.showMessage;
        if(window_client_capabilities.showDocument.has_value())
            object["showDocument"] = *window_client_capabilities.showDocument;
    }
}

#endif