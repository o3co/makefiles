REPOS         := 
IMAGE         := sample.docker
DOCKER_LOGIN  := ecr
AWS_REGION    := ap-northeast-1
AWS_PROFILE   := o3co 
VERSIONS      := latest 1.0 1.0.0

.PHONY: clean
clean: npm-clean
	rm -rf dist

.PHONY: build
build: npm-build docker-build

.PHONY: release
release: docker-release

include ../../Makefile.npm.inc
include ../../Makefile.docker.inc

