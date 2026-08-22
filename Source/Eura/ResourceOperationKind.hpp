// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_resource_operation_kind
#define lyrix_header_guard_eura_resource_operation_kind
#include <string>

namespace Eura
{
    using ResourceOperationKind = std::string;

    inline const ResourceOperationKind Create = "create", Rename = "rename", Delete = "delete";
}

#endif
#endif