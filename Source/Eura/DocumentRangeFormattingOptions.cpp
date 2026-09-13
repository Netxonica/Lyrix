// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentRangeFormattingOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentRangeFormattingOptions&
    document_range_formatting_options) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(document_range_formatting_options))
        ;
        if(object.contains("rangesSupport"))
            document_range_formatting_options.rangesSupport = object.at("rangesSupport").get<bool>(
            );
    }

    auto to_json(nlohmann::json& object, const DocumentRangeFormattingOptions&
    document_range_formatting_options) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(
        document_range_formatting_options));
        if(document_range_formatting_options.rangesSupport.has_value())
            object["rangesSupport"] = *document_range_formatting_options.rangesSupport;
    }
}

#endif