template <typename UpgradeTarget, typename ... UpgradeArguments>
struct T
{
	using Target = UpgradeTarget;
	using Arguments = std::tuple <UpgradeArguments ...>;
};
