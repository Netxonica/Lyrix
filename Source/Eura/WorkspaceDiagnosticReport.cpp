// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceDiagnosticReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceDiagnosticReport&
    workspace_diagnostic_report) noexcept -> void
    {
        const nlohmann::json& items = object.at("items");
        for(const nlohmann::json& item : items)
        {
            if(item.at("kind").get<DocumentDiagnosticReportKind>() == Full)
                workspace_diagnostic_report.items.emplace_back(item.get<
                WorkspaceFullDocumentDiagnosticReport>());
            else
                workspace_diagnostic_report.items.emplace_back(item.get<
                WorkspaceUnchangedDocumentDiagnosticReport>());
        }
    }

    auto to_json(nlohmann::json& object, const WorkspaceDiagnosticReport&
    workspace_diagnostic_report) noexcept -> void
    {
        nlohmann::json items = nlohmann::json::array();
        for(const WorkspaceDocumentDiagnosticReport& item : workspace_diagnostic_report.items)
            std::visit([&items](auto&& item)
            {
                items.emplace_back(item);
            }, item);
        object["items"] = items;
    }
}

#endif