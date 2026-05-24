.PHONY: all app clean

all: app

app:
	@$(MAKE) -C app

clean:
	@rm code_patched.bin code.ips
	@$(MAKE) -C app clean
