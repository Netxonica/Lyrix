// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DiagnosticOptions& diagnostic_options) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(diagnostic_options));
        if(object.contains("identifier"))
            diagnostic_options.identifier = object.at("identifier").get<std::string>();
        diagnostic_options.interFileDependencies = object.at("interFileDependencies").get<bool>();
        diagnostic_options.workspaceDiagnostics = object.at("workspaceDiagnostics").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DiagnosticOptions& diagnostic_options) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(diagnostic_options));
        if(diagnostic_options.identifier.has_value())
            object["identifier"] = *diagnostic_options.identifier;
        object["interFileDependencies"] = diagnostic_options.interFileDependencies;
        object["workspaceDiagnostics"] = diagnostic_options.workspaceDiagnostics;
    }
}

#endif