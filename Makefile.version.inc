VERSION ?= $(shell if [ -a VERSION ]; then cat VERSION; else echo 0.1.0; fi)

.PHONY: version-init
version-init: VERSION

# VERSION FILE
VERSION:
	@echo ${VERSION} > VERSION

.PHONY: version-dump
version-dump:
	@echo ${VERSION} > VERSION

.PHONY: version-increment
version-increment:
	$(eval VERSION  := $(shell echo ${VERSION} | ( IFS=".$${IFS}"; read A B C && echo $$A.$$B.$$((C + 1)))))

.PHONY: version-increment-minor
version-increment-minor:
	$(eval VERSION  := $(shell echo ${VERSION} | ( IFS=".$${IFS}"; read A B C && echo $$A.$$((B + 1)).0)))

.PHONY: version-increment-major
version-increment-major:
	$(eval VERSION  := $(shell echo ${VERSION} | ( IFS=".$${IFS}"; read A B C && echo $$((A + 1)).0.0)))
