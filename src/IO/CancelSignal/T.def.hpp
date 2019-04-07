T::T () : cancelled (false)
{
}

T::T (T && other)
:	cancelled (other . cancelled . load ()), signal (std::move (other . signal))
{
	other . cancelled = false;
}