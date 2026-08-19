// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/Diagnostic.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"severity\":1,\"code\":\"67\",\"codeDescription\":{\"href\":\"meow.extension\"},\"source\":\"the source code\",\"message\":{\"kind\":\"plaintext\",\"value\":\"meow\"},\"tags\":[1,2],\"relatedInformation\":[{\"location\":{\"uri\":\"meow.extension\",\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}}},\"message\":\"meow nya\"}],\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::Diagnostic request;
    Eura::from_json(root, request);
    if(request.range.start.line not_eq 0u or request.range.start.character not_eq 0u or request.
    range.end.line not_eq 42u or request.range.end.character not_eq 67u or not request.severity.
    has_value() or *request.severity not_eq Eura::DiagnosticSeverity::Error or not request.code.
    has_value() or not std::holds_alternative<std::string>(*request.code) or std::get<std::string>(
    *request.code) not_eq "67" or not request.codeDescription.has_value() or request.
    codeDescription->href not_eq "meow.extension" or not request.source.has_value() or *request.
    source not_eq "the source code" or not std::holds_alternative<Eura::MarkupContent>(request.
    message))
        return false;
    const Eura::MarkupContent& markup_content = std::get<Eura::MarkupContent>(request.message);
    if(markup_content.kind not_eq Eura::PlainText or markup_content.value not_eq "meow" or not
    request.tags.has_value() or request.tags->size() not_eq 2uz or static_cast<Eura::DiagnosticTag>
    ((*request.tags)[0uz]) not_eq Eura::DiagnosticTag::Unnecessary or static_cast<Eura::
    DiagnosticTag>((*request.tags)[1uz]) not_eq Eura::DiagnosticTag::Deprecated or not request.
    relatedInformation.has_value() or request.relatedInformation->size() not_eq 1uz)
        return false;
    const Eura::DiagnosticRelatedInformation& diagnostic_related_information = (*request.
    relatedInformation)[0uz];
    if(diagnostic_related_information.location.uri not_eq "meow.extension" or
    diagnostic_related_information.location.range.start.line not_eq 0u or
    diagnostic_related_information.location.range.start.character not_eq 0u or
    diagnostic_related_information.location.range.end.line not_eq 42u or
    diagnostic_related_information.location.range.end.character not_eq 67u or
    diagnostic_related_information.message not_eq "meow nya" or not request.data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.data, message);
    if(message.jsonrpc not_eq "2.0")
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