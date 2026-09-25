// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentDiagnosticReportPartialResult.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"relatedDocuments\":{\"meow.extension\":{\"kind\":\"full\",\"resultId\":\"meow\",\"items\":[]},\"nya.extension\":{\"kind\":\"unchanged\",\"resultId\":\"meow\"}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::DocumentDiagnosticReportPartialResult request;
    Eura::from_json(root, request);
    if(request.relatedDocuments.size() not_eq 2uz)
        return false;
    for(const auto& [uri, document] : request.relatedDocuments)
    {
        if(uri == "meow.extension")
        {
            if(not std::holds_alternative<Eura::FullDocumentDiagnosticReport>(document))
                return false;
            const Eura::FullDocumentDiagnosticReport& full = std::get<Eura::
            FullDocumentDiagnosticReport>(document);
            if(full.kind not_eq Eura::Full or not full.resultId.has_value() or *full.resultId
            not_eq "meow" or not full.items.empty())
                return false;
        }
        else if(uri == "nya.extension")
        {
            if(not std::holds_alternative<Eura::UnchangedDocumentDiagnosticReport>(document))
                return false;
            const Eura::UnchangedDocumentDiagnosticReport& unchanged = std::get<Eura::
            UnchangedDocumentDiagnosticReport>(document);
            if(unchanged.kind not_eq Eura::Unchanged or unchanged.resultId not_eq "meow")
                return false;
        }
        else
            return false;
    }
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif