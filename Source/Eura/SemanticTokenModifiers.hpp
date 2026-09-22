// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_semantic_token_modifiers
#define lyrix_header_guard_eura_semantic_token_modifiers
#include <string>

namespace Eura
{
    using SemanticTokenModifiers = std::string;

    inline const SemanticTokenModifiers Declaration = "declaration", Definition = "definition",
    Readonly = "readonly", Static = "static", Deprecated = "deprecated", Abstract = "abstract",
    Async = "async", Modification = "modification", Documentation = "documentation", DefaultLibrary
    = "defaultLibrary";
}

#endif
#endif