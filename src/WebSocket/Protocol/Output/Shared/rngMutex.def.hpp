template <typename Output>
std::mutex &
T <Output>::rngMutex ()
{
	return static_cast <Output &> (* this) . m_rng_mutex;
}
