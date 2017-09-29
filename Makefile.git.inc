
.PHONY: git-no-dirty
git-no-dirty:
	$(if $(shell git status --porcelain), $(error "GIT is still dirty. Please clean before call make."), @true)


