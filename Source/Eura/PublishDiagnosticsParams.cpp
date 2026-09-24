// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/PublishDiagnosticsParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, PublishDiagnosticsParams&
    publish_diagnostics_params) noexcept -> void
    {
        publish_diagnostics_params.uri = object.at("uri").get<DocumentUri>();
        if(object.contains("version"))
            publish_diagnostics_params.version = object.at("version").get<std::int32_t>();
        const nlohmann::json& diagnostics = object.at("diagnostics");
        for(const nlohmann::json& diagnostic : diagnostics)
            publish_diagnostics_params.diagnostics.emplace_back(diagnostic.get<Diagnostic>());
    }

    auto to_json(nlohmann::json& object, const PublishDiagnosticsParams& publish_diagnostics_params
    ) noexcept -> void
    {
        object["uri"] = publish_diagnostics_params.uri;
        if(publish_diagnostics_params.version.has_value())
            object["version"] = *publish_diagnostics_params.version;
        nlohmann::json diagnostics = nlohmann::json::array();
        for(const Diagnostic& diagnostic : publish_diagnostics_params.diagnostics)
            diagnostics.emplace_back(diagnostic);
        object["diagnostics"] = diagnostics;
    }
}

#endif