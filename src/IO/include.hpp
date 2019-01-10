#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/eventfd.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <exception>
#include <functional>
#include <future>
#include <string>

#include <Failure.hpp>
#include <Thread.hpp>
