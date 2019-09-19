template <typename Cancellable>
T <Cancellable> &
T <Cancellable>::operator = (T && other)
{
	this -> Base::T::operator = (static_cast <Base::T &&> (other));
	this -> m_cancellable = other . m_cancellable;
	this -> m_thread = std::move (other . m_thread);
}
