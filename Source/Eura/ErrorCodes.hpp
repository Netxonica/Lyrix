// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_error_codes
#define lyrix_header_guard_eura_error_codes
#include "Eura/Integer.hpp"

namespace Eura
{
    enum class [[nodiscard]] ErrorCodes : Json::Integer
    {
        ParseError = -32700,
        InvalidRequest = -32600,
        MethodNotFound = -32601,
        InvalidParams = -32602,
        InternalError = -32603,
        jsonrpcReservedErrorRangeStart = -32099,
        jsonrpcReservedErrorRangeEnd = -32000,
        lspReservedErrorRangeStart = -32899,
        RequestFailed = -32803,
        ServerCancelled = -32802,
        ContentModified = -32801,
        RequestCancelled = -32800,
        lspReservedErrorRangeEnd = -32800
    };
}

#endif
#endif