// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentRangesFormattingParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentRangesFormattingParams&
    document_ranges_formatting_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_ranges_formatting_params));
        document_ranges_formatting_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        const nlohmann::json& ranges = object.at("ranges");
        for(const nlohmann::json& range : ranges)
            document_ranges_formatting_params.ranges.emplace_back(range.get<Range>());
        document_ranges_formatting_params.options = object.at("options").get<FormattingOptions>();
    }

    auto to_json(nlohmann::json& object, const DocumentRangesFormattingParams&
    document_ranges_formatting_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(
        document_ranges_formatting_params));
        object["textDocument"] = document_ranges_formatting_params.textDocument;
        nlohmann::json ranges = nlohmann::json::array();
        for(const Range& range : document_ranges_formatting_params.ranges)
            ranges.emplace_back(range);
        object["ranges"] = ranges;
        object["options"] = document_ranges_formatting_params.options;
    }
}

#endif