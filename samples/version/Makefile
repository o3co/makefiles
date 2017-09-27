dump:
	echo ${VERSION}

.PHONY: init
init:  version-init

.PHONY: release
release:  version-increment version-dump

include ../../Makefile.version.inc

