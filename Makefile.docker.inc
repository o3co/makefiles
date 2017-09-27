AWS_REGION   ?= ap-northeast-1
AWS_PROFILE  ?= default
DOCKER_LOGIN ?= none
IMAGE_PATH   := $(if ${REPOS}, ${REPOS}/${IMAGE}, ${IMAGE})
VERSIONS     ?= latest

.PHONY: docker-build
docker-build: docker-build-versions

.PHONY: docker-build-version
docker-build-versions: $(addprefix docker-build_, $(VERSIONS))

.PHONY: docker-login
docker-login: docker-login-$(DOCKER_LOGIN)

.PHONY: docker-login-none
docker-login-none:

.PHONY: docker-login-ecr
docker-login-ecr:
	eval $$(aws ecr get-login --region=$${AWS_REGION} --profile=$${AWS_PROFILE} --no-include-email)

.PHONY: docker-push
docker-push: docker-login docker-push-versions

.PHONY: docker-push-versions
docker-push-versions: docker-login $(addprefix docker-push_, $(VERSIONS))

define docker-build_template
docker-build_$(1):
	docker build . -t ${IMAGE_PATH}:$1
docker-push_$(1):
	@echo docker push ${IMAGE_PATH}:$1
endef

$(foreach ver,$(VERSIONS),$(eval $(call docker-build_template,$(ver))))

