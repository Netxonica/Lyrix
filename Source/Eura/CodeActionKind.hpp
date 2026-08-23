// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_kind
#define lyrix_header_guard_eura_code_action_kind
#include <string>

namespace Eura
{
    using CodeActionKind = std::string;

    inline const CodeActionKind Empty = "", QuickFix = "quickfix", Refactor = "refactor",
    RefactorExtract = "refactor.extract", RefactorInline = "refactor.inline", RefactorMove =
    "refactor.move", RefactorRewrite = "refactor.rewrite", Source = "source", SourceOrganizeImports
    = "source.organizeImports", SourceFixAll = "source.fixAll", Notebook = "notebook";
}

#endif
#endif