// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRangeClientCapabilities.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"dynamicRegistration\":true,\"rangeLimit\":67,\"lineFoldingOnly\":true,\"foldingRangeKind\":{\"valueSet\":[\"comment\"]},\"foldingRange\":{\"collapsedText\":true}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::FoldingRangeClientCapabilities request;
    Eura::from_json(root, request);
    if(not request.dynamicRegistration.has_value() or not *request.dynamicRegistration or not
    request.rangeLimit.has_value() or *request.rangeLimit not_eq 67u or not request.lineFoldingOnly
    .has_value() or not *request.lineFoldingOnly or not request.foldingRangeKind.has_value() or not
    request.foldingRangeKind->valueSet.has_value() or request.foldingRangeKind->valueSet->size()
    not_eq 1uz or (*request.foldingRangeKind->valueSet)[0uz] not_eq Eura::Comment or not request.
    foldingRange.has_value() or not request.foldingRange->collapsedText.has_value() or not *request
    .foldingRange->collapsedText)
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