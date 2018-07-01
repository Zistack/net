#!/bin/bash

special='
type.hpp
struct.hpp
main.hpp
include.hpp
'

function list-source-files
{
	find . -mindepth 1 -maxdepth 1 -type f -regex '\./[^.].*\.hpp' |
		sed -e 's~\./~~' |
		grep -vxF "${special}"
}

function list-functions
{
	local source_files="$(list-source-files)"

	if [ -n "${source_files}" ]
	then
		grep -L '^const T' ${source_files}
	fi
}

function list-modules
{
	find . -mindepth 1 -maxdepth 1 -type d -regex '^\./[^.].*' | sed -e 's~\./~~'
}

function list-constants
{
	local source_files="$(list-source-files)"

	if [ -n "${source_files}" ]
	then
		grep -l '^const T' ${source_files}
	fi
}

function process-module
{
	local module="${1}"

	for dependency in $(cat "${module}"/dependencies 2>/dev/null)
	do
		conditionally-process-module "${dependency}"
	done

	local new_path="${path}"'/'"${module}"

	namespace-do "${module}" "${new_path}" "${command}"
}

function conditionally-process-module
{
	local module="${1}"

	if ! grep -qx "${module}" <<< "${processed_modules}"
	then
		processed_modules="${processed_modules}${module}"$'\n'

		process-module "${module}"
	fi
}

function process-modules
{
	local processed_modules=""

	for new_module in $(list-modules)
	do
		conditionally-process-module "${new_module}"
	done
}

function namespace-do
{
	local module="${1}"
	local path="${2}"
	local command="${3}"

	echo 'namespace '"${module}"
	echo '{'

	cd "${module}"

	(process-modules; "${command}" "${path}") | sed -e 's~^~	~'

	cd ..

	echo '}'
}
function is-struct
{
	test -e struct.hpp
}

function is-typedef
{
	test -e type.hpp
}
function get-function-declarations
{
	local file="${1}"

	get-function-declarations-state-machine < "${file}" | clang-format
}

function get-function-declarations-state-machine
{
	local state="waiting"

	while IFS='' read -r line
	do
		if [ "${state}" = "waiting" ] && [ -n "${line}" ]
		then
			echo "${line}"
			state="in declaration"
		elif [ "${state}" = "in declaration" ]
		then
			if grep -q '^{$' <<< "${line}"
			then
				echo ';'
				state="in definition"
			else
				echo "${line}"
			fi
		elif [ "${state}" = "in definition" ] && grep -q '^}$' <<< "${line}"
		then
			state="waiting"
		fi
	done
}

function get-struct-declaration
{
	local file="${1}"

	get-struct-declaration-state-machine < "${file}" | clang-format
}

function get-struct-declaration-state-machine
{
	local state="waiting"

	while IFS='' read -r line
	do
		if [ "${state}" = "waiting" ] && [ -n "${line}" ]
		then
			state="in declaration"
		fi

		if [ "${state}" = "in declaration" ]
		then
			if grep -q '^struct T' <<< "${line}"
			then
				echo 'struct T;'
				break
			else
				echo "${line}"
			fi
		fi
	done
}

function declare-struct
{
	local path="${1}"

	if is-struct
	then
		get-struct-declaration 'struct.hpp'
	fi
}

function include-typedef-type
{
	local path="${1}"

	if is-typedef
	then
		echo '#include "'"${path}"'/type.hpp"'
	fi
}

function include-struct-definition
{
	local path="${1}"

	if is-struct
	then
		echo '#include "'"${path}"'/struct.hpp"'
	fi
}

function include-constant-definitions
{
	local path="${1}"

	for constant in $(list-constants)
	do
		echo '#include "'"${path}"'/'"${constant}"'"'
	done
}

function declare-functions
{
	local path="${1}"

	if ! is-struct
	then
		for function in $(list-functions)
		do
			get-function-declarations "${function}"
		done
	fi
}

function include-function-definitions
{
	local path="${1}"

	for function in $(list-functions)
	do
		echo '#include "'"${path}"'/'"${function}"'"'
	done
}

srcdir="${1}"
module="${2}"

cd "${srcdir}"

echo '#pragma once'

echo ''

echo '#include "'"${module}"'/include.hpp"'

echo ''

namespace-do "${module}" "${module}" "declare-struct"

echo ''

namespace-do "${module}" "${module}" "include-typedef-type"

echo ''

namespace-do "${module}" "${module}" "include-struct-definition"

echo ''

namespace-do "${module}" "${module}" "include-constant-definitions"

echo ''

namespace-do "${module}" "${module}" "declare-functions"

echo ''

namespace-do "${module}" "${module}" "include-function-definitions"
