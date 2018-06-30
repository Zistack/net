void
close ()
{
	std::unique_lock lock (mutex);

	closed = true;

	condition_variable . notify_one ();
}
