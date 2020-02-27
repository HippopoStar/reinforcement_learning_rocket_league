#!/bin/bash

_ECHO=/bin/echo

_AWK=/usr/bin/awk
_PGREP=/usr/bin/pgrep
_PMAP=/usr/bin/pmap
_XARGS=/usr/bin/xargs

#GAME_NAME=RocketLeague
GAME_NAME=running_program

main() {
	local GAME_PID="$(${_PGREP} ${GAME_NAME})"
	if [ -z "${GAME_PID}" ]
	then
		${_ECHO} 'Unable to get process PID'
		exit 0
	fi

	local PMAP_HEAP_LINE="$(${_PMAP} -XX ${GAME_PID} | ${_AWK} 'NR < 3 || /\[heap\]$/ { print $0 }')"
	if [ -z "${PMAP_HEAP_LINE}" ]
	then
		${_ECHO} 'Unable to get heap usage infos'
		exit 0
	fi

	local ADRESS="$(${_ECHO} "${PMAP_HEAP_LINE}" | ${_AWK} '/\[heap\]$/ { print $1 }')"
	local SIZE="$(${_ECHO} "${PMAP_HEAP_LINE}" | ${_AWK} '/\[heap\]$/ { print $6 }')"

	if [ -z "${ADRESS}" ] || [ -z "${SIZE}" ]
	then
		${_ECHO} 'Unable to get memory adress and size'
		exit 0
	fi

	${_ECHO} "${PMAP_HEAP_LINE}"
	${_ECHO} "PID: ${GAME_PID}"
	${_ECHO} "Adress: ${ADRESS}"
	${_ECHO} "Size: ${SIZE}"
}

main

