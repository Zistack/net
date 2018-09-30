T::T (std::function<void(void)> setCallback,
    std::function<void(void)> clearCallback) :
    state (false),
    locked (false),
    setCallback (setCallback),
    clearCallback (clearCallback)
{
}
