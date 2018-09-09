T::T (uint64_t nanoseconds, std::function<void(void)> callback) :
    callback (callback)
{
	const std::string message_prefix = "Thread::Timeout::T::T\n";

	struct sigevent event_spec = {.sigev_notify = SIGEV_THREAD,
	    .sigev_value = {.sival_ptr = this},
	    .sigev_notify_function = T::fire,
	    .sigev_notify_attributes = NULL};

	if (timer_create (CLOCK_REALTIME, &event_spec, &this->timer_id) == -1)
	{
		throw Failure::Error::T (
		    message_prefix + "timer_create: " + strerror (errno) + "\n");
	}

	struct itimerspec timer_spec = {.it_interval = {.tv_sec = 0, .tv_nsec = 0},
	    .it_value = {.tv_sec = (time_t) nanoseconds / 1000000000,
	        .tv_nsec = (long) nanoseconds % 1000000000}};

	if (timer_settime (this->timer_id, 0, &timer_spec, NULL) == -1)
	{
		timer_delete (this->timer_id);

		throw Failure::Error::T (
		    message_prefix + "timer_settime: " + strerror (errno) + "\n");
	}
}
