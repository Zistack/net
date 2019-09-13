template <typename Output>
std::chrono::nanoseconds
T <Output>::outputTimeout () const
{
	return static_cast <Output &> (* this) . m_output_timeout;
}
