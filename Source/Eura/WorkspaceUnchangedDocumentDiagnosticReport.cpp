// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceUnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceUnchangedDocumentDiagnosticReport&
    workspace_unchanged_document_diagnostic_report) noexcept -> void
    {
        from_json(object, static_cast<UnchangedDocumentDiagnosticReport&>(
        workspace_unchanged_document_diagnostic_report));
        workspace_unchanged_document_diagnostic_report.uri = object.at("uri").get<DocumentUri>();
        const nlohmann::json& version = object.at("version");
        if(version.is_number_integer())
            workspace_unchanged_document_diagnostic_report.version = version.get<std::int32_t>();
        else
            workspace_unchanged_document_diagnostic_report.version = nullptr;
    }

    auto to_json(nlohmann::json& object, const WorkspaceUnchangedDocumentDiagnosticReport&
    workspace_unchanged_document_diagnostic_report) noexcept -> void
    {
        to_json(object, static_cast<const UnchangedDocumentDiagnosticReport&>(
        workspace_unchanged_document_diagnostic_report));
        object["uri"] = workspace_unchanged_document_diagnostic_report.uri;
        std::visit([&object](auto&& version)
        {
            object["version"] = version;
        }, workspace_unchanged_document_diagnostic_report.version);
    }
}

#endif