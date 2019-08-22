template <typename Request, typename Response, typename Details>
const Details &
T <Request, Response, Details>::details () const
{
	return this -> m_details;
}

template <typename Request, typename Response, typename Details>
Details &
T <Request, Response, Details>::details ()
{
	return this -> m_details;
}
