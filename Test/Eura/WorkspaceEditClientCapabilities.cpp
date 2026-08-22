// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEditClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"documentChanges\":true,\"resourceOperations\":[\"meow\"],\"failureHandling\":\"abort\",\"normalizesLineEndings\":true,\"changeAnnotationSupport\":{\"groupsOnLabel\":true},\"metadataSupport\":true,\"snippetEditSupport\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceEditClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.documentChanges.has_value() or not *request.documentChanges or not request.
    resourceOperations.has_value() or request.resourceOperations->size() not_eq 1uz or (*request.
    resourceOperations)[0uz] not_eq "meow" or not request.failureHandling.has_value() or *request.
    failureHandling not_eq "abort" or not request.normalizesLineEndings.has_value() or not *request
    .normalizesLineEndings or not request.changeAnnotationSupport.has_value() or not request.
    changeAnnotationSupport->groupsOnLabel.has_value() or not *request.changeAnnotationSupport->
    groupsOnLabel or not request.metadataSupport.has_value() or not *request.metadataSupport or not
    request.snippetEditSupport.has_value() or not *request.snippetEditSupport)
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif