// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_failure_handling_kind
#define lyrix_header_guard_eura_failure_handling_kind
#include <string>

namespace Eura
{
    using FailureHandlingKind = std::string;

    inline const FailureHandlingKind Abort = "abort", Transactional = "transactional",
    TextOnlyTransactional = "textOnlyTransactional", Undo = "undo";
}

#endif
#endif