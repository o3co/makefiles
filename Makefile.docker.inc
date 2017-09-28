#################
# RESTRICTION:
#   Please configure following vars before include.
#
##
AWS_REGION       ?= ap-northeast-1
AWS_PROFILE      ?= default
DOCKER_LOGIN     ?= none
DOCKER_VERSIONS  ?= latest
#DOCKER_REPOS := <SET YOUR REPOSITORY> 
#DOCKER_IMAGE := <SET DOCKER IMAGE>
DOCKER_IMAGE_PATH = $(if ${DOCKER_REPOS},$(strip $(DOCKER_REPOS))/$(strip $(DOCKER_IMAGE)),$(strip $(DOCKER_IMAGE)))

.PHONY: docker-info
docker-info: 
	@echo "IMAGE:     ${DOCKER_IMAGE_PATH}"
	@echo "VERSIONS:  ${DOCKER_VERSIONS}"
	@echo

.PHONY: docker-build
docker-build: docker-build-versions

.PHONY: docker-build-versions
docker-build-versions:
	$(MAKE) $(foreach ver, $(DOCKER_VERSIONS), docker-build-version_$(ver))

.PHONY: docker-push-versions
docker-push-versions:
	$(MAKE) $(foreach ver, $(DOCKER_VERSIONS), docker-push-version_$(ver))

.PHONY: docker-login
docker-login: docker-login-$(DOCKER_LOGIN)

.PHONY: docker-login-none
docker-login-none:

.PHONY: docker-login-ecr
docker-login-ecr:
	eval $$(aws ecr get-login --region=$${AWS_REGION} --profile=$${AWS_PROFILE} --no-include-email)

.PHONY: docker-push
docker-push: docker-login docker-push-versions

docker-build-version_%:
	docker build . -t ${DOCKER_IMAGE_PATH}:$*

docker-push-version_%: 
	docker push ${DOCKER_IMAGE_PATH}:$*

.PHONY: docker-ifconfig
docker-ifconfig:
	sudo ifconfig lo0 alias 10.200.10.1/24
