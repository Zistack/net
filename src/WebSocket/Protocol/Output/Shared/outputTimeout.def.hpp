template <typename Output>
std::chrono::milliseconds
T <Output>::outputTimeout () const
{
	return static_cast <Output &> (* this) . m_output_timeout;
}
