# IF VERSION file exists, then load version from it. Otherwise use var VERSION or arg
define version-init
$(eval VERSION       ?= $(if $(1), echo $(1), echo "0.1.0"));
$(eval VERSION       := $(shell if [ -a VERSION ]; then cat VERSION; else ${VERSION}; fi))
$(eval VERSION_MINOR := $(shell echo ${VERSION} | ( IFS=".$${IFS}"; read A B C && echo $$A.$$B)))
$(eval VERSION_MAJOR := $(shell echo ${VERSION} | ( IFS=".$${IFS}"; read A B C && echo $$A))) 
endef

# VERSION FILE
VERSION:
	@echo ${VERSION} 

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
