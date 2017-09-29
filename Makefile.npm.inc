# See https://github.com/o3co/makefiles

.PHONY: npm-build
npm-build: npm-install
	npm run build

.PHONY: npm-reinstall
npm-reinstall:  npm-uninstall npm-install

.PHONY: npm-uninstall
npm-uninstall:
	rm -rf node_modules

.PHONY: npm-install
npm-install:  node_modules

node_modules: node_modules/.installed

node_modules/.installed:
	npm install
	touch node_modules/.installed
