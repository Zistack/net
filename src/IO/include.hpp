#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <poll.h>
#include <sys/eventfd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <exception>
#include <functional>
#include <string>

#include <Failure.hpp>

#undef EOF
