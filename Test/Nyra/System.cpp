// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/System.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    return Nyra::Stringify(Nyra::System::Darwin) == "darwin" and Nyra::Stringify(Nyra::System::
    Linux) == "linux" and Nyra::Stringify(Nyra::System::Windows) == "windows";
}

int main()
{
    return not lyrix_test();
}

#endif