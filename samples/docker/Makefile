REPOS         := 
IMAGE         := sample.docker
DOCKER_LOGIN  := ecr
AWS_REGION    := ap-northeast-1
AWS_PROFILE   := o3co 
VERSIONS      := latest 1.0 1.0.0

.PHONY: build
build: docker-build

.PHONY: release
release: docker-release

include ../../Makefile.docker.inc
