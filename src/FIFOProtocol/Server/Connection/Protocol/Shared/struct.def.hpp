template <typename Protocol, typename Response, typename Details>
struct T
{
	const Output::T <Protocol, Response, Details> &
	output () const;

	Output::T <Protocol, Response, Details> &
	output ();

	const Details &
	details () const;

	Details &
	details ();
};
