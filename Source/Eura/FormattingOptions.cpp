// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FormattingOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FormattingOptions& formatting_options) noexcept ->
    void
    {
        formatting_options.tabSize = object.at("tabSize").get<std::uint32_t>();
        formatting_options.insertSpaces = object.at("insertSpaces").get<bool>();
        if(object.contains("trimTrailingWhitespace"))
            formatting_options.trimTrailingWhitespace = object.at("trimTrailingWhitespace").get<
            bool>();
        if(object.contains("insertFinalNewline"))
            formatting_options.insertFinalNewline = object.at("insertFinalNewline").get<bool>();
        if(object.contains("trimFinalNewlines"))
            formatting_options.trimFinalNewlines = object.at("trimFinalNewlines").get<bool>();
        for(const auto& [key, value] : object.items())
            if(key not_eq "tabSize" and key not_eq "insertSpaces" and key not_eq
            "trimTrailingWhitespace" and key not_eq "insertFinalNewline" and key not_eq
            "trimFinalNewlines")
            {
                if(value.is_boolean())
                    formatting_options.optional.emplace(key, value.get<bool>());
                else if(value.is_number_integer())
                    formatting_options.optional.emplace(key, value.get<std::int32_t>());
                else
                    formatting_options.optional.emplace(key, value.get<std::string>());
            }
    }

    auto to_json(nlohmann::json& object, const FormattingOptions& formatting_options) noexcept ->
    void
    {
        object["tabSize"] = formatting_options.tabSize;
        object["insertSpaces"] = formatting_options.insertSpaces;
        if(formatting_options.trimTrailingWhitespace.has_value())
            object["trimTrailingWhitespace"] = *formatting_options.trimTrailingWhitespace;
        if(formatting_options.insertFinalNewline.has_value())
            object["insertFinalNewline"] = *formatting_options.insertFinalNewline;
        if(formatting_options.trimFinalNewlines.has_value())
            object["trimFinalNewlines"] = *formatting_options.trimFinalNewlines;
        for(const auto& [key, value] : formatting_options.optional)
            std::visit([&object, &key](auto&& value)
            {
                object[key] = value;
            }, value);
    }
}

#endif