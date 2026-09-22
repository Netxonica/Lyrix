// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_token_types
#define lyrix_header_guard_eura_semantic_token_types
#include <string>

namespace Eura
{
    using SemanticTokenTypes = std::string;

    inline const SemanticTokenTypes Namespace = "namespace", Type = "type", Class = "class", Enum =
    "enum", Interface = "interface", Struct = "struct", TypeParameter = "typeParameter", Parameter
    = "parameter", Variable = "variable", Property = "property", EnumMember = "enumMember", Event =
    "event", Function = "function", Method = "method", Macro = "macro", Keyword = "keyword",
    Modifier = "modifier", Comment = "comment", String = "string", Number = "number", Regexp =
    "regexp", Operator = "operator", Decorator = "decorator", Label = "label";
}

#endif
#endif