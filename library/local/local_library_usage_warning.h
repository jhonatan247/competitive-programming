#pragma once

#ifdef LOCAL_BUILD
    #include <cstdio>
    namespace { struct _banner { _banner() {
        std::fputs(
            "\n\033[1;31m╔══════════════════════════════════════════════════════════════╗\n"
            "║     LOCAL LIBRARY IN USE — DO NOT SUBMIT — RUN F4 FIRST      ║\n"
            "╚══════════════════════════════════════════════════════════════╝\033[0m\n",
            stderr);
    } } _banner_instance;}
#endif
