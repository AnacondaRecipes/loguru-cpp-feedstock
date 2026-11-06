#include "loguru_example.hpp"

#include <cstdio>
#include <cstring>

static_assert(LOGURU_VERSION_MAJOR == 2 && LOGURU_VERSION_MINOR == 2 &&
              LOGURU_VERSION_PATCH == 0, "Expected upstream loguru 2.2.0");

static int messages_seen = 0;

static void verify_message(void*, const loguru::Message& message)
{
    if (std::strcmp(message.message, "Hello from main.cpp!") == 0 ||
        std::strcmp(message.message, "We ended up in 1985!") == 0) {
        ++messages_seen;
    }
}

int main(int argc, char* argv[])
{
    loguru::init(argc, argv);
    loguru::add_callback("verify", verify_message, nullptr, loguru::Verbosity_MAX);
    LOG_F(INFO, "Hello from main.cpp!");
    complex_calculation();
    LOG_F(INFO, "main function about to end!");
    loguru::remove_callback("verify");
    loguru::shutdown();
    if (messages_seen != 2) {
        std::fprintf(stderr, "expected 2 messages, saw %d\n", messages_seen);
        return 1;
    }
    return 0;
}
