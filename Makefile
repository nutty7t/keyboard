.DEFAULT_GOAL = compiled.hex

keymap_dir = qmk_firmware/keyboards/keebio/iris/keymaps/nutty7t
keymap_files = $(addprefix $(keymap_dir)/,keymap.c config.h rules.mk)
hex_file = qmk_firmware/keebio_iris_rev3_nutty7t.hex

qmk_firmware:
	git clone https://github.com/qmk/qmk_firmware

$(keymap_dir): qmk_firmware
	@mkdir -p $@

$(keymap_files): $(keymap_dir)
	@if [ ! -f $@ ]; then ln -s $(shell pwd)/$(notdir $@) $@; fi;

$(hex_file): $(keymap_files)
	make -C qmk_firmware keebio/iris/rev3:nutty7t

compiled.hex: $(hex_file)
	@cp $(hex_file) $@

clean:
	@rm -f compiled.hex
	@rm -rf qmk_firmware/

.PHONY: clean
