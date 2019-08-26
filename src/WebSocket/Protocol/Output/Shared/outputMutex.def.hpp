template <typename Output>
std::mutex &
T <Output>::outputMutex ()
{
	return static_cast <Output &> (* this) . m_output_mutex;
}
