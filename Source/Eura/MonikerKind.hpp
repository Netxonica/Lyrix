// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_moniker_kind
#define lyrix_header_guard_eura_moniker_kind
#include <string>

namespace Eura
{
    using MonikerKind = std::string;

    inline const MonikerKind Import = "import", Export = "export", Local = "local";
}

#endif
#endif